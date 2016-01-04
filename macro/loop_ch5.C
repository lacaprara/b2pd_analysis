#include  "B0_ch5.C"
#include  "plot_ch.C"


void loop_ch5(int nev=100000) {

  TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-3pi2pi_KS-pi0pi0_output_signal.root");

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch5 B0(B0t);
  B0.Loop(nev);

  plot_ch();
}

