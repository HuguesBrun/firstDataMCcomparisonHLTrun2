
TFile *file_QCDMuPt15to20 = new TFile("theHistosFile_QCDMuPt15to20.root");
TFile *file_QCDMuPt20to30 = new TFile("theHistosFile_QCDMuPt20to30.root");
TFile *file_QCDMuPt30to50 = new TFile("theHistosFile_QCDMuPt30to50.root");
TFile *file_QCDMuPt50to80 = new TFile("theHistosFile_QCDMuPt50to80.root");
TFile *file_QCDMuPt80to120 = new TFile("theHistosFile_QCDMuPt80to120.root");

TFile *file_W = new TFile("theHistosFile_W.root");

TFile *file_DY = new TFile("theHistosFile_DY.root");
TFile *file_data = new TFile("theHistosFile_data.root");


float theMax(float a, float b){
    if (a>b) return a;
    return b;
}

void makeThePlot(float glbScale, TString plotName, TString xAxis, TString yAxis, TString outDir){
    TH1F *histoQCDMuPt15to20 = (TH1F*) file_QCDMuPt15to20->Get(plotName);
    TH1F *L2histoQCDMuPt15to20 = (TH1F*) file_QCDMuPt15to20->Get("nbL3muons");
    float scale_QCDMuPt15to20 = 1273190000.*0.003/L2histoQCDMuPt15to20->GetEntries();
    histoQCDMuPt15to20->Scale(glbScale*scale_QCDMuPt15to20);
    cout << "histoQCDMuPt15to20=" << histoQCDMuPt15to20->Integral() << endl;

    
    TH1F *histoQCDMuPt20to30 = (TH1F*) file_QCDMuPt20to30->Get(plotName);
    TH1F *L2histoQCDMuPt20to30 = (TH1F*) file_QCDMuPt20to30->Get("nbL3muons");
    float scale_QCDMuPt20to30 = 558528000.*0.0053/L2histoQCDMuPt20to30->GetEntries();
    histoQCDMuPt20to30->Scale(glbScale*scale_QCDMuPt20to30);
    cout << "histoQCDMuPt20to30=" << histoQCDMuPt20to30->Integral() << endl;

    histoQCDMuPt20to30->Add(histoQCDMuPt15to20);
    
    TH1F *histoQCDMuPt30to50 = (TH1F*) file_QCDMuPt30to50->Get(plotName);
    TH1F *L2histoQCDMuPt30to50 = (TH1F*) file_QCDMuPt30to50->Get("nbL3muons");
    float scale_QCDMuPt30to50 = 139803000.*0.01182/L2histoQCDMuPt30to50->GetEntries();
    histoQCDMuPt30to50->Scale(glbScale*scale_QCDMuPt30to50);
    cout << "histoQCDMuPt30to50=" << histoQCDMuPt30to50->Integral() << endl;

    histoQCDMuPt30to50->Add(histoQCDMuPt20to30);
    
    TH1F *histoQCDMuPt50to80 = (TH1F*) file_QCDMuPt50to80->Get(plotName);
    TH1F *L2histoQCDMuPt50to80 = (TH1F*) file_QCDMuPt50to80->Get("nbL3muons");
    float scale_QCDMuPt50to80 = 19222500.*0.02276/L2histoQCDMuPt50to80->GetEntries();
    histoQCDMuPt50to80->Scale(glbScale*scale_QCDMuPt50to80);
    cout << "histoQCDMuPt50to80=" << histoQCDMuPt50to80->Integral() << endl;
    histoQCDMuPt50to80->Add(histoQCDMuPt30to50);
    
    TH1F *histoQCDMuPt80to120 = (TH1F*) file_QCDMuPt80to120->Get(plotName);
    TH1F *L2histoQCDMuPt80to120 = (TH1F*) file_QCDMuPt80to120->Get("nbL3muons");
    float scale_QCDMuPt80to120 = 2758420.*0.03844/L2histoQCDMuPt80to120->GetEntries();
    histoQCDMuPt80to120->Scale(glbScale*scale_QCDMuPt80to120);
    cout << "histoQCDMuPt80to120=" << histoQCDMuPt80to120->Integral() << endl;

    histoQCDMuPt80to120->Add(histoQCDMuPt50to80);
    
    cout << "histoQCD=" << histoQCDMuPt80to120->Integral() << endl;

    
    TH1F *histoW = (TH1F*) file_W->Get(plotName);
    TH1F *L2histoW = (TH1F*) file_W->Get("nbL3muons");
    float scale_W = 60290./L2histoW->GetEntries();
    histoW->Scale(glbScale*scale_W);
    cout << "integraleW=" << histoW->Integral() << endl;

    histoW->Add(histoQCDMuPt80to120);

    TH1F *histoDY = (TH1F*) file_DY->Get(plotName);
    TH1F *L2histoDY = (TH1F*) file_DY->Get("nbL3muons");
    float scale_DY = 20000./L2histoDY->GetEntries();
    histoDY->Scale(glbScale*scale_DY);
    cout << "integraleDY=" << histoDY->Integral() << endl;

    histoDY->Add(histoW);
    
    cout << "fullRate=" << histoDY->Integral() << endl;

    TH1F *histodata = (TH1F*) file_data->Get(plotName);
    int nbEntriesData  = histodata->Integral();
    
    float fullScale = nbEntriesData/histoDY->Integral();
    
    cout << "ratio=" << fullScale << endl;
    
    //rescale everyboby
   /* histoQCDMuPt15to20->Scale(fullScale);
    histoQCDMuPt20to30->Scale(fullScale);
    histoQCDMuPt30to50->Scale(fullScale);
    histoQCDMuPt50to80->Scale(fullScale);
    histoQCDMuPt80to120->Scale(fullScale);
    histoW->Scale(fullScale);
    histoDY->Scale(fullScale);*/

    
   TCanvas *c0 = new TCanvas("coucou","c0",600,600);
    c0->SetFillColor(0);
    
    float theMaximum = 6./4*theMax(histoDY->GetMaximum(), histodata->GetMaximum());
    
    histoDY->GetXaxis()->SetTitle(xAxis);
    histoDY->GetYaxis()->SetTitle(yAxis);
    histoDY->SetMinimum(0);
    histoDY->SetMaximum(theMaximum);
    histoDY->SetFillColor(kGreen+1);
    histoDY->Draw();
    
    histoW->SetFillColor(kBlue-4);
    histoW->Draw("same");
    
    histoQCDMuPt80to120->SetFillColor(kRed-9);
    histoQCDMuPt80to120->Draw("same");
    
    histoQCDMuPt50to80->SetFillColor(kRed-7);
    histoQCDMuPt50to80->Draw("same");
    
    histoQCDMuPt30to50->SetFillColor(kRed);
    histoQCDMuPt30to50->Draw("same");
    
    histoQCDMuPt20to30->SetFillColor(kRed+2);
    histoQCDMuPt20to30->Draw("same");

    histoQCDMuPt15to20->SetFillColor(kRed+3);
    histoQCDMuPt15to20->Draw("same");
    

    
    histodata->Draw("same:E1");
    
    TLegend *legend = new TLegend(0.46,0.68,0.84,0.88);
    legend->SetFillColor(0);
    legend->SetLineColor(0);
    legend->AddEntry(histodata,"data","LP");
    legend->AddEntry(histoDY,"DY","F");
    legend->AddEntry(histoW,"W","F");
    legend->AddEntry(histoQCDMuPt30to50,"QCD Mu Enriched","F");
    legend->Draw();

    
    c0->Print(outDir+"/"+plotName+".png");
    
    delete c0;
    
    TCanvas *c0Log = new TCanvas("coucou","c0",600,600);
    c0Log->SetFillColor(0);
    c0Log->SetLogy();
    
    float theMaximumLog = 1000*theMax(histoDY->GetMaximum(), histodata->GetMaximum());
    
    histoDY->GetXaxis()->SetTitle(xAxis);
    histoDY->GetYaxis()->SetTitle(yAxis);
    histoDY->SetMinimum(0.01);
    histoDY->SetMaximum(theMaximumLog);
    histoDY->SetFillColor(kGreen+1);
    histoDY->Draw();
    
    histoW->SetFillColor(kBlue-4);
    histoW->Draw("same");
    
    histoQCDMuPt80to120->SetFillColor(kRed-9);
    histoQCDMuPt80to120->Draw("same");
    
    histoQCDMuPt50to80->SetFillColor(kRed-7);
    histoQCDMuPt50to80->Draw("same");
    
    histoQCDMuPt30to50->SetFillColor(kRed);
    histoQCDMuPt30to50->Draw("same");
    
    histoQCDMuPt20to30->SetFillColor(kRed+2);
    histoQCDMuPt20to30->Draw("same");
    
    histoQCDMuPt15to20->SetFillColor(kRed+3);
    histoQCDMuPt15to20->Draw("same");
    
    
    
    histodata->Draw("same:E1");
    TLegend *legendLog = new TLegend(0.46,0.68,0.84,0.88);
    legendLog->SetFillColor(0);
    legendLog->SetLineColor(0);
    legendLog->AddEntry(histodata,"data","LP");
    legendLog->AddEntry(histoDY,"DY","F");
    legendLog->AddEntry(histoW,"W","F");
    legendLog->AddEntry(histoQCDMuPt30to50,"QCD Mu Enriched","F");
    legendLog->Draw();
    c0Log->Print(outDir+"/"+plotName+"_log.png");
    

    
    delete c0Log;


}

