#include  "B0_ch5.C"
#include  "plot_ch.C"


void loop_ch5(int nev=-1) {

  const char* what="signal";
  TFile *_file0 = TFile::Open(Form("../root_files/ch5/B0_etapr-eta-3pi2pi_KS-pi0pi0_output_%s.root", what));

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch5 B0(B0t, what);
  B0.Loop(nev);

  plot_ch(5, what);
}

