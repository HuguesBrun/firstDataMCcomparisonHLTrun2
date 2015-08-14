//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul  8 11:12:59 2015 by ROOT version 6.02/04
// from TTree eventsTree/
// found on file: file1.root
//////////////////////////////////////////////////////////

#ifndef createMuonTree_h
#define createMuonTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TLorentzVector.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

class createMuonTree : public TSelector {
public :
    
    
    TFile *myFile;
    TTree *myTree;
    TTree *myTreeEvent;
    TTree *myTreeL3;
    TTree *myTreeTnP;
    TTree *myTreeTnPL2;
    
    int myIterator;
    int theCurentLumiSec;
    float  theFullLumi;

    
    int pass_HLT_L1Single16;
    int pass_HLT_L2Mu10;
    int pass_HLT_Mu20;
    int pass_HLT_IsoMu20;
    
    
    
    int nbL2muons;
    float L2_pt;
    float L2_eta;
    float L2_phi;
    float L2_dxy;
    float L2_dz;
    float L2_dxyBS;
    float L2_dzBS;
    float L2_ptLx;
    int L2_nbStationWithHits;
    int L2_nbStationWithHitsDT;
    int L2_nbStationWithHitsCSC;
    int L2_nbValidHits;
    
    int nbL3muons;
    
    int isLeadingL3mu;
    int passL3filter;
    float L3pt;
    float L3eta;
    float L3phi;
    float L3dr;
    float L3dz;
    float L3dxyBS;
    float L3Chi2;
    float L3pfECAL;
    float L3pfECALrho;
    float L3pfHCAL;
    float L3pfHCALrho;
    float L3TrkIso;
    float L3rho;
    float mass;
    
    float tkMuon_pt;
    float tkMuon_eta;
    float tkMuon_phi;
    int tkMuon_l2found;
    
    float deltaEta;
    float deltaPhi;
    float deltaPtoverPt;
    
    
    
    
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

    // Declaration of leaf types
    Int_t           T_Event_RunNumber;
    Int_t           T_Event_EventNumber;
    Int_t           T_Event_LuminosityBlock;
    Float_t         T_Event_InstLumi;
    Int_t           T_nbStripClusters;
    Int_t           T_Event_PassL3muon;
    Int_t           T_Event_nPU;
    Int_t           T_Event_nTruePU;
    Float_t         T_Event_PUeventPtHat;
    Int_t           T_Event_PUdominated;
    Int_t           T_Event_AveNTruePU;
    Float_t         T_Event_PUptHat2;
    Float_t         T_Event_PUptHat;
    Int_t           T_Event_nPUm;
    Int_t           T_Event_nPUp;
    Int_t           T_Event_antiMuEnrichementVeto;
    vector<int>     *T_Event_pathsFired;
    vector<int>     *T_Event_pathsFiredData;
    Float_t         BSx;
    Float_t         BSy;
    Float_t         BSz;
    Float_t         hltRho;
    vector<float>   *T_L2muon_Pt;
    vector<float>   *T_L2muon_Eta;
    vector<float>   *T_L2muon_Phi;
    vector<float>   *T_L2muon_dxy;
    vector<float>   *T_L2muon_dz;
    vector<float>   *T_L2muon_dxyBS;
    vector<float>   *T_L2muon_dzBS;
    vector<float>   *T_L2muon_ptLx;
    vector<int>     *T_L2muon_nbStationWithHits;
    vector<int>     *T_L2muon_nbStationWithHitsDT;
    vector<int>     *T_L2muon_nbStationWithHitsCSC;
    vector<int>     *T_L2muon_nbValidHits;
    vector<int>     *T_L3muon_PassingL3filter;
    vector<float>   *T_L3muon_Pt;
    vector<float>   *T_L3muon_Px;
    vector<float>   *T_L3muon_Py;
    vector<float>   *T_L3muon_Pz;
    vector<float>   *T_L3muon_Energy;
    vector<float>   *T_L3muon_Eta;
    vector<float>   *T_L3muon_Phi;
    vector<float>   *T_L3muon_dr;
    vector<float>   *T_L3muon_dz;
    vector<float>   *T_L3muon_dxyBS;
    vector<float>   *T_L3muon_Chi2;
    vector<float>   *T_L3muon_pfEcal;
    vector<float>   *T_L3muon_pfHcal;
    vector<float>   *T_L3muon_trkIso;
    vector<float>   *T_Tkmuon_Pt;
    vector<float>   *T_Tkmuon_Px;
    vector<float>   *T_Tkmuon_Py;
    vector<float>   *T_Tkmuon_Pz;
    vector<float>   *T_Tkmuon_Energy;
    vector<float>   *T_Tkmuon_Eta;
    vector<float>   *T_Tkmuon_Phi;
    vector<int>     *T_Tkmuon_matchedStation;
    vector<float>   *T_Tkmuon_normChi2;
    vector<int>     *T_Tkmuon_validMuonHit;
    vector<int>     *T_Tkmuon_validHit;
    vector<int>     *T_Tkmuon_type;
    vector<int>     *T_Tkmuon_goodTrackerMuon;
    
