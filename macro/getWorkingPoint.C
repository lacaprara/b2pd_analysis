#include <vector>

struct fileInfo {
  fileInfo() {}

  fileInfo(const TString& aName, TFile* aFile, int aColor) :
    name(aName), file(aFile), color(aColor) {}

  fileInfo(const fileInfo& o):
    name(o.name), file(o.file), color(o.color) {}
  TString name;
  TFile* file;
  int color;
};

void getWorkingPoint(int ch=1) {
  const Int_t nq = 20;
  Double_t xq[nq];  // position where to compute the quantiles in [0,1]
  Double_t yq[nq];  // array to contain the quantiles
  Double_t yq_bk[nq];  // array to contain the quantiles
  for (Int_t i=0;i<nq;i++) xq[i] = Float_t(i+1)/nq;

  TFile *_file0 = TFile::Open("Histo_ch1_signal_iptubeK0.root");
  _file0->cd("BestCandidates");
  TH1F* hBDT=(TH1F*)gDirectory->Get("hBDT");
  hBDT->GetQuantiles(nq,yq,xq);

  //show the original histogram in the top pad
  TCanvas *c1 = new TCanvas("c1","demo quantiles",10,10,700,900);
  c1->Divide(1,2);

  vector<fileInfo> files;
  files.push_back(fileInfo("mixed",    TFile::Open(Form("Histo_ch%d_mixed_iptubeK0.root"  ,ch)), kViolet));
  files.push_back(fileInfo("charged",  TFile::Open(Form("Histo_ch%d_charged_iptubeK0.root",ch)), kGray));
  files.push_back(fileInfo("u#bar{u}", TFile::Open(Form("Histo_ch%d_uubar_iptubeK0.root"  ,ch)), kRed));
  files.push_back(fileInfo("d#bar{d}", TFile::Open(Form("Histo_ch%d_ddbar_iptubeK0.root"  ,ch)), kGreen));
  files.push_back(fileInfo("s#bar{s}", TFile::Open(Form("Histo_ch%d_ssbar_iptubeK0.root"  ,ch)), kBlue));
  files.push_back(fileInfo("c#bar{c}", TFile::Open(Form("Histo_ch%d_ccbar_iptubeK0.root"  ,ch)), kOrange));

  TH1F* hBDT_bk=(TH1F*)hBDT->Clone();
  hBDT_bk->Reset();
  for (vector<fileInfo>::const_iterator f=files.begin(); f!=files.end(); ++f) {
    // only continuum
    if (!(f->name).Contains("bar")) continue;
    cout << "Adding  " << f->name << endl;
    (f->file)->cd("BestCandidates");
    TH1* htmp=(TH1F*)gDirectory->Get("hBDT");
    hBDT_bk->Add(htmp);
  }
  hBDT_bk->GetQuantiles(nq,yq_bk,xq);

  c1->cd(1);
  hBDT_bk->SetLineColor(kRed);
  hBDT_bk->SetLineWidth(2);
  hBDT_bk->Scale(1./hBDT_bk->Integral());
  hBDT_bk->Draw();
  c1->cd(1);
  hBDT->Scale(1./hBDT->Integral());
  hBDT->SetLineWidth(2);
  hBDT->Draw("same");
  // show the quantiles in the bottom pad
  c1->cd(2);
  gPad->SetGrid();
  TGraph *gr_bk = new TGraph(nq,xq,yq_bk);
  gr_bk->SetLineColor(kRed);
  gr_bk->SetMarkerColor(kRed);
  gr_bk->SetMarkerStyle(22);
  gr_bk->Draw("alp");
  // show the quantiles in the bottom pad
  c1->cd(2);
  gPad->SetGrid();
  TGraph *gr = new TGraph(nq,xq,yq);
  gr->SetMarkerStyle(21);
  gr->Draw("lp");

  for (Int_t i=0;i<nq;i++) {
    cout << "Bin " <<  hBDT_bk->GetXaxis()->FindBin(yq[i]) << endl;
    cout << "Signal BDT=" << yq[i] << " eff: " << xq[i] << " background " << hBDT_bk->Integral(1, hBDT_bk->GetXaxis()->FindBin(yq[i]))/hBDT_bk->Integral() << endl;
  }
  for (Int_t i=0;i<nq;i++) 
    cout << "Baackground BDT=" << yq_bk[i] << " eff: " << xq[i] << endl;

}
