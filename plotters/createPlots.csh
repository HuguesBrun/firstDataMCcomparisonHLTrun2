#!/bin/csh

set list=`cat list_rate`

foreach i ($list)
    echo $i
    root -b -q -l 'doPlots.C("'$i'")'
end
