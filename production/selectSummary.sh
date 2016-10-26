#!/bin/bash

for channel in ch1 ch4
do
for what in uubar ddbar ssbar ccbar mixed charged signal
do
 logs=payload_${channel}_[0-9]*_${what}.log
 for log in $logs
 do 
   if [ -e ${log} ]
   then
     echo $log $(grep Processed $log  |tail -1) $(grep -H ^RootInput $log | tail -1)
   fi
 done
 #logs=payload_skim_[0-9]*_${what}.log
 #nfiles=$(ls payload_skim_${channel}_*_${what}.log | wc -l)
 nfiles=$(ls ${logs} | wc -l)
 #nfiles=$(ls payload_skim_*_${what}.log | wc -l)
 output=$(grep -H RootOutput ${logs} | awk '{sum+=$3; print sum}' |tail -1)
 
 input=$(grep -H ^RootInput ${logs} | awk '{sum+=$3; print sum}' |tail -1)
 # eff=$(echo "scale=5; $output*1./$input"| bc)
 # sigmaEff=$(echo "scale=10; sqrt($eff*(1.-$eff)/$input)" | bc)
 #echo -e ${what} "\t" input: $input output ${output} eff: $eff +- $sigmaEff

if [ -z "$input" ]
then
  input=1
fi
if [ -z "$output" ]
then
  output=1
fi

python << END
import math
eff=$output*1./$input

sigmaEff=math.sqrt(eff*(1.-eff)/$input)

print "\033[1;33;10m {0:10} ({1:4d}): IN: {2:0.2f}k OUT: {3:0.3f}k Eff: {4:.3}e-2 +/- {5:.2}e-2\033[0;17;10m".format("$what.$channel",$nfiles,$input/1.e3, $output/1.e3,eff*100.,sigmaEff*100.)

END
 
done

done
