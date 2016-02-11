#include  "B0_ch2.C"
#include  "plot_ch.C"


void loop_ch2(int nev=1000000) {

  const char* what="signal";
//TFile *_file0 = TFile::Open(Form("../steering_files/B0_etapr-eta-gg2pi_KS-pi0pi0_output_%s.root",what));
  TFile *_file0 = TFile::Open(Form("../root_files/ch2/B0_etapr-eta-gg2pi_KS-pi0pi0_output_%s.root",what));

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch2 B0(B0t, what);
  B0.Loop(nev);

  plot_ch(2, what);
}

