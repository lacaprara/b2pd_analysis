#!/bin/bash

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
}

#for what in uubar ddbar ssbar ccbar
#for what in uubar ddbar ssbar ccbar mixed charged
for what in charged

do
  echo "doing $what"
  #for channel in {1,2,4,5}
  for channel in 4
  do
    setChannelName $channel $what
    hadd -f ${channelName}_output_${what}.root payload_ch${channel}_*_${what}/*ot
    echo "done"
  done
  echo "All done"
done
