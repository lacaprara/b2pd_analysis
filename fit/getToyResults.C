// #include <vector>
// #include <TString.h>
// #include <RooRealVar.h>
// #include <TFile.h>
// using namespace std;

void getOneToyResults(TString inFile, TH1F *hRes_dtSig_S, TH1F *hRes_dtSig_C, TH1F* hRes_nSig) {

  // declare histograms and variables
  RooRealVar *rrv_dtSig_S;
  RooRealVar *rrv_dtSig_C;
  RooRealVar *rrv_nSig;

  TFile *inF = new TFile(inFile);
  inF->cd();

  RooDataSet *toyResults = (RooDataSet*)inF->Get("toyResults");
  //toyResults->Print("v");
  int nToys = toyResults->sumEntries();

  cout << "nToys = " << nToys << endl;

  for (int iToy = 0 ; iToy < nToys ; iToy++) {

    if (iToy==0) {
      RooArgSet* args= (RooArgSet*)toyResults->get(iToy);
      TIterator* iter = args->createIterator();
      while (TObject* var = iter->Next()) {
        cout << var->GetName() << endl;
      }
    }

    rrv_dtSig_S = (RooRealVar*)toyResults->get(iToy)->find("dtSig_S");
    rrv_dtSig_C = (RooRealVar*)toyResults->get(iToy)->find("dtSig_C");
    rrv_nSig = (RooRealVar*)toyResults->get(iToy)->find("nSig");


    // rrv_dtSig_S->Print();
    // rrv_dtSig_S->getValV();
    //cout << "val " << rrv_dtSig_S->getValV() << " " <<  rrv_dtSig_S->getAsymErrorLo()  << " " << rrv_dtSig_S->getAsymErrorHi() << endl;
    hRes_dtSig_S->Fill(rrv_dtSig_S->getValV());
    hRes_dtSig_C->Fill(rrv_dtSig_C->getValV());
    hRes_nSig->Fill(rrv_nSig->getValV());

  }





  return;

}

void getToyResults(TString outFile="results.root") {

  gStyle->SetOptStat(2220);
  gStyle->SetStatW(0.4);
  gStyle->SetStatFormat("6.3g");

  gROOT->Reset();

  TFile *outF = new TFile(outFile, "recreate");
  outF->cd();

  TH1F *hRes_dtSig_S = new TH1F("hRes_dtSig_S", "Toy results - dtSig_S", 50, -.2, 1.6);
  TH1F *hRes_dtSig_C = new TH1F("hRes_dtSig_C", "Toy results - dtSig_C", 50, -0.7, 0.7);
  TH1F *hRes_nSig = new TH1F("hRes_nSig", "Toy results - nSig", 100, 0, 800);

  int ch=1;
  //const char* what="";
  const char* what="_iptubeK0_Loose";
  TString fileName(Form("results/EtaPK0_ch%d%s.mlFitter_Config.toyPlot.ToyAct.root",ch,what));
  int nSig=390;

  TString suffix(Form("ch%d%s",ch,what));
  //vector<TString> files;
  //files.push_back(TString("results/EtaPK0_ch1_iptubeK0_Loose.mlFitter_Config.toyPlot.ToyAct.root"));
  //files.push_back(TString("results/EtaPK0_ch1_iptubeK0_Tight.mlFitter_Config.toyPlot.ToyAct.root"));

  //files.push_back(TString("results/EtaPK0_ch1.mlFitter_Config_300fbinv.toyPlot.ToyAct.root"));
  //files.push_back(TString("results/EtaPK0_ch1.mlFitter_Config_3000fbinv.toyPlot.ToyAct.root"));
  //files.push_back(TString("results/EtaPK0_ch1.mlFitter_Config_1000fbinv.toyPlot.ToyAct.root"));

  //files.push_back(TString("results/EtaPK0_ch4_iptubeK0.mlFitter_Config.toyPlot.ToyAct.root"));
  //files.push_back(TString("results/EtaPK0_ch4.mlFitter_Config.toyPlot.ToyAct.root"));

  // for (auto file : files) {
  //   cout << "file " << file << endl;

  //   getOneToyResults(file,hRes_dtSig_S,hRes_dtSig_C,hRes_nSig);
  // }

  getOneToyResults(fileName,hRes_dtSig_S,hRes_dtSig_C,hRes_nSig);
  
    TLine* tl=new TLine();
    tl->SetLineWidth(5);
    tl->SetLineColor(kRed+2);

  outF->cd();
  hRes_dtSig_S->Write();
  hRes_dtSig_C->Write();
  hRes_nSig->Write();

  TCanvas* cS=new TCanvas("cS","cS",600,600);
  TCanvas* cC=new TCanvas("cC","cC",600,600);
  TCanvas* cN=new TCanvas("cN","cN",600,600);
  cS->cd();
  hRes_dtSig_S->DrawCopy();
  tl->DrawLine(0.7,0,0.7,hRes_dtSig_S->GetMaximum()*0.80);

  cS->Print(Form("hRes_dtSig_S_%s.pdf",suffix.Data()));
  cout << "S " << hRes_dtSig_S->GetMean() << " \\pm " << hRes_dtSig_S->GetRMS()/sqrt(hRes_dtSig_S->GetEntries()) << " \\sigma " << hRes_dtSig_S->GetRMS()<< endl;

  cC->cd();
  hRes_dtSig_C->DrawCopy();
  tl->DrawLine(0.0,0,0.0,hRes_dtSig_C->GetMaximum()*0.80);
  cC->Print(Form("hRes_dtSig_C_%s.pdf",suffix.Data()));
  cout << "C " << hRes_dtSig_C->GetMean() << " \\pm " << hRes_dtSig_C->GetRMS()/sqrt(hRes_dtSig_C->GetEntries()) << " \\sigma " << hRes_dtSig_C->GetRMS()<< endl;

  cN->cd();
  hRes_nSig->DrawCopy();
  tl->DrawLine(nSig,0,nSig,hRes_nSig->GetMaximum()*0.80);
  cN->Print(Form("hRes_nSig_%s.pdf",suffix.Data()));
  cout << "nSig " << hRes_nSig->GetMean() << " \\pm " << hRes_nSig->GetRMS()/sqrt(hRes_nSig->GetEntries()) << " \\sigma " << hRes_nSig->GetRMS()<< endl;
  outF->Close();

}