void drawThePlots(){
    gStyle->SetOptStat(0);
    float scale = 11.52/660+2.44/1000;//0.5e-2*100;
   // float scale = 0.073e-2/12.;
    
 /*   makeThePlot(scale, "ptL2", "p_{T} L2 muon","", "plotsL2");
    makeThePlot(scale, "etaL2", "#eta L2 muon","", "plotsL2");
    makeThePlot(scale, "phiL2", "#phi L2 muon","", "plotsL2");
    makeThePlot(scale, "dxyL2", "d_{xy} L2 muon","", "plotsL2");
    makeThePlot(scale, "dzL2", "d_{z} L2 muon","", "plotsL2");
    makeThePlot(scale, "nbStationsWithHits", "nb station with hits","", "plotsL2");
    makeThePlot(scale, "nbStationsWithHitsCSC", "nb station with hits CSC","", "plotsL2");
    makeThePlot(scale, "nbStationsWithHitsDT", "nb station with hits DT","", "plotsL2");
    makeThePlot(scale, "nbValidHits", "nb valid hits","", "plotsL2");

    scale = 11.52/66+2.44/100;
    
    makeThePlot(scale, "ptL3", "p_{T} L3 muon","", "plotsL3");
    makeThePlot(scale, "etaL3", "#eta L3","", "plotsL3");
    makeThePlot(scale, "phiL3", "#phi L3","", "plotsL3");
    makeThePlot(scale, "drL3", "dr L3","", "plotsL3");
    makeThePlot(scale, "dzL3", "dz L3","", "plotsL3");
    makeThePlot(scale, "dxyL3", "dxy L3","", "plotsL3");
    makeThePlot(scale, "Chi2L3", "#chi^{2} L3","", "plotsL3");
    makeThePlot(scale, "L3pfECAL", "pF ECAL isolation","","plotsL3");
    makeThePlot(scale, "L3pfECALrho", "pF ECAL isolation rho corrected","","plotsL3");
    makeThePlot(scale, "L3pfECALrhoRelat", "relat pF ECAL isolation rho corrected","","plotsL3");
    makeThePlot(scale, "L3pfHCAL", "pF HCAL isolation","","plotsL3");
    makeThePlot(scale, "L3pfHCALrho", "pF HCAL isolation rho corrected","","plotsL3");
    makeThePlot(scale, "L3pfHCALrhoRelat", "relat pF HCAL isolation rho corrected","","plotsL3");
    makeThePlot(scale, "L3TrkIso", "tracker isolation","","plotsL3");
    makeThePlot(scale, "L3rho", "#rho","","plotsL3");*/
    
    scale = 11.52/66+2.44/100;
    
    makeThePlot(scale, "ptL3passingL3filter", "p_{T} L3 muon","", "plotsL3Passing");
    makeThePlot(scale, "etaL3passingL3filter", "#eta L3","", "plotsL3Passing");
    makeThePlot(scale, "phiL3passingL3filter", "#phi L3","", "plotsL3Passing");
    makeThePlot(scale, "drL3passingL3filter", "dr L3","", "plotsL3Passing");
    makeThePlot(scale, "dzL3passingL3filter", "dz L3","", "plotsL3Passing");
    makeThePlot(scale, "dxyL3passingL3filter", "dxy L3","", "plotsL3Passing");
    makeThePlot(scale, "Chi2L3passingL3filter", "#chi^{2} L3","", "plotsL3Passing");
    makeThePlot(scale, "L3pfECALpassingL3filter", "pF ECAL isolation","","plotsL3Passing");
    makeThePlot(scale, "L3pfECALrhopassingL3filter", "pF ECAL isolation rho corrected","","plotsL3Passing");
    makeThePlot(scale, "L3pfECALrhoRelatpassingL3filter", "relat pF ECAL isolation rho corrected","","plotsL3Passing");
   makeThePlot(scale, "L3pfHCALpassingL3filter", "pF HCAL isolation","","plotsL3Passing");
    makeThePlot(scale, "L3pfHCALrhopassingL3filter", "pF HCAL isolation rho corrected","","plotsL3Passing");
    makeThePlot(scale, "L3pfHCALrhoRelatpassingL3filter", "relat pF HCAL isolation rho corrected","","plotsL3Passing");
    makeThePlot(scale, "L3TrkIsopassingL3filter", "tracker isolation","","plotsL3Passing");
    makeThePlot(scale, "L3rhopassingL3filter", "#rho","","plotsL3Passing");
    
  /*  scale = 11.52/12+2.44/20;
    makeThePlot(scale, "massL3passingTnP", "mass","","plotsL3TnP");
    makeThePlot(scale, "ptL3passingTnP", "p_{T} L3 muon","","plotsL3TnP");
    makeThePlot(scale, "etaL3passingTnP", "#eta L3","","plotsL3TnP");
    makeThePlot(scale, "phiL3", "#phi L3","","plotsL3TnP");
    makeThePlot(scale, "drL3passingTnP", "dr L3","","plotsL3TnP");
    makeThePlot(scale, "dzL3passingTnP", "dz L3","","plotsL3TnP");
    makeThePlot(scale, "dxyL3passingTnP", "dxy L3","","plotsL3TnP");
    makeThePlot(scale, "Chi2L3passingTnP", "#chi^{2} L3","","plotsL3TnP");
    makeThePlot(scale, "L3pfECALpassingTnP", "pF ECAL isolation","","plotsL3TnP");
    makeThePlot(scale, "L3pfECALrhopassingTnP", "pF ECAL isolation rho corrected","","plotsL3TnP");
    makeThePlot(scale, "L3pfECALrhoRelatassingTnP", "relat pF ECAL isolation rho corrected","","plotsL3TnP");
    makeThePlot(scale, "L3pfHCALpassingTnP", "pF HCAL isolation","","plotsL3TnP");
    makeThePlot(scale, "L3pfHCALrhopassingTnP", "pF HCAL isolation rho corrected","","plotsL3TnP");
    makeThePlot(scale, "L3pfHCALrhoRelatpassingTnP", "relat pF HCAL isolation rho corrected","","plotsL3TnP");
    makeThePlot(scale, "L3TrkIsopassingTnP", "tracker isolation","","plotsL3TnP");
    makeThePlot(scale, "L3rhopassingTnP", "#rho","","plotsL3TnP");*/
    
}