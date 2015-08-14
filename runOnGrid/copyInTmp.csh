#!/bin/csh

#setenv EOSpath /store/group/phys_muon/hbrun/HLTtest/Spring15sample/50nsBis/$1
setenv EOSpath /store/group/phys_muon/hbrun/dataCommissioning/MCfor50nsWithTkMuonsBis/$1
               

#set list = `cmsLs $EOSpath | grep root | grep "07-08" | awk '{ print $5 }'`
set list = `cmsLs $EOSpath | grep root | awk '{ print $5 }'`
mkdir /tmp/hbrun/$1

foreach i ($list)
	echo $i
	set number = `echo $i | awk -F "/" '{ print $9 }' | awk -F "_" '{print $2}'`
	echo $number
	timeout 5 cmsStage $i /tmp/hbrun/$1/fichier_$number.root

end


