#!/bin/bash

for what in uubar ddbar ssbar ccbar mixed charged signal
do
 nfiles=$(ls payload_skim_*_${what}.log | wc -l)
 output=$(grep -H RootOutput payload_skim_*_${what}.log | awk '{sum+=$3; print sum}' |tail -1)
 input=$(grep -H ^SkimFilter payload_skim_*_${what}.log | awk '{sum+=$3; print sum}' |tail -1)
 eff=$(echo "scale=5; $output*1./$input"| bc)
 sigmaEff=$(echo "scale=10; sqrt($eff*(1.-$eff)/$input)" | bc)
 #echo -e ${what} "\t" input: $input output ${output} eff: $eff +- $sigmaEff

python << END
import math
eff=$output*1./$input

sigmaEff=math.sqrt(eff*(1.-eff)/$input)

print "{0:10} ({1:4d}): IN: {2:0.2f}M OUT: {3:0.3f}M Eff: {4:.3}e-2 +/- {5:.2}e-2".format("$what",$nfiles,$input/1.e6, $output/1.e6,eff*100.,sigmaEff*100.)

END
 

done
