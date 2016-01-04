#include  "B0_ch4.C"
#include  "plot_ch.C"


void loop_ch4(int nev=100000) {

  TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-3pi2pi_KS-pi+pi-_output_signal.root");

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch4 B0(B0t);
  B0.Loop(nev);

  plot_ch(4);
}

