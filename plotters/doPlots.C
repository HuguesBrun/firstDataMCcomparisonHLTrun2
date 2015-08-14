TFile *theOutFile;
TChain *chainEvent = new TChain("myTreeEvent");
TChain *chainL2 = new TChain("myTreeL2");
TChain *chainL3 = new TChain("myTreeL3");
TChain *chainL3TnP = new TChain("myTreeTnP");


void preparePlots(TChain *chain, TString name, TString variable, TString cuts, int nBins, float lowBin, float highBin){
    cout << "creating " << name << endl;
    TH1F *histo = new TH1F("histo","",nBins,lowBin,highBin);
    chain->Draw(variable+">>histo",cuts);
    
    theOutFile->cd();
    histo->Write(name);
    
    delete histo;
}




void doPlots(TString theSample = "data"){
    chainL2->Add("theOutFile_"+theSample+".root");
    chainL3->Add("theOutFile_"+theSample+".root");
    chainL3TnP->Add("theOutFile_"+theSample+".root");
    chainEvent->Add("theOutFile_"+theSample+".root");
    
    theOutFile = new TFile("theHistosFile_"+theSample+".root","RECREATE");
    
    
    
    
    TString cutOnL2 = "pass_HLT_L1Single16==1&&L2_pt>10";
    
    preparePlots(chainL2, "ptL2","L2_pt",cutOnL2,100,0,200);
    preparePlots(chainL2, "etaL2","L2_eta",cutOnL2,100,-2.5,2.5);
    preparePlots(chainL2, "phiL2","L2_phi",cutOnL2,100,-3.1416,3.1416);
    preparePlots(chainL2, "dxyL2","L2_dxy",cutOnL2,100,-200,200);
    preparePlots(chainL2, "dzL2","L2_dzBS",cutOnL2,100,-400,400);
    preparePlots(chainL2, "nbStationsWithHits","L2_nbStationWithHits",cutOnL2,10,0,10);
    preparePlots(chainL2, "nbStationsWithHitsCSC","L2_nbStationWithHitsCSC",cutOnL2,10,0,10);
    preparePlots(chainL2, "nbStationsWithHitsDT","L2_nbStationWithHitsDT",cutOnL2,10,0,10);
    preparePlots(chainL2, "nbValidHits","L2_nbValidHits",cutOnL2,30,0,30);
    
    
    TString cutOnL3 = "pass_HLT_L2Mu10==1&&isLeadingL3mu==1&&L3pt>16";//&&passL3filter==1";
    
    preparePlots(chainL3,"ptL3","L3pt",cutOnL3,120,0,60);
    preparePlots(chainL3,"etaL3","L3eta",cutOnL3,100,-2.5,2.5);
    preparePlots(chainL3,"phiL3","L3phi",cutOnL3,100,-3.1416,3.1416);
    preparePlots(chainL3,"drL3","L3dr",cutOnL3,50,0,0.1);
    preparePlots(chainL3,"dzL3","L3dz",cutOnL3,100,0,50);
    preparePlots(chainL3,"dxyL3","L3dxyBS",cutOnL3,50,0,0.25);
    preparePlots(chainL3,"Chi2L3","L3Chi2",cutOnL3,40,0,20);
    preparePlots(chainL3,"L3pfECAL","L3pfECAL",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfECALrho","L3pfECALrho",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfECALrhoRelat","L3pfECALrho/L3pt",cutOnL3,50,0,5);
    preparePlots(chainL3,"L3pfHCAL","L3pfHCAL",cutOnL3,40,0,100);
    preparePlots(chainL3,"L3pfHCALrho","L3pfHCALrho",cutOnL3,40,0,100);
    preparePlots(chainL3,"L3pfHCALrhoRelat","L3pfHCALrho/L3pt",cutOnL3,50,0,5);
    preparePlots(chainL3,"L3TrkIso","L3TrkIso",cutOnL3,30,0,30);
    preparePlots(chainL3,"L3rho","L3rho",cutOnL3,25,0,25);
    
    
    cutOnL3 = "pass_HLT_L2Mu10==1&&isLeadingL3mu==1&&L3pt>50&&passL3filter==1";
    
    preparePlots(chainL3,"ptL3passingL3filter","L3pt",cutOnL3,120,0,60);
    preparePlots(chainL3,"etaL3passingL3filter","L3eta",cutOnL3,100,-2.5,2.5);
    preparePlots(chainL3,"phiL3passingL3filter","L3phi",cutOnL3,100,-3.1416,3.1416);
    preparePlots(chainL3,"drL3passingL3filter","L3dr",cutOnL3,50,0,0.1);
    preparePlots(chainL3,"dzL3passingL3filter","L3dz",cutOnL3,100,0,50);
    preparePlots(chainL3,"dxyL3passingL3filter","L3dxyBS",cutOnL3,50,0,0.25);
    preparePlots(chainL3,"Chi2L3passingL3filter","L3Chi2",cutOnL3,40,0,20);
    preparePlots(chainL3,"L3pfECALpassingL3filter","L3pfECAL",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfECALrhopassingL3filter","L3pfECALrho",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfECALrhoRelatpassingL3filter","L3pfECALrho/L3pt",cutOnL3,50,0,5);
    preparePlots(chainL3,"L3pfHCALpassingL3filter","L3pfHCAL",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfHCALrhopassingL3filter","L3pfHCALrho",cutOnL3,40,0,40);
    preparePlots(chainL3,"L3pfHCALrhoRelatpassingL3filter","L3pfHCALrho/L3pt",cutOnL3,50,0,5);
    preparePlots(chainL3,"L3TrkIsopassingL3filter","L3TrkIso",cutOnL3,30,0,30);
    preparePlots(chainL3,"L3rhopassingL3filter","L3rho",cutOnL3,25,0,25);
    
    
    cutOnL3 = "pass_HLT_Mu20&&L3pt>16";
    preparePlots(chainL3TnP,"massL3passingTnP","mass",cutOnL3,80,30,120);
    preparePlots(chainL3TnP,"ptL3passingTnP","L3pt",cutOnL3,30,0,60);
    preparePlots(chainL3TnP,"etaL3passingTnP","L3eta",cutOnL3,20,-2.5,2.5);
    preparePlots(chainL3TnP,"phiL3passingTnP","L3phi",cutOnL3,20,-3.1416,3.1416);
    preparePlots(chainL3TnP,"drL3passingTnP","L3dr",cutOnL3,20,0,0.05);
    preparePlots(chainL3TnP,"dzL3passingTnP","L3dz",cutOnL3,20,0,25);
    preparePlots(chainL3TnP,"dxyL3passingTnP","L3dxyBS",cutOnL3,20,0,0.5);
    preparePlots(chainL3TnP,"Chi2L3passingTnP","L3Chi2",cutOnL3,20,0,20);
    preparePlots(chainL3TnP,"L3pfECALpassingTnP","L3pfECAL",cutOnL3,20,0,20);
    preparePlots(chainL3TnP,"L3pfECALrhopassingTnP","L3pfECALrho",cutOnL3,20,0,20);
    preparePlots(chainL3TnP,"L3pfECALrhoRelatassingTnP","L3pfECALrho/L3pt",cutOnL3,20,0,1);
    preparePlots(chainL3TnP,"L3pfHCALpassingTnP","L3pfHCAL",cutOnL3,20,0,15);
    preparePlots(chainL3TnP,"L3pfHCALrhopassingTnP","L3pfHCALrho",cutOnL3,20,0,15);
    preparePlots(chainL3TnP,"L3pfHCALrhoRelatpassingTnP","L3pfHCALrho/L3pt",cutOnL3,20,0,1);
    preparePlots(chainL3TnP,"L3TrkIsopassingTnP","L3TrkIso",cutOnL3,20,0,1);
    preparePlots(chainL3TnP,"L3rhopassingTnP","L3rho",cutOnL3,25,0,25);
    
    
    
    preparePlots(chainEvent,"nbL2muons","nbL2muons","1",10,0,10);
    preparePlots(chainEvent,"nbL2muonsPassing","nbL2muons",cutOnL2,10,0,10);
    preparePlots(chainEvent,"nbL3muons","nbL3muons","1",10,0,10);
    preparePlots(chainEvent,"nbL3muonsPassing","nbL3muons","pass_HLT_L2Mu10==1",10,0,10);


    TH2F *L2etaPhi = new TH2F("L2etaPhi","",100,-3.1416,3.1416,100,-2.5,2.5);
    chainL2->Draw("L2_eta:L2_phi>>L2etaPhi");
    theOutFile->cd();
    L2etaPhi->Write();
    
    TH2F *L3etaPhi = new TH2F("L3etaPhi","",100,-3.1416,3.1416,100,-2.5,2.5);
    chainL3->Draw("L3eta:L3phi>>L3etaPhi");
    theOutFile->cd();
    L3etaPhi->Write();

    theOutFile->Close();
}