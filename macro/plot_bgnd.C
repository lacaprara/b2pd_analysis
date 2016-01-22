#include <vector>

bool plotAllDistributions=1;
bool plotGoldDistributions=1;

struct plotInfo {
  plotInfo() {}

  plotInfo(const TString& aName, bool aLog, const float& aCutLow, const float& aCutHigh, bool aGold):
    name(aName), log(aLog), cutLow(aCutLow), cutHigh(aCutHigh), gold(aGold) {}

  plotInfo(const plotInfo& o):
    name(o.name), log(o.log), cutLow(o.cutLow), cutHigh(o.cutHigh), gold(o.gold) {}
  TString name;
  bool log;
  float cutLow, cutHigh;
  bool gold;
};

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


void getWhatToPlot(int channel, vector<plotInfo>& result) {
  switch(channel) {
    case 1:
      result.push_back(plotInfo("hMbc"          ,false,5.25 ,5.29 ,true));
      result.push_back(plotInfo("hDeltaE"       ,false,-0.1 ,0.1  ,true));
      result.push_back(plotInfo("hMinvEta"      ,false,0.45 ,0.57 ,true));
      result.push_back(plotInfo("hMinvEtaP"     ,false,0.93 ,0.98 ,true));
      result.push_back(plotInfo("hMinvK0S"      ,false,0.48 ,0.52 ,true));
      result.push_back(plotInfo("hPIDpi"        ,true ,0.20 ,1.00 ,true));
      result.push_back(plotInfo("hD0pi"         ,true ,-0.08,0.08 ,false));
      result.push_back(plotInfo("hZ0pi"         ,true ,-0.1 ,+0.1 ,false));
      result.push_back(plotInfo("hNPxdHitspi"   ,false,1    ,4    ,false));
      result.push_back(plotInfo("hVtxPValueK0S" ,true ,1e-5 ,1    ,false));
      result.push_back(plotInfo("hVtxPValueEta" ,true ,1e-5 ,1    ,false));
      result.push_back(plotInfo("hVtxPValueEtaP",true ,1e-5 ,1    ,false));
      result.push_back(plotInfo("hVtxPValueB0"  ,true ,1e-5 ,1    ,false));
      break;
    case 2:
      result.push_back(plotInfo("hMbc",           false, 5.25, 5.29,  true));
      result.push_back(plotInfo("hDeltaE",        false, -0.15,0.25,  true));
      result.push_back(plotInfo("hMinvEta",       false, 0.48, 0.57,  true));
      result.push_back(plotInfo("hMinvEtaP",      false, 0.93, 0.98,  true));
      result.push_back(plotInfo("hMinvPi0",       false, 0.1 , 0.15,  true));
      result.push_back(plotInfo("hMinvK0S",       false, 0.42, 0.52,  true));
      result.push_back(plotInfo("hPIDpi",         true,  0.2,  1.0,   false));
      result.push_back(plotInfo("hD0pi",          true,  -0.08,+0.08, false));
      result.push_back(plotInfo("hZ0pi",          true,  -0.15,+0.15, false));
      result.push_back(plotInfo("hNPxdHitspi",    false, 1,    4,     false));
      result.push_back(plotInfo("hVtxPValueEta",  true,  1E-3, 1E-3,  false));
      result.push_back(plotInfo("hVtxPValueEtaP", true,  1E-3, 1E-3,  false));
      result.push_back(plotInfo("hVtxPValueB0",   true,  1E-3, 1E-3,  false));
      break;
    case 3:
      break;
    case 4:
      result.push_back(plotInfo("hMbc",                 false, 5.25,  5.29,  true));
      result.push_back(plotInfo("hDeltaE",              false, -0.15, 0.15,  true));
      result.push_back(plotInfo("hMinvEta",             false, 0.52,  0.57,  true));
      result.push_back(plotInfo("hMinvEtaP",            false, 0.93,  0.98,  true));
      result.push_back(plotInfo("hMinvPi0",             false, 0.1 ,  0.15,  true));
      result.push_back(plotInfo("hMinvK0S",             false, 0.48,  0.52,  true));
      result.push_back(plotInfo("hPIDpi",               true, 0.2,   1.0,   false));
      result.push_back(plotInfo("hD0pi",                true, -0.08, +0.08, false));
      result.push_back(plotInfo("hZ0pi",                true, -0.15, +0.15, false));
      result.push_back(plotInfo("hNPxdHitspi",          true, 1,     4,     false));
      result.push_back(plotInfo("hVtxPValueEta",        true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueEtaP",       true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueB0",         true, 1E-3,  1E-3,  false));
      break;
    case 5:
      result.push_back(plotInfo("hMbc",                 false, 5.25,  5.29,  true));
      result.push_back(plotInfo("hDeltaE",              false, -0.15, 0.25,  true));
      result.push_back(plotInfo("hMinvEta",             false, 0.52,  0.57,  true));
      result.push_back(plotInfo("hMinvEtaP",            false, 0.93,  0.98,  true));
      result.push_back(plotInfo("hMinvPi0",             false, 0.1 ,  0.15,  true));
      result.push_back(plotInfo("hMinvK0S",             false, 0.40,  0.52,  true));
      result.push_back(plotInfo("hPIDpi",               true, 0.2,   1.0,   false));
      result.push_back(plotInfo("hD0pi",                true, -0.08, +0.08, false));
      result.push_back(plotInfo("hZ0pi",                true, -0.15, +0.15, false));
      result.push_back(plotInfo("hNPxdHitspi",          true, 1,     4,     false));
      result.push_back(plotInfo("hVtxPValueEta",        true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueEtaP",       true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueB0",         true, 1E-3,  1E-3,  false));
      break;
    case 6:
      break;
  }
}


