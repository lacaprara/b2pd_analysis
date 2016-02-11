#!/bin/bash

#for what in uubar ddbar ssbar ccbar mixed charged signal
for what in signal
do
for channel in ch1 ch2 ch4 ch5
do
 logs=payload_skim_${channel}_[0-9]*_${what}.log
 #logs=payload_skim_[0-9]*_${what}.log
 #nfiles=$(ls payload_skim_${channel}_*_${what}.log | wc -l)
 nfiles=$(ls ${logs} | wc -l)
 #nfiles=$(ls payload_skim_*_${what}.log | wc -l)
 output=$(grep -H RootOutput ${logs} | awk '{sum+=$3; print sum}' |tail -1)
 
 input=$(grep -H ^SkimFilter ${logs} | awk '{sum+=$3; print sum}' |tail -1)
 # eff=$(echo "scale=5; $output*1./$input"| bc)
 # sigmaEff=$(echo "scale=10; sqrt($eff*(1.-$eff)/$input)" | bc)
 #echo -e ${what} "\t" input: $input output ${output} eff: $eff +- $sigmaEff

python << END
import math
eff=$output*1./$input

sigmaEff=math.sqrt(eff*(1.-eff)/$input)

print "{0:10} ({1:4d}): IN: {2:0.2f}M OUT: {3:0.3f}M Eff: {4:.3}e-2 +/- {5:.2}e-2".format("$what.$channel",$nfiles,$input/1.e6, $output/1.e6,eff*100.,sigmaEff*100.)

END
 
done

done
