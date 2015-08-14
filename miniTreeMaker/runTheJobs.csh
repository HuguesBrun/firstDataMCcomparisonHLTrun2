#!/bin/csh

set list=`cat ../list_rate`

echo $list

foreach i ($list)
	echo $i
	root -b -q -l 'runTheTree.C("'$i'")'
        set name=`echo $i | sed s/"rate_"/""/g` 
	echo $name
	cp theOutFile.root theOutFile_$name.root
end

