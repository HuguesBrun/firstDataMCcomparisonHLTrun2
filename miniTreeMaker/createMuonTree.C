#define createMuonTree_cxx
// The class definition in createMuonTree.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("createMuonTree.C")
// root> T->Process("createMuonTree.C","some options")
// root> T->Process("createMuonTree.C+")
//

#include "createMuonTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>
#include <algorithm>


void createMuonTree::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void createMuonTree::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t createMuonTree::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either createMuonTree::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
    
    fChain->GetTree()->GetEntry(entry);
    myIterator++;
    //fChain->GetEntry(entry);
    if (myIterator%100==0) cout << "i=" << myIterator << endl;
    
    if (theCurentLumiSec != T_Event_LuminosityBlock){
        cout << "new lumi section =" << T_Event_LuminosityBlock << endl;
        theCurentLumiSec =T_Event_LuminosityBlock;
        theFullLumi += T_Event_InstLumi;
    }
    
    pass_HLT_L1Single16 = T_Event_pathsFired->at(1);
    pass_HLT_L2Mu10 = T_Event_pathsFired->at(2);
    pass_HLT_Mu20 = T_Event_pathsFired->at(3);
    pass_HLT_IsoMu20 = T_Event_pathsFired->at(4);
/*    pass_HLT_L1Single16 = T_Event_pathsFiredData->at(1);
    pass_HLT_L2Mu10 = T_Event_pathsFiredData->at(2);
    pass_HLT_Mu20 = T_Event_pathsFiredData->at(3);
    pass_HLT_IsoMu20 = T_Event_pathsFiredData->at(4);*/
    
    nbL2muons = T_L2muon_Pt->size();
    //int L2ind = findLeadingPtL2muon();
    for (int i = 0 ; i < nbL2muons ; i++){
        L2_pt = T_L2muon_Pt->at(i);
         L2_eta = T_L2muon_Eta->at(i);
         L2_phi = T_L2muon_Phi->at(i);
         L2_dxy = T_L2muon_dxy->at(i);
         L2_dz = T_L2muon_dz->at(i);
         L2_dxyBS = T_L2muon_dxyBS->at(i);
         L2_dzBS = T_L2muon_dzBS->at(i);
         L2_ptLx =  T_L2muon_ptLx->at(i);
         L2_nbStationWithHits =  T_L2muon_nbStationWithHits->at(i);
         L2_nbStationWithHitsDT = T_L2muon_nbStationWithHitsDT->at(i);
         L2_nbStationWithHitsCSC =T_L2muon_nbStationWithHitsCSC->at(i);
         L2_nbValidHits = T_L2muon_nbValidHits->at(i);
         myTree->Fill();
    }
    
    nbL3muons = T_L3muon_Pt->size();
    for (int i = 0 ; i < nbL3muons ; i++){
        passL3filter = T_L3muon_PassingL3filter->at(i);
        isLeadingL3mu = checkIsLeadingL3mu(i);
        L3pt =T_L3muon_Pt->at(i);
         L3eta = T_L3muon_Eta->at(i);
         L3phi = T_L3muon_Phi->at(i);
         L3dr = T_L3muon_dr->at(i);
         L3dz = T_L3muon_dz->at(i);
         L3dxyBS = T_L3muon_dxyBS->at(i);
         L3Chi2 = T_L3muon_Chi2->at(i);
         L3pfECAL = T_L3muon_pfEcal->at(i);
         L3pfHCAL = T_L3muon_pfHcal->at(i);
         L3TrkIso = T_L3muon_trkIso->at(i);
        L3pfECALrho = (T_L3muon_Eta->at(i)<1.479) ? T_L3muon_pfEcal->at(i) - 0.1447* hltRho :  T_L3muon_pfEcal->at(i) - 0.0858* hltRho;
        L3pfHCALrho = (T_L3muon_Eta->at(i)<1.479) ? T_L3muon_pfHcal->at(i) - 0.0652* hltRho :  T_L3muon_pfHcal->at(i) - 0.132* hltRho;
        L3rho = hltRho;
        myTreeL3->Fill();

    }
    
    if (nbL3muons>1){
        for (int j=0 ; j < nbL3muons ; j++){
            if (!(T_L3muon_Pt->at(j)> 20)) continue;
            if (!(fabs(T_L3muon_Eta->at(j))<2.4)) continue;
            if (!T_L3muon_PassingL3filter->at(j)) continue;
            if (T_L3muon_trkIso->at(j)>1) continue;
            TLorentzVector *tag = new TLorentzVector(T_L3muon_Px->at(j),T_L3muon_Py->at(j),T_L3muon_Pz->at(j),T_L3muon_Energy->at(j));
            for (int i= 0 ; i < nbL3muons ; i++){
                if (i==j) continue;
                passL3filter = T_L3muon_PassingL3filter->at(i);
                L3pt =T_L3muon_Pt->at(i);
                L3eta = T_L3muon_Eta->at(i);
                L3phi = T_L3muon_Phi->at(i);
                L3dr = T_L3muon_dr->at(i);
                L3dz = T_L3muon_dz->at(i);
                L3dxyBS = T_L3muon_dxyBS->at(i);
                L3Chi2 = T_L3muon_Chi2->at(i);
                L3pfECAL = T_L3muon_pfEcal->at(i);
                L3pfHCAL = T_L3muon_pfHcal->at(i);
                L3TrkIso = T_L3muon_trkIso->at(i);
                L3pfECALrho = (T_L3muon_Eta->at(i)<1.479) ? T_L3muon_pfEcal->at(i) - 0.1447* hltRho :  T_L3muon_pfEcal->at(i) - 0.0858* hltRho;
                L3pfHCALrho = (T_L3muon_Eta->at(i)<1.479) ? T_L3muon_pfHcal->at(i) - 0.0652* hltRho :  T_L3muon_pfHcal->at(i) - 0.132* hltRho;
                L3rho = hltRho;
                TLorentzVector *probe = new TLorentzVector(T_L3muon_Px->at(i),T_L3muon_Py->at(i),T_L3muon_Pz->at(i),T_L3muon_Energy->at(i));
                TLorentzVector sum = *tag + *probe;
                mass = sum.M();
                myTreeTnP->Fill();
            }
        }
    }
    
    int nbTkMuons = T_Tkmuon_Pt->size();
    if (nbTkMuons>0&&nbL3muons>0) {
        for (int j=0 ; j < nbL3muons ; j++){
            if (!(T_L3muon_Pt->at(j)> 20)) continue;
            if (!(fabs(T_L3muon_Eta->at(j))<2.4)) continue;
            if (!T_L3muon_PassingL3filter->at(j)) continue;
            if (T_L3muon_trkIso->at(j)>1) continue;
            TLorentzVector *tag = new TLorentzVector(T_L3muon_Px->at(j),T_L3muon_Py->at(j),T_L3muon_Pz->at(j),T_L3muon_Energy->at(j));
            for (int i = 0 ; i < nbTkMuons ; i++){
                float deltaR = sqrt(pow(T_L3muon_Eta->at(j)-T_Tkmuon_Eta->at(i),2)+ pow(acos(cos(T_L3muon_Phi->at(j)-T_Tkmuon_Phi->at(i))),2)) ;
                if (deltaR<0.1) continue;
                TLorentzVector *probe = new TLorentzVector(T_Tkmuon_Px->at(i),T_Tkmuon_Py->at(i),T_Tkmuon_Pz->at(i),T_Tkmuon_Energy->at(i));
                TLorentzVector sum = *tag + *probe;
                mass = sum.M();
                tkMuon_pt = T_Tkmuon_Pt->at(i);
                tkMuon_eta = T_Tkmuon_Eta->at(i);
                tkMuon_phi = T_Tkmuon_Phi->at(i);
                tkMuon_l2found = 0;
                int iteL2muon = -1;
                float minDr=100;
                for (int k = 0 ; k < nbL2muons ; k++){
                    float deltaR2 = sqrt(pow(T_L2muon_Eta->at(k)-T_Tkmuon_Eta->at(i),2)+ pow(acos(cos(T_L2muon_Phi->at(k)-T_Tkmuon_Phi->at(i))),2)) ;
                    if (deltaR2<minDr) {minDr = deltaR2; iteL2muon = k;}
                }
                if (minDr<0.2){
                    tkMuon_l2found = 1;
                    L2_pt = T_L2muon_Pt->at(iteL2muon);
                    L2_eta = T_L2muon_Eta->at(iteL2muon);
                    L2_phi = T_L2muon_Phi->at(iteL2muon);
                    L2_dxy = T_L2muon_dxy->at(iteL2muon);
                    L2_dz = T_L2muon_dz->at(iteL2muon);
                    L2_dxyBS = T_L2muon_dxyBS->at(iteL2muon);
                    L2_dzBS = T_L2muon_dzBS->at(iteL2muon);
                    L2_ptLx =  T_L2muon_ptLx->at(iteL2muon);
                    L2_nbStationWithHits =  T_L2muon_nbStationWithHits->at(iteL2muon);
                    L2_nbStationWithHitsDT = T_L2muon_nbStationWithHitsDT->at(iteL2muon);
                    L2_nbStationWithHitsCSC =T_L2muon_nbStationWithHitsCSC->at(iteL2muon);
                    L2_nbValidHits = T_L2muon_nbValidHits->at(iteL2muon);
                    deltaEta =   L2_eta - tkMuon_eta;
                    deltaPhi =   L2_phi - tkMuon_phi;
                    deltaPtoverPt = (L2_pt-tkMuon_pt)/tkMuon_pt;
                }
                else {
                    L2_pt = -1;
                    L2_eta = -1;
                    L2_phi = -1;
                    L2_dxy = -1;
                    L2_dz = -1;
                    L2_dxyBS = -1;
                    L2_dzBS = -1;
                    L2_ptLx = -1;
                    L2_nbStationWithHits =  -1;
                    L2_nbStationWithHitsDT = -1;
                    L2_nbStationWithHitsCSC =-1;
                    L2_nbValidHits = -1;
                }
                
                myTreeTnPL2->Fill();
            }
            
        }
    }
    
    myTreeEvent->Fill();
    
   return kTRUE;
}

void createMuonTree::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void createMuonTree::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
    
    std::cout << "theFullLumi=" << theFullLumi*23 << std::endl;
    
    myFile->Write();
    myFile->Close();

}

bool createMuonTree::checkIsLeadingL3mu(int localIte){
    int nbL3muons = T_L3muon_Pt->size();
    float maxPt = 0;
    int indMax = -1;
    for (int i = 0 ; i < nbL3muons ; i++){
        float thePt = T_L3muon_Pt->at(i);
        if (thePt>maxPt){
            maxPt = thePt;
            indMax = i;
        }
    }
    if (localIte==indMax) return true;
    else return false;
}
