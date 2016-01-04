void plot() {
//  TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root");
 TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-gg2pi_KS-pi0pi0_output_signal.root");
// TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root");
// TFile *_file0 = TFile::Open("../root_files/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root");
  auto B0=(TTree*)_file0->Get("B0");
  auto cMass= new TCanvas("cMass");
  cMass->Divide(2,2);
  cMass->cd(1);
  B0->Draw("B0.B0_M");
  cMass->cd(2);
  B0->Draw("B0_eta'_M","abs(B0_eta'_M-.958)<0.002");
  cMass->cd(3);
  B0->Draw("B0_eta'_eta_M","abs(B0_eta'_eta_M-.547862)<0.00001");
  cMass->cd(4);
  B0->Draw("B0_K_S0_M");
  cMass->Print("B0_mass.pdf");

  auto c1= new TCanvas("c1");
  c1->Divide(3,2);
  c1->cd(1);
  B0->Draw("B0_deltae");
  c1->cd(2);
  B0->Draw("B0_eta'_M","abs(B0_eta'_M-.958)<0.002");
  c1->cd(3);
  B0->Draw("B0_VtxPvalue");
  c1->cd(4);
  B0->Draw("B0_mbc");
  c1->cd(5);
  B0->Draw("B0_K_S0_M");
  c1->cd(6);
  B0->Draw("B0_DeltaT","abs(B0_DeltaT)<10");
  c1->Print("B0.pdf");
}

