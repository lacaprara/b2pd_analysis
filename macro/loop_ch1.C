#include  "B0_ch1.C"
#include  "plot_ch.C"


void loop_ch1(int nev=10000) {

  //TFile *_file0 = TFile::Open("../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root");
  TFile *_file0 = TFile::Open("../root_files/ch1/uubar/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal_0.root");

  TTree* B0t=(TTree*) _file0->Get("B0"); 
  B0_ch1 B0(B0t);
  B0.Loop(nev);

  plot_ch(1);
}

