#include <vector>

bool plotAllDistributions=0;
bool plotGoldDistributions=0;
bool plotEvents=1;
bool plotDeltaT=0;
bool plotDeltaZ=0;
bool plotAsym=0;

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


void getWhatToPlot(int channel, vector<plotInfo>& result) {
  switch(channel) {
    case 1:
      result.push_back(plotInfo("hMbc"          ,false,5.25 ,5.29 ,true));
      result.push_back(plotInfo("hDeltaE"       ,false,-0.1 ,0.1  ,true));
      result.push_back(plotInfo("hMinvEta"      ,false,0.45 ,0.57 ,true));
      result.push_back(plotInfo("hMinvEtaP"     ,false,0.93 ,0.98 ,true));
      result.push_back(plotInfo("hMinvK0S"      ,true ,0.48 ,0.52 ,true));
      result.push_back(plotInfo("hPIDpi"        ,true ,0.20 ,1.00 ,true));
      result.push_back(plotInfo("hDLLKaon"      ,true ,-10.0 ,+10000.00 ,true));
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
      result.push_back(plotInfo("hMinvPi0",       true,  0.1 , 0.15,  true));
      result.push_back(plotInfo("hMinvK0S",       true,  0.42, 0.52,  true));
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
      result.push_back(plotInfo("hMbc",                 true, 5.25,  5.29,  true));
      result.push_back(plotInfo("hDeltaE",              true, -0.15, 0.15,  true));
      result.push_back(plotInfo("hMinvEta",             true, 0.52,  0.57,  true));
      result.push_back(plotInfo("hMinvEtaP",            true, 0.93,  0.98,  true));
      result.push_back(plotInfo("hMinvPi0",             true, 0.1 ,  0.15,  true));
      result.push_back(plotInfo("hMinvK0S",             true, 0.48,  0.52,  true));
      result.push_back(plotInfo("hPIDpi",               true, 0.2,   1.0,   false));
      result.push_back(plotInfo("hD0pi",                true, -0.08, +0.08, false));
      result.push_back(plotInfo("hZ0pi",                true, -0.15, +0.15, false));
      result.push_back(plotInfo("hNPxdHitspi",          true, 1,     4,     false));
      result.push_back(plotInfo("hVtxPValueEta",        true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueEtaP",       true, 1E-3,  1E-3,  false));
      result.push_back(plotInfo("hVtxPValueB0",         true, 1E-3,  1E-3,  false));
      break;
    case 5:
      result.push_back(plotInfo("hMbc",                 true, 5.25,  5.29,  true));
      result.push_back(plotInfo("hDeltaE",              true, -0.15, 0.25,  true));
      result.push_back(plotInfo("hMinvEta",             true, 0.52,  0.57,  true));
      result.push_back(plotInfo("hMinvEtaP",            true, 0.93,  0.98,  true));
      result.push_back(plotInfo("hMinvPi0",             true, 0.1 ,  0.15,  true));
      result.push_back(plotInfo("hMinvK0S",             true, 0.40,  0.52,  true));
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

/*
 * Define the fit function to determine the parameters of the 
 * sum of three Gaussians
 *
 * parameter   name                  description     
 * -------------------------------------------------------------
 * 0          norm              Normalisation.  The value of this parameter is dependent on the
 *                                              fit range and choice of histogram binning.
 * 1          mu1               mean of Gaussian 1
 * 2          sigma1            width of Gaussian 1
 * 3          mu2               mean of Gaussian 2
 * 4          sigma2            width of Gaussian 2
 * 5          mu3               mean of Gaussian 3
 * 6          sigma3            width of Gaussian 3
 * 7          frac1             fraction of Gaussian 1
 * 8          frac2             fraction of Gaussian 2
 */
Double_t fitFunc(Double_t * x, Double_t * par)
{
  Double_t PDF    = 0.0;
  Double_t g1     = 0.0;
  Double_t g2     = 0.0;
  Double_t g3     = 0.0;

  // Calculate the exponents of the Gaussians
  Double_t arg1 = (par[2] != 0.0) ? (x[0] - par[1])/(par[2]) : 0.0;
  Double_t arg2 = (par[4] != 0.0) ? (x[0] - par[3])/(par[4]) : 0.0;
  Double_t arg3 = (par[6] != 0.0) ? (x[0] - par[5])/(par[6]) : 0.0;

  // add each Gaussian contribution to the PDF
  // g1 = exp(-0.5*arg1*arg1)/(par[2]*sqrt(2.0*TMath::Pi()));
  // g2 = exp(-0.5*arg2*arg2)/(par[4]*sqrt(2.0*TMath::Pi()));
  // g3 = exp(-0.5*arg3*arg3)/(par[6]*sqrt(2.0*TMath::Pi()));
  g1 = exp(-0.5*arg1*arg1);// /(par[2]*sqrt(2.0*TMath::Pi()));
  g2 = exp(-0.5*arg2*arg2);// /(par[4]*sqrt(2.0*TMath::Pi()));
  g3 = exp(-0.5*arg3*arg3);// /(par[6]*sqrt(2.0*TMath::Pi()));
  PDF = par[0]*(par[7]*g1 + par[8]*g2 + (1-par[7]-par[8])*g3);

  return PDF;
}

void plot_ch(int ch=1, const char* appendix="signal", int inputEvents=0) {
  TFile* hfile=TFile::Open(Form("Histo_ch%d_%s.root",ch,appendix));
 // TFile* hfile=TFile::Open(Form("Histo_ch%d.root",ch,appendix));

  gStyle->SetPadTopMargin(0.10);
  gStyle->SetOptStat(0);
  gStyle->SetTitleSize(.3,"XYZ");

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

    TLegend* tleg=new TLegend(0.2,0.4,0.6,0.89);
    tleg->SetFillStyle(0);

    TCanvas* c0[nCanvas];
    int iCan=0;
    c0[iCan]=new TCanvas(Form("c0%d",iCan),"Before Cuts",sizeX,sizeY);
    c0[iCan]->Divide(nX,nY);
    int i=0;
    bool first=true;
    for (vector<plotInfo>::const_iterator h=plotInfos.begin(); h!=plotInfos.end(); ++h) {
      //cout << "iCan " << iCan << " i " << i+1 << " h " << h->name << endl;
      c0[iCan]->cd(i+1);
      hfile->cd("AllCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      float ymin=0;
      if (h->log) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->SetMinimum(ymin);
        htmp->DrawCopy();
        if (first)tleg->AddEntry(htmp,"All cands","l");
      }
      hfile->cd("AllCandidatesIsSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kYellow);
        htmp->DrawCopy("same");
        if (first)tleg->AddEntry(htmp,"MC match","f");
      }
      hfile->cd("AllGoodCandidates");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kBlue);
        htmp->DrawCopy("same");
        if (first)tleg->AddEntry(htmp,"Good cands","f");
      }
      hfile->cd("AllGoodCandidatesIsSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kGreen);
        htmp->DrawCopy("same");
        if (first)tleg->AddEntry(htmp," \" MC match","f");
      }
      // hfile->cd("BestCandidates");
      // TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      // if (htmp) {
      //   htmp->SetLineColor(kRed);
      //   htmp->DrawCopy("same");
      //   if (first)tleg->AddEntry(htmp,"Best cands","l");
      // }
      // hfile->cd("BestCandidatesIsSignal");
      // TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      // if (htmp) {
      //   htmp->SetLineColor(kViolet);
      //   htmp->DrawCopy("same");
      //   if (first)tleg->AddEntry(htmp," \" MC match","l");
      // }
      // hfile->cd("BestCandidatesIsNotSignal");
      // TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      // if (htmp) {
      //   htmp->SetLineColor(kBlack);
      //   htmp->SetLineStyle(2);
      //   htmp->DrawCopy("same");
      //   if (first)tleg->AddEntry(htmp," \" SXF","l");
      // }
      tl->DrawLine(h->cutLow,ymin,h->cutLow,htmp->GetMaximum()*1.05);
      tl->DrawLine(h->cutHigh,ymin,h->cutHigh,htmp->GetMaximum()*1.05);
      if (first) {
        tleg->Draw();
        first=false;
      }

      ++i;

      // Check if I need a new canvas
      if (i>=nX*nY) {
        channel(ch,c0[iCan]);
        c0[iCan]->Print(Form("Ch%d_all_distr%d.pdf",ch,iCan));
        c0[iCan]->Print(Form("Ch%d_all_distr%d.png",ch,iCan));
        iCan++;
        c0[iCan]=new TCanvas(Form("c0%d",iCan),"Before Cuts",sizeX,sizeY);
        c0[iCan]->Divide(nX,nY);
        i=0;
        first=true;
      }
    }
    channel(ch,c0[iCan]);
    c0[iCan]->Print(Form("Ch%d_all_distr%d.pdf",ch,iCan));
    c0[iCan]->Print(Form("Ch%d_all_distr%d.png",ch,iCan));
    // c0[iCan]->cd(14);
    // TH1* htmp=(TH1F*)hfile->Get("hNCands");
    // if (htmp) htmp->DrawCopy();
    // tt->DrawLatexNDC(0.3,0.6,Form("All cands #e: %3.2f",htmp->GetEntries()/10000.));
    // tt->DrawLatexNDC(0.3,0.5,Form("All cands multiplicity: %3.2f",htmp->GetMean()));
    // //c1->cd(16);
    // htmp=(TH1F*)hfile->Get("hNGoodCands");
    // if (htmp) {
    //   htmp->SetFillColor(kGreen);
    //   htmp->DrawCopy("same");
    //   tt->DrawLatexNDC(0.3,0.4,Form("All cands #e: %3.2f",htmp->GetEntries()/10000.));
    //   tt->DrawLatexNDC(0.3,0.3,Form("Good cands multiplicity: %3.2f",htmp->GetMean()));
    // }
    hfile->cd();
  }


  if(plotGoldDistributions) {

    TLine* tl=new TLine();
    tl->SetLineWidth(2);
    tl->SetLineColor(kRed+2);
    TCanvas* c1=new TCanvas("c1","Before Cuts",900,600);
    c1->Divide(3,2);
    TLegend* tleg=new TLegend(0.2,0.4,0.6,0.89);
    tleg->SetFillStyle(0);
    int i=0;
    for (vector<plotInfo>::const_iterator h=plotInfos.begin(); h!=plotInfos.end(); ++h) {
      if (!h->gold) continue;
      c1->cd(i+1);
      hfile->cd("AllCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      float ymin=0;
      if (h->log) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->GetXaxis()->SetTitleOffset(.7);
        htmp->GetXaxis()->SetTitleSize(0.06);
        htmp->SetMinimum(ymin);
        htmp->DrawCopy();
        if (i==0)tleg->AddEntry(htmp,"All cands","l");
      }
      hfile->cd("AllCandidatesIsSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kYellow);
        htmp->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp,"MC match","f");
      }
      hfile->cd("AllGoodCandidates");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kBlue);
        htmp->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp,"Good cands","f");
      }
      hfile->cd("AllGoodCandidatesIsSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kGreen);
        htmp->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp," \" MC match","f");
      }
      tl->DrawLine(h->cutLow,ymin,h->cutLow,htmp->GetMaximum()*1.05);
      tl->DrawLine(h->cutHigh,ymin,h->cutHigh,htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
      ++i;
    }
    channel(ch,c1);
    c1->Print(Form("Ch%d_distr.pdf",ch));
    c1->Print(Form("Ch%d_distr.png",ch));


    TCanvas* c2=new TCanvas("c2","Before Cuts",900,600);
    c2->Divide(3,2);
    tleg=new TLegend(0.2,0.6,0.6,0.89);
    i=0;
    for (vector<plotInfo>::const_iterator h=plotInfos.begin(); h!=plotInfos.end(); ++h) {
      if (!h->gold) continue;
      c2->cd(i+1);
      hfile->cd("BestCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(h->name);
      float ymin=0;
      if (h->log) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->GetXaxis()->SetTitleOffset(.7);
        htmp->GetXaxis()->SetTitleSize(0.06);
        htmp->SetMinimum(ymin);
        htmp->SetFillColor(kBlue);
        htmp->DrawCopy();
        if (i==0)tleg->AddEntry(htmp,"Best cands","f");
      }
      hfile->cd("BestCandidatesIsSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetFillColor(kGreen);
        htmp->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp," \" MC match","f");
      }
      hfile->cd("BestCandidatesIsNotSignal");
      htmp=(TH1F*)gDirectory->Get(h->name);
      if (htmp) {
        htmp->SetLineColor(kBlack);
        htmp->SetLineStyle(2);
        htmp->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp," \" SXF","l");
      }
      tl->DrawLine(h->cutLow,ymin,h->cutLow,htmp->GetMaximum()*1.05);
      tl->DrawLine(h->cutHigh,ymin,h->cutHigh,htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
      ++i;
    }
    channel(ch,c2);

    c2->Print(Form("Ch%d_best_distr.pdf",ch));
    c2->Print(Form("Ch%d_best_distr.png",ch));
  }

  if (plotEvents) {
    hfile->cd();
    TH1* hEvents=(TH1F*)hfile->Get("hEvents");
    hEvents->SetBinContent(1, inputEvents);

    TCanvas* cEvents=new TCanvas("cEvents","",900,500);
    cEvents->Divide(1);

    cEvents->cd(1);
    TH1* htmp=(TH1F*)hfile->Get("hNCands");
    if (htmp) htmp->DrawCopy();
    tt->DrawLatexNDC(0.3,0.6,Form("All cands multiplicity: %3.2f",htmp->GetMean()));
    tt->DrawLatexNDC(0.3,0.5,Form("All cands #epsilon: %3.3f",htmp->GetEntries()/hEvents->GetBinContent(1)));
    cEvents->cd(1);
    htmp=(TH1F*)hfile->Get("hNGoodCands");
    if (htmp) {
      htmp->SetFillColor(kBlue);
      htmp->DrawCopy();
      tt->DrawLatexNDC(0.3,0.6,Form("Good cands multiplicity: %3.2f",htmp->GetMean()));
      tt->DrawLatexNDC(0.3,0.5,Form("Best cands           #epsilon: %3.3f",hEvents->GetBinContent(13)/hEvents->GetBinContent(1)));
      tt->DrawLatexNDC(0.3,0.4,Form("Best cands MC true  #epsilon: %3.3f",hEvents->GetBinContent(14)/hEvents->GetBinContent(1)));
      tt->DrawLatexNDC(0.3,0.3,Form("Best cands MC false #epsilon: %3.3f",hEvents->GetBinContent(15)/hEvents->GetBinContent(1)));
    }
    hfile->cd();
    // Statistics
    cout << "Total number of events: " << hEvents->GetBinContent(1) << endl;
    cout << "Total number of events skim: " << hEvents->GetBinContent(2)<< endl;
    cout << "Total number of events reco: " << hEvents->GetBinContent(3)<< endl;
    cout << "Total number of events passed: " << hEvents->GetBinContent(13)<< endl;
    cout << "Total number of signal events passed: " << hEvents->GetBinContent(14)<< endl;
    cout << "Total number of SXF passed: " << hEvents->GetBinContent(15)<< endl;
    vector<string> cuts;
    if (ch==1) {
      cuts.push_back("Input");
      cuts.push_back("Skim");
      cuts.push_back("Reco");
      cuts.push_back("Mbc");
      cuts.push_back("DeltaE");
      cuts.push_back("Eta Mass");
      cuts.push_back("EtaP Mass");
      cuts.push_back("K0 Mass");
      cuts.push_back("Pi DLL Kaon");
      cuts.push_back("Pi d0");
      cuts.push_back("Pi z0");
      cuts.push_back("Pi nPXDHits");
      cuts.push_back("Pi VtxPValue");
      cuts.push_back("Passed");
      cuts.push_back("MC True");
      cuts.push_back("SxF");
    }
    for (int i=1; i<16 ; ++i ) {
      string what=(i<cuts.size()? cuts[i-1]: "what?");
      cout << "Cut " << i << " " << what << ": \t" 
        << hEvents->GetBinContent(i)
        << " true \t" 
        << hEvents->GetBinContent(20+i)
        <<  endl;
    }
    cEvents->cd(1);
    //hEvents->GetXaxis()->SetRange(10,22);
    hEvents->Draw("text hist");

    channel(ch, cEvents,0.5,0.93);
    cEvents->Print(Form("Ch%d_events.pdf",ch));
    cEvents->Print(Form("Ch%d_events.png",ch));
  }

  if (plotDeltaT) {
    hfile->cd("BestCandidatesDeltaT");
    // MC DT
    TH1* hTrueDT_best=(TH1F*)gDirectory->Get("hTrueDT_best");

    TH1* hTrueDT_TrueB0_best=(TH1F*)gDirectory->Get("hTrueDT_TrueB0_best");
    hTrueDT_TrueB0_best->SetLineColor(kRed);
    TH1* hTrueDT_TrueB0bar_best=(TH1F*)gDirectory->Get("hTrueDT_TrueB0bar_best");
    hTrueDT_TrueB0bar_best->SetLineColor(kBlue);

    TH1* hTrueDT_TagB0_best=(TH1F*)gDirectory->Get("hTrueDT_TagB0_best");
    hTrueDT_TagB0_best->SetLineColor(kRed);
    TH1* hTrueDT_TagB0bar_best=(TH1F*)gDirectory->Get("hTrueDT_TagB0bar_best");
    hTrueDT_TagB0bar_best->SetLineColor(kBlue);

    // Reco DT
    TH1* hDeltaDT_best=(TH1F*)gDirectory->Get("hDeltaDT_best");

    TH1* hDT_best=(TH1F*)gDirectory->Get("hDT_best");

    TH1* hDT_TrueB0_best=(TH1F*)gDirectory->Get("hDT_TrueB0_best");
    hDT_TrueB0_best->SetLineColor(kRed);
    TH1* hDT_TrueB0bar_best=(TH1F*)gDirectory->Get("hDT_TrueB0bar_best");
    hDT_TrueB0bar_best->SetLineColor(kBlue);

    TH1* hDT_TagB0_best=(TH1F*)gDirectory->Get("hDT_TagB0_best");
    hDT_TagB0_best->SetLineColor(kRed);
    TH1* hDT_TagB0bar_best=(TH1F*)gDirectory->Get("hDT_TagB0bar_best");
    hDT_TagB0bar_best->SetLineColor(kBlue);

    // define the number of parameters and fit range for the function fitFunc.
    Int_t npar = 9;
    Double_t min_range = -20.0;
    Double_t max_range = 20.0;
    TF1 * myFitFunc = new TF1("fitFunc", fitFunc, min_range, max_range, npar);
    myFitFunc->SetParName(0, "norm");
    myFitFunc->SetParName(1, "Bias_{C}");
    myFitFunc->SetParName(2, "#sigma_{C}");
    myFitFunc->SetParName(3, "Bias_{T}");
    myFitFunc->SetParName(4, "#sigma_{T}");
    myFitFunc->SetParName(5, "Bias_{O}");
    myFitFunc->SetParName(6, "#sigma_{O}");
    myFitFunc->SetParName(7, "f_{C}");
    myFitFunc->SetParName(8, "f_{T}");
    myFitFunc->SetParameters(100.0, 0., 1., 0., 1.5, 0, 3., 0.4, 0.1);

    myFitFunc->SetParLimits(0, 0.0, 2E6);  // norm
    myFitFunc->SetParLimits(1, -2.0, 2.0);    // mu1
    myFitFunc->SetParLimits(2, 0.01,  1.);      // sigma1
    myFitFunc->SetParLimits(3, -4.0, +4.0);   // mu2
    myFitFunc->SetParLimits(4, .3,  3.);      // sigma2
    myFitFunc->SetParLimits(5, -4.0, +4.0);   // mu3
    myFitFunc->SetParLimits(6, 2.,  20.);    // sigma3
    myFitFunc->SetParLimits(7, 0.0,  1.0);    // frac1
    myFitFunc->SetParLimits(8, 0.0,  1.0);    // frac2

    myFitFunc->SetLineWidth(2);

    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
    gStyle->SetFitFormat("4.3g");
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatFont(62);
    gStyle->SetStatH(0.15);
    gStyle->SetStatW(0.18);
    TCanvas* cDt=new TCanvas("cDt");
    //hDT_best->Draw();
    hDeltaDT_best->Fit("fitFunc", "LE");
    hDeltaDT_best->Draw("e");

    TF1 *gC    = new TF1("gC","gaus",min_range, max_range);
    TF1 *gT    = new TF1("gT","gaus",min_range, max_range);
    TF1 *gO    = new TF1("gO","gaus",min_range, max_range);
    double* fitParams=myFitFunc->GetParameters();
    gC->SetLineColor(kRed);
    gC->SetLineStyle(2);
    gC->SetParameter(0,fitParams[0]*fitParams[7]);
    gC->SetParameter(1,fitParams[1]);
    gC->SetParameter(2,fitParams[2]);
    cout << "Core " << gC->GetParameter(0) << " " << gC->GetParameter(1)  << " " << gC->GetParameter(2)<< endl;
    gT->SetLineColor(kGreen);
    gT->SetLineStyle(2);
    gT->SetParameter(0,fitParams[0]*fitParams[8]);
    gT->SetParameter(1,fitParams[3]);
    gT->SetParameter(2,fitParams[4]);
    cout << "Tail " << gT->GetParameter(0) << " " << gT->GetParameter(1)  << " " << gT->GetParameter(2)<< endl;
    gO->SetLineColor(kBlue);
    gO->SetLineStyle(2);
    gO->SetParameter(0,fitParams[0]*(1-fitParams[7]-fitParams[8]));
    gO->SetParameter(1,fitParams[5]);
    gO->SetParameter(2,fitParams[6]);
    cout << "Outlier " << gO->GetParameter(0) << " " << gO->GetParameter(1)  << " " << gO->GetParameter(2)<< endl;
    gC->Draw("same");
    gT->Draw("same");
    gO->Draw("same");

    double resoDt=(gC->GetParameter(2)*gC->GetParameter(0))+(gO->GetParameter(2)*gO->GetParameter(0))+(gT->GetParameter(2)*gT->GetParameter(0));
    double sumW=gC->GetParameter(0)+gO->GetParameter(0)+gT->GetParameter(0);
    cout << "Mean(DT) = " << resoDt/sumW << endl;
    TLegend* tleg=new TLegend(0.2,.6,0.4,0.89,"Fit","NDC");
    tleg->AddEntry(gC,"Core","l");
    tleg->AddEntry(gT,"Tail","l");
    tleg->AddEntry(gO,"Outlier","l");
    tleg->Draw();

    tt->DrawLatexNDC(0.65,0.35,Form("<#Deltat>: %3.2f ps",resoDt/sumW));
    channel(ch, cDt,0.3,0.96);
    cDt->Print(Form("Ch%d_Dt.pdf",ch));
    cDt->Print(Form("Ch%d_Dt.png",ch));
  }

  if (plotDeltaZ) {
    hfile->cd("BestCandidatesDeltaT");
    // Signal vertex
    TH1* hDzVtxSignal_best=(TH1F*)gDirectory->Get("hDzVtxSignal_best");

    // tag Vertex
    TH1* hDzVtxTag_best=(TH1F*)gDirectory->Get("hDzVtxTag_best");


    // define the number of parameters and fit range for the function fitFunc.
    Int_t npar = 9;
    Double_t min_range = -0.05;
    Double_t max_range = 0.05;
    TF1 * myFitFunc = new TF1("fitFunc", fitFunc, min_range, max_range, npar);
    myFitFunc->SetParName(0, "norm");
    myFitFunc->SetParName(1, "Bias_{C}");
    myFitFunc->SetParName(2, "#sigma_{C}");
    myFitFunc->SetParName(3, "Bias_{T}");
    myFitFunc->SetParName(4, "#sigma_{T}");
    myFitFunc->SetParName(5, "Bias_{O}");
    myFitFunc->SetParName(6, "#sigma_{O}");
    myFitFunc->SetParName(7, "f_{C}");
    myFitFunc->SetParName(8, "f_{T}");
    myFitFunc->SetParameters(100.0, 0., .001, 0., 0.01, 0, .03, 0.4, 0.3);

    myFitFunc->SetParLimits(0, 0.0, 100000);  // norm
    myFitFunc->SetParLimits(1, -.02, .02);    // mu1
    myFitFunc->SetParLimits(2, 0.001,  .01);      // sigma1
    myFitFunc->SetParLimits(3, -.04, +.04);   // mu2
    myFitFunc->SetParLimits(4, .001,  .01);      // sigma2
    myFitFunc->SetParLimits(5, -.04, +.04);   // mu3
    myFitFunc->SetParLimits(6, .001,  1.);    // sigma3
    myFitFunc->SetParLimits(7, 0.0,  1.0);    // frac1
    myFitFunc->SetParLimits(8, 0.0,  1.0);    // frac2

    myFitFunc->SetLineWidth(2);

    gStyle->SetOptStat(0);
    gStyle->SetFitFormat("4.3g");
    gStyle->SetStatFontSize(0.05);
    gStyle->SetStatFont(62);
    gStyle->SetStatH(0.15);
    gStyle->SetStatW(0.18);
    TCanvas* cDz=new TCanvas("cDz","cDz",1000,500);
    cDz->Divide(2);
    cDz->cd(1);
    //hDT_best->Draw();
    hDzVtxSignal_best->Fit("fitFunc", "LE");
    hDzVtxSignal_best->Draw("e");
    TF1 *gC    = new TF1("gC","gaus",min_range, max_range);
    TF1 *gT    = new TF1("gT","gaus",min_range, max_range);
    TF1 *gO    = new TF1("gO","gaus",min_range, max_range);
    double* fitParams=myFitFunc->GetParameters();
    gC->SetLineColor(kRed);
    gC->SetLineStyle(2);
    gC->SetParameter(0,fitParams[0]*fitParams[7]);
    gC->SetParameter(1,fitParams[1]);
    gC->SetParameter(2,fitParams[2]);
    cout << "Core " << gC->GetParameter(0) << " " << gC->GetParameter(1)  << " " << gC->GetParameter(2)<< endl;
    gT->SetLineColor(kGreen);
    gT->SetLineStyle(2);
    gT->SetParameter(0,fitParams[0]*fitParams[8]);
    gT->SetParameter(1,fitParams[3]);
    gT->SetParameter(2,fitParams[4]);
    cout << "Tail " << gT->GetParameter(0) << " " << gT->GetParameter(1)  << " " << gT->GetParameter(2)<< endl;
    gO->SetLineColor(kBlue);
    gO->SetLineStyle(2);
    gO->SetParameter(0,fitParams[0]*(1-fitParams[7]-fitParams[8]));
    gO->SetParameter(1,fitParams[5]);
    gO->SetParameter(2,fitParams[6]);
    cout << "Outlier " << gO->GetParameter(0) << " " << gO->GetParameter(1)  << " " << gO->GetParameter(2)<< endl;
    gC->Draw("same");
    gT->Draw("same");
    gO->Draw("same");

    double resoDt=(gC->GetParameter(2)*gC->GetParameter(0))+(gO->GetParameter(2)*gO->GetParameter(0))+(gT->GetParameter(2)*gT->GetParameter(0));
    double sumW=gC->GetParameter(0)+gO->GetParameter(0)+gT->GetParameter(0);
    cout << "Mean(DZ) = " << resoDt/sumW << endl;
    TLegend* tleg=new TLegend(0.2,.6,0.4,0.89,"Fit","NDC");
    tleg->AddEntry(gC,"Core","l");
    tleg->AddEntry(gT,"Tail","l");
    tleg->AddEntry(gO,"Outlier","l");
    tleg->Draw();

    tt->DrawLatexNDC(0.65,0.35,Form("<#Deltaz>: %3.2f #mum",resoDt/sumW*10000.));

    cDz->cd(2);
    hDzVtxTag_best->Fit("fitFunc", "LE");
    hDzVtxTag_best->Draw("e");
    gC    = new TF1("gC","gaus",min_range, max_range);
    gT    = new TF1("gT","gaus",min_range, max_range);
    gO    = new TF1("gO","gaus",min_range, max_range);
    fitParams=myFitFunc->GetParameters();
    gC->SetLineColor(kRed);
    gC->SetLineStyle(2);
    gC->SetParameter(0,fitParams[0]*fitParams[7]);
    gC->SetParameter(1,fitParams[1]);
    gC->SetParameter(2,fitParams[2]);
    cout << "Core " << gC->GetParameter(0) << " " << gC->GetParameter(1)  << " " << gC->GetParameter(2)<< endl;
    gT->SetLineColor(kGreen);
    gT->SetLineStyle(2);
    gT->SetParameter(0,fitParams[0]*fitParams[8]);
    gT->SetParameter(1,fitParams[3]);
    gT->SetParameter(2,fitParams[4]);
    cout << "Tail " << gT->GetParameter(0) << " " << gT->GetParameter(1)  << " " << gT->GetParameter(2)<< endl;
    gO->SetLineColor(kBlue);
    gO->SetLineStyle(2);
    gO->SetParameter(0,fitParams[0]*(1-fitParams[7]-fitParams[8]));
    gO->SetParameter(1,fitParams[5]);
    gO->SetParameter(2,fitParams[6]);
    cout << "Outlier " << gO->GetParameter(0) << " " << gO->GetParameter(1)  << " " << gO->GetParameter(2)<< endl;
    gC->Draw("same");
    gT->Draw("same");
    gO->Draw("same");

    resoDt=(gC->GetParameter(2)*gC->GetParameter(0))+(gO->GetParameter(2)*gO->GetParameter(0))+(gT->GetParameter(2)*gT->GetParameter(0));
    sumW=gC->GetParameter(0)+gO->GetParameter(0)+gT->GetParameter(0);
    cout << "Mean(DZ) = " << resoDt/sumW << endl;
    tleg=new TLegend(0.2,.6,0.4,0.89,"Fit","NDC");
    tleg->AddEntry(gC,"Core","l");
    tleg->AddEntry(gT,"Tail","l");
    tleg->AddEntry(gO,"Outlier","l");
    tleg->Draw();

    tt->DrawLatexNDC(0.65,0.35,Form("<#Deltaz>: %3.2f #mum",resoDt/sumW*10000.));
    cDz->cd();
    channel(ch, cDz,0.3,0.96);
    cDz->Print(Form("Ch%d_Dz.pdf",ch));
    cDz->Print(Form("Ch%d_Dz.png",ch));
  }

  if (plotAsym) {
    TCanvas* cAsym=new TCanvas("cAsym");
    TPad *pad1 = new TPad("pad1", "The pad 80% of the height",0.0,0.3,1.0,1.0,0);
    TPad *pad2 = new TPad("pad2", "The pad 20% of the height",0.0,0.0,1.0,0.3,0);
    pad1->Draw();
    pad2->Draw();
    pad1->cd();

    TH1* hDT_TagB0_best=(TH1F*)gDirectory->Get("hDT_TagB0_best");
    hDT_TagB0_best->SetMarkerStyle(24);
    hDT_TagB0_best->SetMarkerColor(kBlue);
    hDT_TagB0_best->SetLineColor(kBlue);
    hDT_TagB0_best->Draw("histoe");

    TH1* hDT_TagB0bar_best=(TH1F*)gDirectory->Get("hDT_TagB0bar_best");
    hDT_TagB0bar_best->SetMarkerStyle(20);
    hDT_TagB0bar_best->SetMarkerColor(kRed);
    hDT_TagB0bar_best->SetLineColor(kRed);
    hDT_TagB0bar_best->Draw("histo e same");

    TLegend* tleg=new TLegend(0.2,.6,0.4,0.89,"Flavour","NDC");
    tleg->AddEntry(hDT_TagB0_best,"B_{0}","l");
    tleg->AddEntry(hDT_TagB0bar_best,"#bar{B_{0}}","l");
    tleg->Draw();

    pad2->cd();
    TH1* hDT_Tag_best_num=(TH1*)hDT_TagB0_best->Clone();
    hDT_Tag_best_num->Add(hDT_TagB0bar_best,-1.);

    TH1* hDT_Tag_best_den=(TH1*)hDT_TagB0_best->Clone();
    hDT_Tag_best_den->Add(hDT_TagB0bar_best,+1.);

    TH1* hDT_Tag_best_asym=(TH1*)hDT_Tag_best_num->Clone();
    hDT_Tag_best_asym->Divide(hDT_Tag_best_den);

    hDT_Tag_best_asym->SetMaximum(+1.05);
    hDT_Tag_best_asym->SetMinimum(-1.05);
    hDT_Tag_best_asym->SetLineColor(kBlack);
    hDT_Tag_best_asym->SetMarkerColor(kBlack);
    hDT_Tag_best_asym->SetMarkerStyle(20);
    gPad->SetGridy();
    hDT_Tag_best_asym->Draw("e");
    hDT_Tag_best_asym->GetYaxis()->SetNdivisions(503);

    hDT_Tag_best_asym->GetYaxis()->SetTitle("Asymmetry");
    hDT_Tag_best_asym->GetYaxis()->SetTitleOffset(0.3);
    hDT_Tag_best_asym->GetYaxis()->SetTitleSize(0.1);
    hDT_Tag_best_asym->GetYaxis()->SetLabelSize(0.1);

    hDT_Tag_best_asym->GetXaxis()->SetLabelSize(0.1);
    hDT_Tag_best_asym->GetXaxis()->SetTitleSize(0.1);

    hDT_Tag_best_asym->Draw("e");
    // TF1* mysin=new TF1("mysin","[0]*sin([1]*x)",-10,10);
    // mysin->SetParameter(0,0.2);
    // mysin->SetParameter(1,0.2);
    // hDT_Tag_best_asym->Fit("mysin","R");
    channel(ch,cAsym,0.5,0.96);
    cAsym->Print(Form("Ch%d_Asym.pdf",ch));
    cAsym->Print(Form("Ch%d_Asym.png",ch));
  }
}

void plotAll() {
  plot_ch(1);
  plot_ch(2);
  plot_ch(4);
  plot_ch(5);
}
