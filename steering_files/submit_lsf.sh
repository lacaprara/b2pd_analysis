#!/bin/bash

nFilesPerJob=1

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
#BSUB -o job_${payloadName}.log
#BSUB -J job_${payloadName}.job

echo hostname
date

pwd

mkdir job_${payloadName}/
cd job_${payloadName}/
cp ../SelectEtaPrK0_ch1.py .
time basf2 SelectEtaPrK0_ch${channel}.py $numFiles $firstFile
mv ${channelName}_output_signal.root ${channelName}_output_signal_{$job}.root

date
cd ../
EOF
}

#for channel in {1,2,4,5}
for channel in 1
do
  job=0
  setChannelName $channel
  nFiles=$(wc -l ${channelName}_gsim-BKGx0.list | awk '{print $1}' )
  nFiles=3
  echo $nFiles
  for files in `seq 0 $nFilesPerJob $nFiles`
  do
      payload $job $channel $files $nFilesPerJob
      bsub < payload_${payloadName}.sh
      ((job++))
  done
done
