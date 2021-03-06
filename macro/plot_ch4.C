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

void channel(TCanvas* c, float x=0.5, float y=0.96) {
  TLatex* tch=new TLatex();
  tch->SetTextSize(0.04);
  tch->SetTextAlign(21);
  TString channel("B^{0}#rightarrow#eta'( #eta(#pi^{+}#pi^{-}#pi^{0}) #pi^{+}#pi^{-}) K^{0}_{S}(#pi^{+}#pi^{-})");
  c->cd();
  TPad *newpad=new TPad("newpad","a transparent pad",0,0,1,1);
  newpad->SetFillStyle(4000);
  newpad->Draw();
  newpad->cd();
  tch->DrawLatexNDC(x,y,channel);
}

Double_t fitFunc(Double_t * x, Double_t * par)
{
  Double_t PDF     = 0.0;
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

void plot_ch4() {
  TFile* hfile=TFile::Open("Histo_ch4.root");

  gStyle->SetPadTopMargin(0.10);
  gStyle->SetOptStat(0);


  TLatex* tt=new TLatex();
  tt->SetTextSize(0.05);


  TLine* tl=new TLine();
  tl->SetLineWidth(2);
  tl->SetLineColor(kRed+2);

  if (false) {
    TString hNames[13]={"hMbc","hDeltaE","hMinvEta","hMinvEtaP","hMinvPi0","hMinvK0S","hPIDpi","hD0pi","hZ0pi","hNPxdHitspi","hVtxPValueEta","hVtxPValueEtaP","hVtxPValueB0"};
    bool hLog[13]={true,true,true,true,true,true,true,true,true,true,true,true,true};
    float hCutLow[13] ={5.25,-0.15,0.52,0.93,0.1 ,0.48,0.2,-0.08,-0.15,1,1E-3,1E-3,1E-3};
    float hCutHigh[13]={5.29, 0.15,0.57,0.98,0.15,0.52,1.0,+0.08,+0.15,4,1E-3,1E-3,1E-3};

    TCanvas* c1=new TCanvas("c1","Before Cuts");
    c1->Divide(4,4);
    for (int i=0; i<13; ++i) {
      c1->cd(i+1);
      hfile->cd("AllCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(hNames[i]);
      float ymin=0;
      if (hLog[i]) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->GetXaxis()->SetTitleOffset(.7);
        htmp->GetXaxis()->SetTitleSize(0.08);
        htmp->SetMinimum(ymin);
        htmp->DrawCopy();
      }
      hfile->cd("AllCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]+"_is");
      if (htmp_is) {
        htmp_is->SetFillColor(kYellow);
        htmp_is->DrawCopy("same");
      }
      hfile->cd("AllGoodCandidates");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]+"_good");
      if (htmp_is) {
        htmp_is->SetFillColor(kBlue);
        htmp_is->DrawCopy("same");
      }
      hfile->cd("AllGoodCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]+"_is_good");
      if (htmp_is) {
        htmp_is->SetFillColor(kGreen);
        htmp_is->DrawCopy("same");
      }
      hfile->cd("BestCandidates");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]+"_best");
      if (htmp_is) {
        htmp_is->SetLineColor(kRed);
        htmp_is->DrawCopy("same");
      }
      hfile->cd("BestCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]+"_is_best");
      if (htmp_is) {
        htmp_is->SetLineColor(kViolet);
        htmp_is->DrawCopy("same");
      }
      tl->DrawLine(hCutLow[i],ymin,hCutLow[i],htmp->GetMaximum()*1.05);
      tl->DrawLine(hCutHigh[i],ymin,hCutHigh[i],htmp->GetMaximum()*1.05);
    }
    c1->cd(16);
    TH1* htmp=(TH1F*)hfile->Get("hNCands");
    if (htmp) htmp->DrawCopy();
    tt->DrawLatexNDC(0.3,0.6,Form("All cands #e: %3.2f",htmp->GetEntries()/10000.));
    tt->DrawLatexNDC(0.3,0.5,Form("All cands multiplicity: %3.2f",htmp->GetMean()));
    //c1->cd(16);
    htmp=(TH1F*)hfile->Get("hNGoodCands");
    if (htmp) {
      htmp->SetFillColor(kGreen);
      htmp->DrawCopy("same");
      tt->DrawLatexNDC(0.3,0.4,Form("All cands #e: %3.2f",htmp->GetEntries()/10000.));
      tt->DrawLatexNDC(0.3,0.3,Form("Good cands multiplicity: %3.2f",htmp->GetMean()));
    }
    c1->cd(15);
    channel(c1,0.5,0.1);
    hfile->cd();
  }

  if(true) {
    TString hNames[6]={"hMbc","hDeltaE","hMinvEta","hMinvEtaP","hMinvPi0","hMinvK0S"};
    bool hLog[6]={true,true,true,true,true,true};
    float hCutLow[6] ={5.25,-0.15,0.52,0.93,0.1 ,0.48};
    float hCutHigh[6]={5.29, 0.15,0.57,0.98,0.15,0.52};
    TLine* tl=new TLine();
    tl->SetLineWidth(2);
    tl->SetLineColor(kRed+2);
    TCanvas* c1=new TCanvas("c1","Before Cuts",900,600);
    c1->Divide(3,2);
    TLegend* tleg=new TLegend(0.2,0.4,0.6,0.89);
    tleg->SetFillStyle(0);
    for (int i=0; i<6; ++i) {
      c1->cd(i+1);
      hfile->cd("AllCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(hNames[i]);
      float ymin=0;
      if (hLog[i]) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->GetXaxis()->SetTitleOffset(.7);
        htmp->GetXaxis()->SetTitleSize(0.08);
        htmp->SetMinimum(ymin);
        htmp->DrawCopy();
        if (i==0)tleg->AddEntry(htmp,"All cands","l");
      }
      hfile->cd("AllCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]);
      if (htmp_is) {
        htmp_is->SetFillColor(kYellow);
        htmp_is->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp_is,"MC match","f");
      }
      hfile->cd("AllGoodCandidates");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]);
      if (htmp_is) {
        htmp_is->SetFillColor(kBlue);
        htmp_is->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp_is,"Good cands","f");
      }
      hfile->cd("AllGoodCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]);
      if (htmp_is) {
        htmp_is->SetFillColor(kGreen);
        htmp_is->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp_is," \" MC match","f");
      }
      tl->DrawLine(hCutLow[i],ymin,hCutLow[i],htmp->GetMaximum()*1.05);
      tl->DrawLine(hCutHigh[i],ymin,hCutHigh[i],htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
    }
    channel(c1);

    c1->Print("Ch4_distr.pdf");
    c1->Print("Ch4_distr.png");

    TCanvas* c2=new TCanvas("c2","Before Cuts",900,600);
    c2->Divide(3,2);
    TLegend* tleg=new TLegend(0.2,0.6,0.6,0.89);
    for (int i=0; i<6; ++i) {
      c2->cd(i+1);
      hfile->cd("BestCandidates");
      TH1* htmp=(TH1F*)gDirectory->Get(hNames[i]);
      float ymin=0;
      if (hLog[i]) {
        gPad->SetLogy();
        ymin=1;
      }
      if (htmp) {
        htmp->GetXaxis()->SetTitleOffset(.7);
        htmp->GetXaxis()->SetTitleSize(0.08);
        htmp->SetMinimum(ymin);
        htmp->SetFillColor(kBlue);
        htmp->DrawCopy();
        if (i==0)tleg->AddEntry(htmp,"Best cands","f");
      }
      hfile->cd("BestCandidatesIsSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]);
      if (htmp_is) {
        htmp_is->SetFillColor(kGreen);
        htmp_is->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp_is," \" MC match","f");
      }
      hfile->cd("BestCandidatesIsNotSignal");
      TH1* htmp_is=(TH1F*)gDirectory->Get(hNames[i]);
      if (htmp_is) {
        htmp_is->SetLineColor(kBlack);
        htmp_is->SetLineStyle(2);
        htmp_is->DrawCopy("same");
        if (i==0)tleg->AddEntry(htmp_is," \" SXF","l");
      }
      tl->DrawLine(hCutLow[i],ymin,hCutLow[i],htmp->GetMaximum()*1.05);
      tl->DrawLine(hCutHigh[i],ymin,hCutHigh[i],htmp->GetMaximum()*1.05);
      if (i==0) tleg->Draw();
    }
    channel(c2);

    c2->Print("Ch4_best_distr.pdf");
    c2->Print("Ch4_best_distr.png");
  }

  if (true) {
    hfile->cd();

    TCanvas* cEvents=new TCanvas("cEvents","",600,300);
    cEvents->Divide(2);

    cEvents->cd(1);
    TH1* htmp=(TH1F*)hfile->Get("hNCands");
    if (htmp) htmp->DrawCopy();
    tt->DrawLatexNDC(0.3,0.7,Form("All cands multiplicity: %3.2f",htmp->GetMean()));
    tt->DrawLatexNDC(0.3,0.6,Form("All cands #epsilon: %3.3f",htmp->GetEntries()/10000.));
    cEvents->cd(2);
    htmp=(TH1F*)hfile->Get("hNGoodCands");
    if (htmp) {
      htmp->SetFillColor(kBlue);
      htmp->DrawCopy();
      tt->DrawLatexNDC(0.3,0.7,Form("Good cands multiplicity: %3.2f",htmp->GetMean()));
      tt->DrawLatexNDC(0.3,0.6,Form("Good cands #epsilon: %3.3f",htmp->GetEntries()/10000.));
    }
    hfile->cd();
    // Statistics
    TH1* hEvents=(TH1F*)hfile->Get("hEvents");
    cout << "Total number of events: " << hEvents->GetBinContent(1) << " " << hEvents->GetBinContent(10)<< endl;
    cout << "Total number of events passed: " << hEvents->GetBinContent(2) << " " << hEvents->GetBinContent(11)<< endl;
    cout << "Total number of signal events passed: " << hEvents->GetBinContent(3) << " " << hEvents->GetBinContent(12)<< endl;
    channel(cEvents,0.5,0.93);
    cEvents->Print("Ch4_events.pdf");
    cEvents->Print("Ch4_events.png");
  }
  
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
  myFitFunc->SetParameters(1500.0, 0., 1., 0., 1.5, 0, 3., 0.4, 0.3);

  myFitFunc->SetParLimits(0, 0.0, 2500.0);  // norm
  myFitFunc->SetParLimits(1, -2.0, 2.0);    // mu1
  myFitFunc->SetParLimits(2, 0.1,  1.);      // sigma1
  myFitFunc->SetParLimits(3, -4.0, +4.0);   // mu2
  myFitFunc->SetParLimits(4, 1.,  3.);      // sigma2
  myFitFunc->SetParLimits(5, -4.0, +4.0);   // mu3
  myFitFunc->SetParLimits(6, 2.,  20.);    // sigma3
  myFitFunc->SetParLimits(7, 0.0,  1.0);    // frac1
  myFitFunc->SetParLimits(8, 0.0,  1.0);    // frac2

  myFitFunc->SetLineWidth(2);
  if (false) {

    TCanvas* cDtAll=new TCanvas("cDtAll");
    cDtAll->Divide(3,2);
    cDtAll->cd(1);



    //hTrueDT_best->Draw();
    hTrueDT_best->Fit("fitFunc", "LE");
    hTrueDT_best->Draw("e");
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


    //return;

    cDtAll->cd(2);
    hTrueDT_TrueB0_best->Draw();
    hTrueDT_TrueB0bar_best->Draw("same");

    cDtAll->cd(3);
    hTrueDT_TagB0_best->Draw();
    hTrueDT_TagB0bar_best->Draw("same");


    cDtAll->cd(4);
    //hDT_best->Draw();
    hDT_best->Fit("fitFunc", "LE");
    hDT_best->Draw("e");
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

    cDtAll->cd(5);
    hDT_TrueB0_best->Draw();
    hDT_TrueB0bar_best->Draw("same");

    cDtAll->cd(6);
    hDT_TagB0_best->Draw();
    hDT_TagB0bar_best->Draw("same");
  }
  
  gStyle->SetOptStat(0);
  gStyle->SetFitFormat("4.3g");
  gStyle->SetStatFontSize(0.05);
  gStyle->SetStatFont(62);
  gStyle->SetStatH(0.15);
  gStyle->SetStatW(0.18);
  TCanvas* cDt=new TCanvas("cDt");
  //hDT_best->Draw();
  hDT_best->Fit("fitFunc", "LE");
  hDT_best->Draw("e");
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

  channel(cDt,0.3,0.96);
  cDt->Print("Ch4_Dt.pdf");
  cDt->Print("Ch4_Dt.png");

  TCanvas* cAsym=new TCanvas("cAsym");
  TPad *pad1 = new TPad("pad1", "The pad 80% of the height",0.0,0.3,1.0,1.0,0);
  TPad *pad2 = new TPad("pad2", "The pad 20% of the height",0.0,0.0,1.0,0.3,0);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();

  hDT_TagB0_best->SetMarkerStyle(24);
  hDT_TagB0_best->SetMarkerColor(kBlue);
  hDT_TagB0_best->SetLineColor(kBlue);
  hDT_TagB0_best->Draw("histoe");

  hDT_TagB0bar_best->SetMarkerStyle(20);
  hDT_TagB0bar_best->SetMarkerColor(kRed);
  hDT_TagB0bar_best->SetLineColor(kRed);
  hDT_TagB0bar_best->Draw("histo e same");

  TLegend* tleg=new TLegend(0.2,.6,0.4,0.89,"Flavour","NDC");
  tleg->AddEntry(hDT_TagB0_best,"B_{0}","l");
  tleg->AddEntry(hDT_TagB0bar_best,"#bar{B_{0}}","l");
  tleg->Draw();

  pad2->cd();
  TH1* hDT_Tag_best_num=hDT_TagB0_best->Clone();
  hDT_Tag_best_num->Add(hDT_TagB0bar_best,-1.);

  TH1* hDT_Tag_best_den=hDT_TagB0_best->Clone();
  hDT_Tag_best_den->Add(hDT_TagB0bar_best,+1.);

  TH1* hDT_Tag_best_asym=hDT_Tag_best_num->Clone();
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
  channel(cAsym,0.5,0.96);

  cAsym->Print("Ch4_Asym.pdf");
  cAsym->Print("Ch4_Asym.png");
}
