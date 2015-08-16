#!/bin/csh

set list=`cat listRuns`
foreach number ($list)
	echo $number
	bsub -q 8nh runTrigger.csh $number
end