void channel(int ch, TCanvas* c, float x=0.5, float y=0.96) {
  TLatex* tch=new TLatex();
  tch->SetTextSize(0.04);
  tch->SetTextAlign(21);
  TString what;
  switch(ch){
    case 1:
      what="B^{0}#rightarrow#eta'( #eta(#gamma#gamma) #pi^{+}#pi^{-}) K^{0}_{S}(#pi^{+}#pi^{-})";
      break;
    case 2:
      what= "B^{0}#rightarrow#eta'( #eta(#gamma#gamma) #pi^{+}#pi^{-}) K^{0}_{S}(#pi^{0}#pi^{0})";
      break;
    case 4:
      what = "B^{0}#rightarrow#eta'( #eta(#pi^{+}#pi^{-}#pi^{0}) #pi^{+}#pi^{-}) K^{0}_{S}(#pi^{+}#pi^{-})";
      break;
    case 5:
      what = "B^{0}#rightarrow#eta'( #eta(#pi^{+}#pi^{-}#pi^{0}) #pi^{+}#pi^{-}) K^{0}_{S}(#pi^{0}#pi^{0})";
      break;
    default:
      what="what??";
      break;
  }
  c->cd();
  TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
  newpad->SetFillStyle(4000);
  newpad->Draw();
  newpad->cd();
  tch->DrawLatexNDC(x,y,what);
}

