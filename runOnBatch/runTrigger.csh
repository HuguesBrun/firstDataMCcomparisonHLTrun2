#!/bin/csh

#echo "fit jobs" | mail -s "lauching the job ${1}" hbrun@cern.ch
set LOCALDIR = `pwd`
setenv WORKINGDIR /afs/cern.ch/work/h/hbrun/CMSSW_7_4_6_runDATA/src/
setenv SCRAM_ARCH slc6_amd64_gcc491
#setenv CONF_FILE runRECO_$1.py
setenv LOCAL_PATH hugues/OnlineHLTanalyzer/python/runData/runTkMuonFullrunB
setenv OUTDIR /store/group/phys_muon/hbrun/dataCommissioning/dataAllRunBjsonNewCond
cd $WORKINGDIR
cmsenv
cd $LOCAL_PATH 
cp runOnlineHLT_data_${1}.py $LOCALDIR
cp theRunBjsonFile.json $LOCALDIR
cd $LOCALDIR
ls 
cmsRun runOnlineHLT_data_${1}.py

echo "bon ben c finin : on list le directory now ! " 
ls 
sleep 120
cmsStage  /tmp/hbrun/muonL2treeDATA_${1}.root $OUTDIR
