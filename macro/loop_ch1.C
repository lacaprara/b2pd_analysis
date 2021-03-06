#include  "B0_ch1.C"
#include  "plot_ch.C"


void loop_ch1(int nev=-1) {

  TFile *_file0 = TFile::Open("../steering_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_BGx0.root");
  //TFile *_file0 = TFile::Open("../steering_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_BGx1.root");
  const char* what="signal";
  //TFile *_file0 = TFile::Open(Form("../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_output_%s.root",what));
  //TFile *_file0 = TFile::Open(Form("../steering_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_%s.root",what));
  //TFile *_file0 = TFile::Open(Form("./B0_etapr-eta-gg2pi_KS-pi+pi-_output_%s.root",what));

  TTree* All=(TTree*) _file0->Get("All"); 
  int inputEvents=0;
  if (All) inputEvents=All->GetEntries();
  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch1 B0(B0t,what);
  B0.Loop(nev);
  
  plot_ch(1,what,inputEvents);
}

