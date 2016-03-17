#!/bin/bash

#for what in uubar ddbar ssbar ccbar mixed charged signal
for what in charged mixed ddbar ssbar uubar ccbar signal
do
for channel in ch1 ch4 
do
 logs=payload_${channel}_[0-9]*_${what}.log
 nfiles=$(ls ${logs} | wc -l)
 total_proc=0
 for log in $logs
 do
   over=$(grep -c "Total Number of Particles created in the DataStore" ${log})
   if [[ $over -ne 0 ]]
   then
     output=$(grep -H "^Total     " ${log} | awk '{sum+=$3; print sum}' |tail -1)
     total_proc=$((total_proc + output))
     echo $log DONE $output
   else
     processed=$(grep -H "Processed" ${log} |tail -1)
     echo $log RUNNING $processed
   fi
 done
 echo $what $channel TOTAL DONE $total_proc
done

done

