#!/bin/bash

nFilesPerJob=10

channelName=unknown
setChannelName() {
  ch=$1
  case $ch in
    [1]*)
      channelName=B0_etapr-eta-gg2pi_KS-pi+pi-
    ;;
    [2]*)
      channelName=B0_etapr-eta-gg2pi_KS-pi0pi0
    ;;
    [3]*)
    ;;
    [4]*)
      channelName=B0_etapr-eta-3pi2pi_KS-pi+pi-
    ;;
    [5]*)
      channelName=B0_etapr-eta-3pi2pi_KS-pi0pi0
    ;;
    [6]*)
    ;;
  esac
}

payload() {
  job=$1
  channel=$2
  firstFile=$3
  numFiles=$4
  payloadName=ch${channel}_${job}

cat > payload_${payloadName}.sh << EOF
#!/bin/sh
#BSUB -o payload_${payloadName}.log
#BSUB -J payload_${payloadName}.job
#BSUB -q s

hostname
date

pwd

mkdir payload_${payloadName}/
cd payload_${payloadName}/
cp ../SelectEtaPrK0_ch${channel}.py .
cp ../${channelName}_gsim-BKGx0.list .
time basf2 SelectEtaPrK0_ch${channel}.py $numFiles $firstFile
mv ${channelName}_output_signal.root ${channelName}_output_signal_${job}.root

date
cd ../
EOF
}

#for channel in {1,2,4,5}
for channel in {2,4,5}
do
  job=0
  setChannelName $channel
  nFiles=$(wc -l ${channelName}_gsim-BKGx0.list | awk '{print $1}' )
  echo echo "Submitting $(echo $nFiles*1./$nFilesPerJob| bc) jobs over $((nFiles)) files for channel $channel $channelName"
  for files in `seq 0 $nFilesPerJob $nFiles`
  do
      payload $job $channel $files $nFilesPerJob
      bsub < payload_${payloadName}.sh
      ((job++))
  done
  echo "done"
done