    // List of branches
    TBranch        *b_T_Event_RunNumber;   //!
    TBranch        *b_T_Event_EventNumber;   //!
    TBranch        *b_T_Event_LuminosityBlock;   //!
    TBranch        *b_T_Event_InstLumi;   //!
    TBranch        *b_T_nbStripClusters;   //!
    TBranch        *b_T_Event_PassL3muon;   //!
    TBranch        *b_T_Event_nPU;   //!
    TBranch        *b_T_Event_nTruePU;   //!
    TBranch        *b_T_Event_PUeventPtHat;   //!
    TBranch        *b_T_Event_PUdominated;   //!
    TBranch        *b_T_Event_AveNTruePU;   //!
    TBranch        *b_T_Event_PUptHat2;   //!
    TBranch        *b_T_Event_PUptHat;   //!
    TBranch        *b_T_Event_nPUm;   //!
    TBranch        *b_T_Event_nPUp;   //!
    TBranch        *b_T_Event_antiMuEnrichementVeto;   //!
    TBranch        *b_T_Event_pathsFired;   //!
    TBranch        *b_T_Event_pathsFiredData;   //!
    TBranch        *b_BSx;   //!
    TBranch        *b_BSy;   //!
    TBranch        *b_BSz;   //!
    TBranch        *b_hltRho;   //!
    TBranch        *b_T_L2muon_Pt;   //!
    TBranch        *b_T_L2muon_Eta;   //!
    TBranch        *b_T_L2muon_Phi;   //!
    TBranch        *b_T_L2muon_dxy;   //!
    TBranch        *b_T_L2muon_dz;   //!
    TBranch        *b_T_L2muon_dxyBS;   //!
    TBranch        *b_T_L2muon_dzBS;   //!
    TBranch        *b_T_L2muon_ptLx;   //!
    TBranch        *b_T_L2muon_nbStationWithHits;   //!
    TBranch        *b_T_L2muon_nbStationWithHitsDT;   //!
    TBranch        *b_T_L2muon_nbStationWithHitsCSC;   //!
    TBranch        *b_T_L2muon_nbValidHits;   //!
    TBranch        *b_T_L3muon_PassingL3filter;   //!
    TBranch        *b_T_L3muon_Pt;   //!
    TBranch        *b_T_L3muon_Px;   //!
    TBranch        *b_T_L3muon_Py;   //!
    TBranch        *b_T_L3muon_Pz;   //!
    TBranch        *b_T_L3muon_Energy;   //!
    TBranch        *b_T_L3muon_Eta;   //!
    TBranch        *b_T_L3muon_Phi;   //!
    TBranch        *b_T_L3muon_dr;   //!
    TBranch        *b_T_L3muon_dz;   //!
    TBranch        *b_T_L3muon_dxyBS;   //!
    TBranch        *b_T_L3muon_Chi2;   //!
    TBranch        *b_T_L3muon_pfEcal;   //!
    TBranch        *b_T_L3muon_pfHcal;   //!
    TBranch        *b_T_L3muon_trkIso;   //!
    TBranch        *b_T_Tkmuon_Pt;   //!
    TBranch        *b_T_Tkmuon_Px;   //!
    TBranch        *b_T_Tkmuon_Py;   //!
    TBranch        *b_T_Tkmuon_Pz;   //!
    TBranch        *b_T_Tkmuon_Energy;   //!
    TBranch        *b_T_Tkmuon_Eta;   //!
    TBranch        *b_T_Tkmuon_Phi;   //!
    TBranch        *b_T_Tkmuon_matchedStation;   //!
    TBranch        *b_T_Tkmuon_normChi2;   //!
    TBranch        *b_T_Tkmuon_validMuonHit;   //!
    TBranch        *b_T_Tkmuon_validHit;   //!
    TBranch        *b_T_Tkmuon_type;   //!
    TBranch        *b_T_Tkmuon_goodTrackerMuon;   //!
    
    
   createMuonTree(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~createMuonTree() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
   virtual bool     checkIsLeadingL3mu(int);


   ClassDef(createMuonTree,0);
};

#endif

#ifdef createMuonTree_cxx
void createMuonTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).
    
    myIterator=0;
    theCurentLumiSec = -1;
    theFullLumi = 0;
    
    myFile = new TFile("theOutFile.root","RECREATE");
    myTreeEvent = new TTree("myTreeEvent","");
    myTreeEvent->Branch("nbL2muons", &nbL2muons,"nbL2muons/I");
    myTreeEvent->Branch("nbL3muons", &nbL3muons,"nbL3muons/I");
    
    myTreeEvent->Branch("pass_HLT_L1Single16", &pass_HLT_L1Single16,"pass_HLT_L1Single16/I");
    myTreeEvent->Branch("pass_HLT_L2Mu10", &pass_HLT_L2Mu10,"pass_HLT_L2Mu10/I");
    myTreeEvent->Branch("pass_HLT_IsoMu20", &pass_HLT_IsoMu20,"pass_HLT_IsoMu20/I");
    myTreeEvent->Branch("pass_HLT_Mu20", &pass_HLT_Mu20,"pass_HLT_Mu20/I");
    
    myTreeEvent->Branch("BSx", &BSx,"BSx/F");
    myTreeEvent->Branch("BSy", &BSy,"BSy/F");
    myTreeEvent->Branch("BSz", &BSz,"BSz/F");
    
    myTree = new TTree("myTreeL2","");
    myTree->Branch("pass_HLT_L1Single16", &pass_HLT_L1Single16,"pass_HLT_L1Single16/I");
    myTree->Branch("pass_HLT_L2Mu10", &pass_HLT_L2Mu10,"pass_HLT_L2Mu10/I");
    myTree->Branch("L2_pt", &L2_pt,"L2_pt/F");
    myTree->Branch("L2_eta", &L2_eta,"L2_eta/F");
    myTree->Branch("L2_phi", &L2_phi,"L2_phi/F");
    myTree->Branch("L2_dxy", &L2_dxy,"L2_dxy/F");
    myTree->Branch("L2_dz", &L2_dz,"L2_dz/F");
    myTree->Branch("L2_dxyBS", &L2_dxyBS,"L2_dxyBS/F");
    myTree->Branch("L2_dzBS", &L2_dzBS,"L2_dzBS/F");
    myTree->Branch("L2_ptLx", &L2_ptLx,"L2_ptLx/F");
    myTree->Branch("L2_nbStationWithHits", &L2_nbStationWithHits,"L2_nbStationWithHits/I");
    myTree->Branch("L2_nbStationWithHitsDT", &L2_nbStationWithHitsDT,"L2_nbStationWithHitsDT/I");
    myTree->Branch("L2_nbStationWithHitsCSC", &L2_nbStationWithHitsCSC,"L2_nbStationWithHitsCSC/I");
    myTree->Branch("L2_nbValidHits", &L2_nbValidHits,"L2_nbValidHits/I");
    

    myTreeL3 = new TTree("myTreeL3","");
    myTreeL3->Branch("pass_HLT_L2Mu10", &pass_HLT_L2Mu10,"pass_HLT_L2Mu10/I");
    myTreeL3->Branch("passL3filter", &passL3filter,"passL3filter/I");
    myTreeL3->Branch("isLeadingL3mu", &isLeadingL3mu,"isLeadingL3mu/I");
    myTreeL3->Branch("L3pt", &L3pt,"L3pt/F");
    myTreeL3->Branch("L3eta", &L3eta,"L3eta/F");
    myTreeL3->Branch("L3phi", &L3phi,"L3phi/F");
    myTreeL3->Branch("L3dr", &L3dr,"L3dr/F");
    myTreeL3->Branch("L3dz", &L3dz,"L3dz/F");
    myTreeL3->Branch("L3dxyBS", &L3dxyBS,"L3dxyBS/F");
    myTreeL3->Branch("L3Chi2", &L3Chi2,"L3Chi2/F");
    myTreeL3->Branch("L3pfECAL", &L3pfECAL,"L3pfECAL/F");
    myTreeL3->Branch("L3pfECALrho", &L3pfECALrho,"L3pfECALrho/F");
    myTreeL3->Branch("L3pfHCAL", &L3pfHCAL,"L3pfHCAL/F");
    myTreeL3->Branch("L3pfHCALrho", &L3pfHCALrho,"L3pfHCALrho/F");
    myTreeL3->Branch("L3TrkIso", &L3TrkIso,"L3TrkIso/F");
    myTreeL3->Branch("L3rho", &L3rho,"L3rho/F");

    myTreeTnP = new TTree("myTreeTnP","");
    myTreeTnP->Branch("pass_HLT_L2Mu10", &pass_HLT_L2Mu10,"pass_HLT_L2Mu10/I");
    myTreeTnP->Branch("pass_HLT_Mu20", &pass_HLT_Mu20,"pass_HLT_Mu20/I");
    myTreeTnP->Branch("passL3filter", &passL3filter,"passL3filter/I");
    myTreeTnP->Branch("L3pt", &L3pt,"L3pt/F");
    myTreeTnP->Branch("L3eta", &L3eta,"L3eta/F");
    myTreeTnP->Branch("L3phi", &L3phi,"L3phi/F");
    myTreeTnP->Branch("L3dr", &L3dr,"L3dr/F");
    myTreeTnP->Branch("L3dz", &L3dz,"L3dz/F");
    myTreeTnP->Branch("L3dxyBS", &L3dxyBS,"L3dxyBS/F");
    myTreeTnP->Branch("L3Chi2", &L3Chi2,"L3Chi2/F");
    myTreeTnP->Branch("L3pfECAL", &L3pfECAL,"L3pfECAL/F");
    myTreeTnP->Branch("L3pfECALrho", &L3pfECALrho,"L3pfECALrho/F");
    myTreeTnP->Branch("L3pfHCAL", &L3pfHCAL,"L3pfHCAL/F");
    myTreeTnP->Branch("L3pfHCALrho", &L3pfHCALrho,"L3pfHCALrho/F");
    myTreeTnP->Branch("L3TrkIso", &L3TrkIso,"L3TrkIso/F");
    myTreeTnP->Branch("L3rho", &L3rho,"L3rho/F");
    myTreeTnP->Branch("mass", &mass,"mass/F");
    
    
    myTreeTnPL2 = new TTree("myTreeCheckL2TnP","");
  //  myTree->Branch("pass_HLT_L1Single16", &pass_HLT_L1Single16,"pass_HLT_L1Single16/I");
    myTreeTnPL2->Branch("pass_HLT_IsoMu20", &pass_HLT_IsoMu20,"pass_HLT_IsoMu20/I");
    myTreeTnPL2->Branch("tkMuon_pt", &tkMuon_pt,"tkMuon_pt/F");
    myTreeTnPL2->Branch("tkMuon_eta", &tkMuon_eta,"tkMuon_eta/F");
    myTreeTnPL2->Branch("tkMuon_phi", &tkMuon_phi,"tkMuon_phi/F");
    myTreeTnPL2->Branch("tkMuon_l2found", &tkMuon_l2found,"tkMuon_l2found/I");

    myTreeTnPL2->Branch("deltaEta", &deltaEta,"deltaEta/F");
    myTreeTnPL2->Branch("deltaPhi", &deltaPhi,"deltaPhi/F");
    myTreeTnPL2->Branch("deltaPtoverPt", &deltaPtoverPt,"deltaPtoverPt/F");

    
    myTreeTnPL2->Branch("L2_pt", &L2_pt,"L2_pt/F");
    myTreeTnPL2->Branch("L2_eta", &L2_eta,"L2_eta/F");
    myTreeTnPL2->Branch("L2_phi", &L2_phi,"L2_phi/F");
    myTreeTnPL2->Branch("L2_dxy", &L2_dxy,"L2_dxy/F");
    myTreeTnPL2->Branch("L2_dz", &L2_dz,"L2_dz/F");
    myTreeTnPL2->Branch("L2_dxyBS", &L2_dxyBS,"L2_dxyBS/F");
    myTreeTnPL2->Branch("L2_dzBS", &L2_dzBS,"L2_dzBS/F");
    myTreeTnPL2->Branch("L2_ptLx", &L2_ptLx,"L2_ptLx/F");
    myTreeTnPL2->Branch("L2_nbStationWithHits", &L2_nbStationWithHits,"L2_nbStationWithHits/I");
    myTreeTnPL2->Branch("L2_nbStationWithHitsDT", &L2_nbStationWithHitsDT,"L2_nbStationWithHitsDT/I");
    myTreeTnPL2->Branch("L2_nbStationWithHitsCSC", &L2_nbStationWithHitsCSC,"L2_nbStationWithHitsCSC/I");
    myTreeTnPL2->Branch("L2_nbValidHits", &L2_nbValidHits,"L2_nbValidHits/I");
    myTreeTnPL2->Branch("mass", &mass,"mass/F");

   // Set object pointer
    // Set object pointer
    // Set object pointer
    T_Event_pathsFired = 0;
    T_Event_pathsFiredData = 0;
    T_L2muon_Pt = 0;
    T_L2muon_Eta = 0;
    T_L2muon_Phi = 0;
    T_L2muon_dxy = 0;
    T_L2muon_dz = 0;
    T_L2muon_dxyBS = 0;
    T_L2muon_dzBS = 0;
    T_L2muon_ptLx = 0;
    T_L2muon_nbStationWithHits = 0;
    T_L2muon_nbStationWithHitsDT = 0;
    T_L2muon_nbStationWithHitsCSC = 0;
    T_L2muon_nbValidHits = 0;
    T_L3muon_PassingL3filter = 0;
    T_L3muon_Pt = 0;
    T_L3muon_Px = 0;
    T_L3muon_Py = 0;
    T_L3muon_Pz = 0;
    T_L3muon_Energy = 0;
    T_L3muon_Eta = 0;
    T_L3muon_Phi = 0;
    T_L3muon_dr = 0;
    T_L3muon_dz = 0;
    T_L3muon_dxyBS = 0;
    T_L3muon_Chi2 = 0;
    T_L3muon_pfEcal = 0;
    T_L3muon_pfHcal = 0;
    T_L3muon_trkIso = 0;
    T_Tkmuon_Pt = 0;
    T_Tkmuon_Px = 0;
    T_Tkmuon_Py = 0;
    T_Tkmuon_Pz = 0;
    T_Tkmuon_Energy = 0;
    T_Tkmuon_Eta = 0;
    T_Tkmuon_Phi = 0;
    T_Tkmuon_matchedStation = 0;
    T_Tkmuon_normChi2 = 0;
    T_Tkmuon_validMuonHit = 0;
    T_Tkmuon_validHit = 0;
    T_Tkmuon_type = 0;
    T_Tkmuon_goodTrackerMuon = 0;
    // Set branch addresses and branch pointers
    if (!tree) return;
    fChain = tree;
    fChain->SetMakeClass(1);
    
    fChain->SetBranchAddress("T_Event_RunNumber", &T_Event_RunNumber, &b_T_Event_RunNumber);
    fChain->SetBranchAddress("T_Event_EventNumber", &T_Event_EventNumber, &b_T_Event_EventNumber);
    fChain->SetBranchAddress("T_Event_LuminosityBlock", &T_Event_LuminosityBlock, &b_T_Event_LuminosityBlock);
    fChain->SetBranchAddress("T_Event_InstLumi", &T_Event_InstLumi, &b_T_Event_InstLumi);
    fChain->SetBranchAddress("T_nbStripClusters", &T_nbStripClusters, &b_T_nbStripClusters);
    fChain->SetBranchAddress("T_Event_PassL3muon", &T_Event_PassL3muon, &b_T_Event_PassL3muon);
    fChain->SetBranchAddress("T_Event_nPU", &T_Event_nPU, &b_T_Event_nPU);
    fChain->SetBranchAddress("T_Event_nTruePU", &T_Event_nTruePU, &b_T_Event_nTruePU);
    fChain->SetBranchAddress("T_Event_PUeventPtHat", &T_Event_PUeventPtHat, &b_T_Event_PUeventPtHat);
    fChain->SetBranchAddress("T_Event_PUdominated", &T_Event_PUdominated, &b_T_Event_PUdominated);
    fChain->SetBranchAddress("T_Event_AveNTruePU", &T_Event_AveNTruePU, &b_T_Event_AveNTruePU);
    fChain->SetBranchAddress("T_Event_PUptHat2", &T_Event_PUptHat2, &b_T_Event_PUptHat2);
    fChain->SetBranchAddress("T_Event_PUptHat", &T_Event_PUptHat, &b_T_Event_PUptHat);
    fChain->SetBranchAddress("T_Event_nPUm", &T_Event_nPUm, &b_T_Event_nPUm);
    fChain->SetBranchAddress("T_Event_nPUp", &T_Event_nPUp, &b_T_Event_nPUp);
    fChain->SetBranchAddress("T_Event_antiMuEnrichementVeto", &T_Event_antiMuEnrichementVeto, &b_T_Event_antiMuEnrichementVeto);
    fChain->SetBranchAddress("T_Event_pathsFired", &T_Event_pathsFired, &b_T_Event_pathsFired);
    fChain->SetBranchAddress("T_Event_pathsFiredData", &T_Event_pathsFiredData, &b_T_Event_pathsFiredData);
    fChain->SetBranchAddress("BSx", &BSx, &b_BSx);
    fChain->SetBranchAddress("BSy", &BSy, &b_BSy);
    fChain->SetBranchAddress("BSz", &BSz, &b_BSz);
    fChain->SetBranchAddress("hltRho", &hltRho, &b_hltRho);
    fChain->SetBranchAddress("T_L2muon_Pt", &T_L2muon_Pt, &b_T_L2muon_Pt);
    fChain->SetBranchAddress("T_L2muon_Eta", &T_L2muon_Eta, &b_T_L2muon_Eta);
    fChain->SetBranchAddress("T_L2muon_Phi", &T_L2muon_Phi, &b_T_L2muon_Phi);
    fChain->SetBranchAddress("T_L2muon_dxy", &T_L2muon_dxy, &b_T_L2muon_dxy);
    fChain->SetBranchAddress("T_L2muon_dz", &T_L2muon_dz, &b_T_L2muon_dz);
    fChain->SetBranchAddress("T_L2muon_dxyBS", &T_L2muon_dxyBS, &b_T_L2muon_dxyBS);
    fChain->SetBranchAddress("T_L2muon_dzBS", &T_L2muon_dzBS, &b_T_L2muon_dzBS);
    fChain->SetBranchAddress("T_L2muon_ptLx", &T_L2muon_ptLx, &b_T_L2muon_ptLx);
    fChain->SetBranchAddress("T_L2muon_nbStationWithHits", &T_L2muon_nbStationWithHits, &b_T_L2muon_nbStationWithHits);
    fChain->SetBranchAddress("T_L2muon_nbStationWithHitsDT", &T_L2muon_nbStationWithHitsDT, &b_T_L2muon_nbStationWithHitsDT);
    fChain->SetBranchAddress("T_L2muon_nbStationWithHitsCSC", &T_L2muon_nbStationWithHitsCSC, &b_T_L2muon_nbStationWithHitsCSC);
    fChain->SetBranchAddress("T_L2muon_nbValidHits", &T_L2muon_nbValidHits, &b_T_L2muon_nbValidHits);
    fChain->SetBranchAddress("T_L3muon_PassingL3filter", &T_L3muon_PassingL3filter, &b_T_L3muon_PassingL3filter);
    fChain->SetBranchAddress("T_L3muon_Pt", &T_L3muon_Pt, &b_T_L3muon_Pt);
    fChain->SetBranchAddress("T_L3muon_Px", &T_L3muon_Px, &b_T_L3muon_Px);
    fChain->SetBranchAddress("T_L3muon_Py", &T_L3muon_Py, &b_T_L3muon_Py);
    fChain->SetBranchAddress("T_L3muon_Pz", &T_L3muon_Pz, &b_T_L3muon_Pz);
    fChain->SetBranchAddress("T_L3muon_Energy", &T_L3muon_Energy, &b_T_L3muon_Energy);
    fChain->SetBranchAddress("T_L3muon_Eta", &T_L3muon_Eta, &b_T_L3muon_Eta);
    fChain->SetBranchAddress("T_L3muon_Phi", &T_L3muon_Phi, &b_T_L3muon_Phi);
    fChain->SetBranchAddress("T_L3muon_dr", &T_L3muon_dr, &b_T_L3muon_dr);
    fChain->SetBranchAddress("T_L3muon_dz", &T_L3muon_dz, &b_T_L3muon_dz);
    fChain->SetBranchAddress("T_L3muon_dxyBS", &T_L3muon_dxyBS, &b_T_L3muon_dxyBS);
    fChain->SetBranchAddress("T_L3muon_Chi2", &T_L3muon_Chi2, &b_T_L3muon_Chi2);
    fChain->SetBranchAddress("T_L3muon_pfEcal", &T_L3muon_pfEcal, &b_T_L3muon_pfEcal);
    fChain->SetBranchAddress("T_L3muon_pfHcal", &T_L3muon_pfHcal, &b_T_L3muon_pfHcal);
    fChain->SetBranchAddress("T_L3muon_trkIso", &T_L3muon_trkIso, &b_T_L3muon_trkIso);
    fChain->SetBranchAddress("T_Tkmuon_Pt", &T_Tkmuon_Pt, &b_T_Tkmuon_Pt);
    fChain->SetBranchAddress("T_Tkmuon_Px", &T_Tkmuon_Px, &b_T_Tkmuon_Px);
    fChain->SetBranchAddress("T_Tkmuon_Py", &T_Tkmuon_Py, &b_T_Tkmuon_Py);
    fChain->SetBranchAddress("T_Tkmuon_Pz", &T_Tkmuon_Pz, &b_T_Tkmuon_Pz);
    fChain->SetBranchAddress("T_Tkmuon_Energy", &T_Tkmuon_Energy, &b_T_Tkmuon_Energy);
    fChain->SetBranchAddress("T_Tkmuon_Eta", &T_Tkmuon_Eta, &b_T_Tkmuon_Eta);
    fChain->SetBranchAddress("T_Tkmuon_Phi", &T_Tkmuon_Phi, &b_T_Tkmuon_Phi);
    fChain->SetBranchAddress("T_Tkmuon_matchedStation", &T_Tkmuon_matchedStation, &b_T_Tkmuon_matchedStation);
    fChain->SetBranchAddress("T_Tkmuon_normChi2", &T_Tkmuon_normChi2, &b_T_Tkmuon_normChi2);
    fChain->SetBranchAddress("T_Tkmuon_validMuonHit", &T_Tkmuon_validMuonHit, &b_T_Tkmuon_validMuonHit);
    fChain->SetBranchAddress("T_Tkmuon_validHit", &T_Tkmuon_validHit, &b_T_Tkmuon_validHit);
    fChain->SetBranchAddress("T_Tkmuon_type", &T_Tkmuon_type, &b_T_Tkmuon_type);
    fChain->SetBranchAddress("T_Tkmuon_goodTrackerMuon", &T_Tkmuon_goodTrackerMuon, &b_T_Tkmuon_goodTrackerMuon);
}

Bool_t createMuonTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef createMuonTree_cxx
