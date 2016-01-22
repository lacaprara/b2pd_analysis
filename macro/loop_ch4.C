#include  "B0_ch4.C"
#include  "plot_ch.C"


void loop_ch4(int nev=100000) {

  const char* what="signal";
  TFile *_file0 =
    TFile::Open(Form("../steering_files/B0_etapr-eta-3pi2pi_KS-pi+pi-_output_%s.root",what));

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch4 B0(B0t, what);
  B0.Loop(nev);

  plot_ch(4, what);
}

