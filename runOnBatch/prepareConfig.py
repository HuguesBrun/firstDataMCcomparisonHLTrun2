import os
import sys
import optparse
import re
import commands
import das_client
import json


def putRunInShape(theRun):
    return theRun[:-3]+"/"+theRun[3:]
#ask directly to DAS the files corresponding the to run
def listFichier(theRun, theSample, dataTier,runNumberRAW):
    runNumber = putRunInShape(runNumberRAW)
    theQuery = "file dataset=/"+theSample+"*/"+theRun+"*/"+dataTier
    jsondict = das_client.get_data('https://cmsweb.cern.ch', theQuery, 0, 0, False)
    status = jsondict['status']
    if status != 'ok':
        print "DAS query status: %s"%(status)
    data = jsondict['data']
    theFileList = []
    for aRaw in data:
        recordStuff = aRaw['file']
        for aRecord in recordStuff:
            #                if ((len(re.split("251/244",aRecord['name']))>1) or (len(re.split("251/252",aRecord['name']))>1) or (len(re.split("251/562",aRecord['name']))>1) or (len(re.split("251/643",aRecord['name']))>1) or (len(re.split("251/638",aRecord['name']))>1) or (len(re.split("251/721",aRecord['name']))>1) or (len(re.split("251/718",aRecord['name']))>1)):
            if ((len(re.split(runNumber,aRecord['name']))>1)):
                theFileList.append(aRecord['name'])
                print "\""+aRecord['name']+"\","
    return theFileList

#thelistFile= listFichier("Run2015B","SingleMuon","RAW","251/168")
theListOfGoodRuns= ["251244","251251","251252","251561","251562","251643","251883"]
#theListOfGoodRuns= ["251883"]
for aRun in theListOfGoodRuns:
    thelistFile= listFichier("Run2015B","SingleMuon","RAW", aRun)
        #thelistFile= listFichier("Run2015B","DoubleMuon","RECO", aRun)
        
    theListOfList= []
    theSmallList = []
    for file in thelistFile:
        theSmallList.append(file)
        if (len(theSmallList)>4):
            theListOfList.append(theSmallList)
            theSmallList = []
    theListOfList.append(theSmallList)

    file = open("runTheHLT_data.py","r")
    scriptLine = file.readlines()
    file.close()

    iteFile=0


    for fileList in theListOfList:
        nbFileInside = 0
        iteFile=iteFile+1
        outFile = open("runOnlineHLT_data_run"+aRun+"_"+str(iteFile)+".py","w")
        for line in scriptLine:
            if len(re.split("theRAWfiles",line))> 1:
                for theFile in fileList:
                    outFile.write("'"+theFile+"',\n")
                continue
            if len(re.split("outputFile",line))> 1:
                outFile.write("                                   outputFile = cms.string(\"/tmp/hbrun/muonL2treeDATA_run"+aRun+"_"+str(iteFile)+".root\")\n")
                continue
            outFile.write(line)
