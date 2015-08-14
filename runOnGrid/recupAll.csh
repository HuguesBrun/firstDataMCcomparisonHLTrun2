#!/bin/csh


set list=`cat list_rate`

foreach i ($list)
	echo $i 
	source copyInTmp.csh $i
end

