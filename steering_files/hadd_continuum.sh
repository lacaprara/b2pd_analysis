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
  case $what in
    'signal')
      fileList=${channelName}_gsim-BKGx0.list
      ;;
    *)
      fileList=BackgroundSkim_${what}_BGx1.list
      ;;
  esac
}

#for what in uubar ddbar ssbar ccbar
for what in ccbar

do
  echo "doing $what"
  #for channel in {1,2,4,5}
  for channel in 4 5
  do
    setChannelName $channel $what
    hadd -f ${channelName}_output_${what}.root payload_ch${channel}_*_${what}/*ot
    echo "done"
  done
  echo "All done"
done