void plot_bgnd(int ch=2) {
  vector<fileInfo> files;
  files.push_back(fileInfo("u#bar{u}", TFile::Open(Form("Histo_ch%d_uubar.root"  ,ch)), kRed));
  files.push_back(fileInfo("d#bar{d}", TFile::Open(Form("Histo_ch%d_ddbar.root"  ,ch)), kGreen));
  files.push_back(fileInfo("s#bar{s}", TFile::Open(Form("Histo_ch%d_ssbar.root"  ,ch)), kBlue));
  files.push_back(fileInfo("c#bar{c}", TFile::Open(Form("Histo_ch%d_ccbar.root"  ,ch)), kOrange));
  // files.push_back(fileInfo("mixed",    TFile::Open(Form("Histo_ch%d_mixed.root"  ,ch)), kViolet));
  // files.push_back(fileInfo("charged",  TFile::Open(Form("Histo_ch%d_charged.root",ch)), kGray));

  gStyle->SetPadTopMargin(0.10);
  gStyle->SetOptStat(0);
  gStyle->SetTitleSize(.5,"XYZ");

  TLatex* tt=new TLatex();
  tt->SetTextSize(0.05);

  vector<plotInfo> plotInfos;
  getWhatToPlot(ch, plotInfos);

  if (plotAllDistributions) {
    TLine* tl=new TLine();
    tl->SetLineWidth(2);
    tl->SetLineColor(kRed+2);
    int nHisto=plotInfos.size();

    int nX=3, nY=1;
    float sizeX=900,sizeY=300;
    const int nCanvas(nHisto/(nX*nY)+1);

    TLegend* tleg=new TLegend(0.8,0.6,0.96,0.89);
    tleg->SetFillStyle(0);

    TCanvas* c0[nCanvas];
    int iCan=0;
    c0[iCan]=new TCanvas(Form("c0%d",iCan),"Before Cuts",sizeX,sizeY);
    c0[iCan]->Divide(nX,nY);
    int i=0;
    for (vector<plotInfo>::const_iterator h=plotInfos.begin(); h!=plotInfos.end(); ++h) {
      THStack hs;
      TString xTitle;
      for (vector<fileInfo>::const_iterator f=files.begin(); f!=files.end(); ++f) {
        c0[iCan]->cd(i+1);
        (f->file)->cd("AllCandidates");
        TH1* htmp=(TH1F*)gDirectory->Get(h->name);
        float ymin=0;
        if (h->log) {
          gPad->SetLogy();
          ymin=10;
        }
        if (htmp) {
          htmp->GetXaxis()->SetTitleOffset(.7);
          htmp->GetXaxis()->SetTitleSize(0.08);
          htmp->SetFillColor(f->color);
          htmp->SetMinimum(ymin);
          hs.Add(htmp);
          xTitle=htmp->GetXaxis()->GetTitle();
          if (i==0) {
            tleg->AddEntry(htmp,f->name,"f");
          }
        }
      }
      hs.DrawClone();
      tt->SetTextAlign(32);
      tt->DrawLatexNDC(0.95,.03,xTitle);

      tl->DrawLine(h->cutLow,ymin,h->cutLow,htmp->GetMaximum()*1.05);
      tl->DrawLine(h->cutHigh,ymin,h->cutHigh,htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
      ++i;

      // Check if I need a new canvas
      if (i>nX*nY) {
        channel(ch,c0[iCan]);
        c0[iCan]->Print(Form("Ch%d_all_distr%d_bgnd.pdf",ch,iCan));
        c0[iCan]->Print(Form("Ch%d_all_distr%d_bgnd.png",ch,iCan));
        iCan++;
        c0[iCan]=new TCanvas(Form("c0%d",iCan),"Before Cuts",sizeX,sizeY);
        c0[iCan]->Divide(nX,nY);
        tleg->Clear();
        i=0;
      }
    }
    channel(ch,c0[iCan]);
    c0[iCan]->Print(Form("Ch%d_all_distr%d_bgnd.pdf",ch,iCan));
    c0[iCan]->Print(Form("Ch%d_all_distr%d_bgnd.png",ch,iCan));
  }


  if(plotGoldDistributions) {

    TLine* tl=new TLine();
    tl->SetLineWidth(2);
    tl->SetLineColor(kRed+2);
    TCanvas* c1=new TCanvas("c1","Before Cuts",900,600);
    c1->Divide(3,2);
    TLegend* tleg=new TLegend(0.8,0.6,0.96,0.89);
    tleg->SetFillStyle(0);
    int i=0;
    for (vector<plotInfo>::const_iterator h=plotInfos.begin(); h!=plotInfos.end(); ++h) {
      if (!h->gold) continue;
      THStack hs;
      TString xTitle;
      for (vector<fileInfo>::const_iterator f=files.begin(); f!=files.end(); ++f) {

        c1->cd(i+1);
        (f->file)->cd("AllCandidates");
        TH1* htmp=(TH1F*)gDirectory->Get(h->name);
        float ymin=0;
        if (h->log) {
          gPad->SetLogy();
          ymin=10;
        }
        if (htmp) {
          htmp->SetFillColor(f->color);
          htmp->GetXaxis()->SetTitleOffset(.7);
          htmp->GetXaxis()->SetTitleOffset(.7);
          htmp->GetXaxis()->SetTitleSize(0.08);
          xTitle=htmp->GetXaxis()->GetTitle();
          hs.Add(htmp);
          if (i==0) {
            cout << "Adding " << f->name << endl;
            tleg->AddEntry(htmp,f->name,"f");
          }
        }
      }
      hs.DrawClone();
      tt->SetTextAlign(32);
      tt->DrawLatexNDC(0.95,.03,xTitle);

      tl->DrawLine(h->cutLow,ymin,h->cutLow,htmp->GetMaximum()*1.05);
      tl->DrawLine(h->cutHigh,ymin,h->cutHigh,htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
      ++i;
    }
    channel(ch,c1);
    c1->Print(Form("Ch%d_distr_bgnd.pdf",ch));
    c1->Print(Form("Ch%d_distr_bgnd.png",ch));


  }

}

void plotAll() {
  plot_bgnd(1);
  plot_bgnd(2);
  plot_bgnd(4);
  plot_bgnd(5);
}
