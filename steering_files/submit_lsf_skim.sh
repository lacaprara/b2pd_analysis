#!/bin/bash

nFilesPerJobSignal=20
nFilesPerJobBackground=20
nFilesPerJobPeaking=5
nMaxFiles=99999999

#DOIT=false
DOIT=true
DoSignal=false
DoBackground=true
DoPeaking=true

what='signal'
# what='uubar'
# what='ddbar'
# what='ssbar'
# what='ccbar'
# what='mixed'
# what='charged'

channelName=unknown
setChannelName() {
  ch=$1
  what=$2
  case $ch in
    1)
      channelName=B0_etapr-eta-gg2pi_KS-pi+pi-
    ;;
    2)
      channelName=B0_etapr-eta-gg2pi_KS-pi0pi0
    ;;
    3)
    ;;
    4)
      channelName=B0_etapr-eta-3pi2pi_KS-pi+pi-
    ;;
    5)
      channelName=B0_etapr-eta-3pi2pi_KS-pi0pi0
    ;;
    6)
    ;;
  esac
  case $what in
    'signal')
      fileList=${channelName}_gsim-BKGx0.list
      ;;
    *)
      fileList=Background_${what}_BGx1.list
      ;;
  esac
}

payload() {
  job=$1
  channel=$2
  firstFile=$3
  numFiles=$4
  what=$5

  payloadName=skim_ch${channel}_${job}_${what}

  dataset=$what
  if [ $what = 'signal' ]; then dataset=${what}_ch${channel}; fi

cat > payload_${payloadName}.sh << EOF
#!/bin/sh
#BSUB -o payload_${payloadName}.log
#BSUB -J payload_${payloadName}.job
#BSUB -q l

hostname
date

pwd

mkdir payload_${payloadName}/
cd payload_${payloadName}/
cp ../SkimEtaPrK0.py .
cp ../${fileList} .
time basf2 SkimEtaPrK0.py $dataset $numFiles $firstFile
mv B0_etapr_eta2pi_KS_skim_${what}.root B0_etapr_eta2pi_KS_skim_${what}_${job}.root

date
cd ../
EOF
}

# SIGNAL
if $DoSignal ; then
what=signal
for channel in {1,4}
do
  job=0
  setChannelName $channel $what
  nFiles=$(wc -l ${fileList} | awk '{print $1}' )
  if [[ $nFiles -gt $nMaxFiles ]] ; then nFiles=$nMaxFiles; fi
  echo echo "SKIM: Submitting $(echo $nFiles*1./$nFilesPerJobSignal+1| bc) jobs over $((nFiles)) files for ${what} ${channel}"
  for firstFile in `seq 0 $nFilesPerJobSignal $(($nFiles-1))`
  do  
      payload $job $channel $firstFile $nFilesPerJobSignal $what
      $DOIT && bsub < payload_${payloadName}.sh
      ((job++))
  done
  echo "done"
done
echo "SIGNAL done"
fi



## BACKGROUND
if $DoBackground ; then
channel=14
for what in uubar ddbar  ssbar ccbar
#for what in ccbar
do
echo "doing $what"
  job=0
  setChannelName $channel $what
  nFiles=$(wc -l ${fileList} | awk '{print $1}' )
  if [[ $nFiles -gt $nMaxFiles ]] ; then nFiles=$nMaxFiles; fi
  echo echo "SKIM: Submitting $(echo $nFiles*1./$nFilesPerJobBackground+1| bc) jobs over $((nFiles)) files for ${what} ${channel}"
  for firstFile in `seq 0 $nFilesPerJobBackground $(($nFiles-1))`
  do  
      payload $job $channel $firstFile $nFilesPerJobBackground $what
      $DOIT &&  bsub < payload_${payloadName}.sh
      ((job++))
  done
  echo "done"
done
echo "BACKGROUND done"
fi


## PEAKING BACKGROUND
if $DoPeaking ; then
channel=14
for what in mixed charged
#for what in ccbar
do
echo "doing $what"
  job=0
  setChannelName $channel $what
  nFiles=$(wc -l ${fileList} | awk '{print $1}' )
  if [[ $nFiles -gt $nMaxFiles ]] ; then nFiles=$nMaxFiles; fi
  echo echo "SKIM: Submitting $(echo $nFiles*1./$nFilesPerJobPeaking+1| bc) jobs over $((nFiles)) files for ${what} ${channel}"
  for firstFile in `seq 0 $nFilesPerJobPeaking $(($nFiles-1))`
  do  
      payload $job $channel $firstFile $nFilesPerJobPeaking $what
      $DOIT &&  bsub < payload_${payloadName}.sh
      ((job++))
  done
  echo "done"
done
echo "PEAKING BACKGROUND done"
fi
