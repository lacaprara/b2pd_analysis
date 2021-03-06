#define B0_TMVA_ch1_cxx
#include "B0_TMVA_ch1.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TRandom.h>
#include <iostream>
#include <fstream>
using namespace std;


void B0_TMVA_ch1::Loop(Long64_t maxEv)
{
  TRandom* random1 = new TRandom;

  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();

  TH1F *hNCands= new TH1F("hNCands",";N candidates", 20, 0, 20);
  TH1F *hNGoodCands= new TH1F("hNGoodCands",";N good candidates", 20, 0, 20);
  TH1F *hEvents= new TH1F("hEvents","Events statistics", 30, 0, 30);

  createHisto("AllCandidates");

  // isSignal
  createHisto("AllCandidatesIsSignal");

  // is good candidate
  createHisto("AllGoodCandidates");

  // isGood candidate and isSignal
  createHisto("AllGoodCandidatesIsSignal");

  // is best candidate
  createHisto("BestCandidates");

  // isBest candidate and isSignal
  createHisto("BestCandidatesIsSignal");

  // isBest candidate and NOT isSignal
  createHisto("BestCandidatesIsNotSignal");
  // Dt plots
  TH1F *hDT_best  = new TH1F("hDT_best",";#Deltat (ps)", 100, -20., 20.);
  TH1F *hDeltaDT_best  = new TH1F("hDeltaDT_best",";#Deltat-#Deltat_{true} (ps)", 200, -10., 10.);
  TH1F *hDT_TrueB0_best  = new TH1F("hDT_TrueB0_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hDT_TrueB0bar_best  = new TH1F("hDT_TrueB0bar_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hDT_TagB0_best  = new TH1F("hDT_TagB0_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hDT_TagB0bar_best  = new TH1F("hDT_TagB0bar_best",";#Deltat (ps)", 20, -10., 10.);

  TH1F *hDzVtxSignal_best  = new TH1F("hDzVtxSignal_best",";#Deltaz (signal) (cm)", 100, -0.05, 0.05);
  TH1F *hDzVtxTag_best  = new TH1F("hDzVtxTag_best",";#Deltaz (tag) (cm)", 100, -0.05, 0.05);

  TH1F *hTrueDT_best  = new TH1F("hTrueDT_best",";#Deltat (ps)", 100, -20., 20.);
  TH1F *hTrueDT_TrueB0_best  = new TH1F("hTrueDT_TrueB0_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hTrueDT_TrueB0bar_best  = new TH1F("hTrueDT_TrueB0bar_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hTrueDT_TagB0_best  = new TH1F("hTrueDT_TagB0_best",";#Deltat (ps)", 20, -10., 10.);
  TH1F *hTrueDT_TagB0bar_best  = new TH1F("hTrueDT_TagB0bar_best",";#Deltat (ps)", 20, -10., 10.);

  initTMVA();

  Long64_t nbytes = 0, nb = 0;
  int lastEvt=0;
  int nCandsLast=0;
  int nGoodCands=0;
  int nev=0;
  int nevGood=0;
  int nevGoodSignal=0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;

    // Count number of candidates
    if (evt_no!=lastEvt) { // new event
      nev++;
      static int j=1;
      if ((nev%j)==0) {
        if ((nev/j)==9) j*=10;
        cout << "Run:Event analyzed " << run_no << ":" << evt_no << " Num " << nev << endl;
      }
      if (maxEv>0 && nev > maxEv) break;
      hNCands->Fill(nCandsLast);
      hEvents->Fill(20);
      if (nGoodCands) {
        hNGoodCands->Fill(nGoodCands);
        hEvents->Fill(21);
      }
      //cout << " nCands " << nCandsLast << " good " << nGoodCands << endl;
      nGoodCands=0;
      lastEvt=evt_no;
    }
    nCandsLast=nCands;
    if (_skipIfSignal && B0__isSignal)  continue;

    //cout << endl << "iCand/N " << iCand << "/"<< nCands ;
    //
    fillHistos("AllCandidates");

    if (B0__isSignal)  fillHistos("AllCandidatesIsSignal");

    // apply cuts
    if (Cut(jentry)>0) {
      //cout << " Good " ;
      nGoodCands++;

      fillHistos("AllGoodCandidates");
      if (B0__isSignal) fillHistos("AllGoodCandidatesIsSignal");
    }
  }

  hNCands->Write();
  hNGoodCands->Write();

  saveHisto("AllCandidates");

  saveHisto("AllCandidatesIsSignal");

  saveHisto("AllGoodCandidates");

  saveHisto("AllGoodCandidatesIsSignal");

  // Now do again the loop over the events, selection the best candidates in
  // the event among the good ones.
  if (true) {

    TFile* skimFile = new TFile(Form("B0_etapr-eta-gg2pi_KS-pi+pi-_output_skim_%s.root",_what),"recreate"); 
    // skimming initialization
    LoadTree(0); //force 1st tree to be loaded
    TTree *newtree = fChain->GetTree()->CloneTree(0); 
    TBranch *b_bdt = newtree->Branch("bdt",&bdt,"bdt/F");
    TBranch *b_mlp = newtree->Branch("mlp",&mlp,"mlp/F");
    TBranch *b_svm = newtree->Branch("svm",&svm,"svm/F");

    // File for fit
    ofstream fitFile;
    fitFile.open(Form("B0_etapr-eta-gg2pi_KS-pi+pi-_output_skim_%s.txt",_what));

    cout << "############################### " << endl;
    cout << "Selecting best Candidates " << endl;

    Long64_t nbytes = 0, nb = 0;
    bool isNewEvent=false;
    int oldEvno=-999;
    double bestB0Mass=0;
    double bestB0PVtx=9999;
    Long64_t jentry=0;
    int nev=0;
    do {
      //cout << "jentry " << jentry << endl;
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      Long64_t nCandsCurrent=nCands;
      // cout << "nCands = " << nCandsCurrent << endl;

      hEvents->Fill(1);


      Long64_t iBest = selectBestCand(jentry, nCandsCurrent);
      nb = fChain->GetEntry(iBest);
      if (!(_skipIfSignal && B0__isSignal)) {

        bdt = theReader->EvaluateMVA("BDT method");
        mlp = theReader->EvaluateMVA("MLP method");
        svm = theReader->EvaluateMVA("SVM method");
        int cut=-Cut(iBest);
        //cout << "Cut " << -cut << endl;
        if (cut>0) 
          for (int icut=1; icut<=cut; ++icut)
            hEvents->Fill(1+icut);
        else
          for (int icut=1; icut<=11; ++icut)
            hEvents->Fill(1+icut);
        if (iBest>=0) {
          hEvents->Fill(22);

          fillHistos("BestCandidates");

          // Plot Dt, reco and MC
          hDT_best->Fill(B0_DeltaT);
          double DDt=B0_DeltaT-B0_TruthDeltaT;
          hDeltaDT_best->Fill(DDt);
          hTrueDT_best->Fill(B0_TruthDeltaT);

          hDzVtxTag_best->Fill(B0_TagVz-B0_TruthTagVz);
          hDzVtxSignal_best->Fill(B0_Z-B0_TruthZ);

          int recoFlavourTag=B0_mcTagPDG;
          // Plot Dt for B0 and B0bar tag (MC)
          if (B0__isSignal) {
            if (B0_mcTagPDG>0) {
              hDT_TrueB0_best->Fill(B0_DeltaT);
              hTrueDT_TrueB0_best->Fill(B0_TruthDeltaT);
            } else {
              hDT_TrueB0bar_best->Fill(B0_DeltaT);
              hTrueDT_TrueB0bar_best->Fill(B0_TruthDeltaT);
            }
            // same, but with a diluition factor of e(1-2w)^2=0.32, namely eff=1. and
            // mis-tag rate =0.217, with a random decision

            // mistag
            if (random1->Rndm() < 0.217) recoFlavourTag=-recoFlavourTag;
            if (recoFlavourTag>0) {
              hDT_TagB0_best->Fill(B0_DeltaT);
              hTrueDT_TagB0_best->Fill(B0_TruthDeltaT);
            } else {
              hDT_TagB0bar_best->Fill(B0_DeltaT);
              hTrueDT_TagB0bar_best->Fill(B0_TruthDeltaT);
            }

          }

          // Write relevant values in ascii file for Fitting
          int B0TrueFlavourTag=(B0_mcTagPDG>0?+1:-1);
          int B0FlavourTag=(recoFlavourTag>0?+1:-1);
          fitFile  << 
            setw(15) << B0_mbc  << 
            setw(15) << B0_deltae  << 
            setw(15) << bdt  << 
            setw(15) << mlp  << 
            setw(15) << svm  << 
            setw(15) << B0_etaP_M  << 
            setw(15) << B0_etaP_eta_M  << 
            setw(15) << B0_K_S0_M  << 
            setw(15) << B0_DeltaT  << 
            setw(15) << B0_TruthDeltaT  << 
            setw(15) << B0TrueFlavourTag  << 
            setw(15) << B0FlavourTag  << 
            setw(15) << B0__isSignal  << 
            endl;


          if (B0__isSignal) {
            hEvents->Fill(13);
            fillHistos("BestCandidatesIsSignal");
          } else {
            hEvents->Fill(14);
            fillHistos("BestCandidatesIsNotSignal");
          }
          //Show(iBest);

          // Fill Skim tree
          newtree->Fill();
        }
      }

      // next events
      jentry+=nCandsCurrent;
      nev++;
      static int jj=1;
      if ((nev%jj)==0) {
        if ((nev/jj)==9) jj*=10;
        cout << "Run:Event analyzed " << run_no << ":" << evt_no << " Num " << nev << endl;
      }

    } while ((maxEv<0 || nev< maxEv) && jentry <nentries); 


    // Write skim tree
    skimFile->cd();
    newtree->Write();
    skimFile->Close();
    fitFile.close();

    ofile->cd();
    hEvents->Write();
    saveHisto("BestCandidates");

    saveHisto("BestCandidatesIsSignal");

    saveHisto("BestCandidatesIsNotSignal");

    ofile->cd();
    ofile->mkdir("BestCandidatesDeltaT");
    ofile->cd("BestCandidatesDeltaT");
    hDT_best->Write();
    hDeltaDT_best->Write();

    hDzVtxSignal_best->Write();
    hDzVtxTag_best->Write();
    hDT_TrueB0_best->Write();
    hDT_TrueB0bar_best->Write();
    hDT_TagB0_best->Write();
    hDT_TagB0bar_best->Write();

    hTrueDT_best->Write();
    hTrueDT_TrueB0_best->Write();
    hTrueDT_TrueB0bar_best->Write();
    hTrueDT_TagB0_best->Write();
    hTrueDT_TagB0bar_best->Write();

    ofile->Close();
    skimFile->Close();
  }


}

void B0_TMVA_ch1::createHisto(const TString& dir) {
  ofile->cd();
  ofile->mkdir(dir);
  ofile->cd(dir);
  new TH1F("hMbc","Mbc;M_{bc}", 100, 5.25,5.29);
  new TH1F("hDeltaE",";#DeltaE", 100, -0.2,0.2);
  new TH1F("hMinvEta",";M_{#eta}", 100, 0.4,0.7);
  new TH1F("hMinvEtaP",";M_{#eta'}", 100, 0.85,1.15);
  new TH1F("hMinvK0S",";M_{K^{0}_{S}}", 100, 0.45, 0.55);

  new TH1F("hPIDpi",";PID_{#pi}", 100, 0, 1.);
  new TH1F("hDLLKaon",";#DeltaLL_{#pi/K}", 100, -20., 50.);
  new TH1F("hD0pi",";d_{0}(#pi)", 100, -.2, .2);
  new TH1F("hZ0pi",";z_{0}(#pi)", 100, -.5, .5);
  new TH1F("hNPxdHitspi",";n PXD hits (#pi)", 4, 0, 4);

  new TH1F("hVtxPValueK0S",";P_{vtx}(K^{0}_{S})", 100, 0, 1);
  new TH1F("hVtxPValueEta",";P_{vtx}(#eta)", 100, 0, 1);
  new TH1F("hVtxPValueEtaP",";P_{vtx}(#eta')", 100, 0, 1);
  new TH1F("hVtxPValueB0",";P_{vtx}(B_{0})", 100, 0, 1);

  new TH1F("hBDT",";BDT", 100, -0.5, .5);
  new TH1F("hMLP",";MLP", 100, -0.5, .5);
  new TH1F("hSVM",";SVN", 100, -0.5, .5);

  ofile->cd();
}

void B0_TMVA_ch1::saveHisto(const TString& dir) {
  ofile->cd();
  ofile->cd(dir);
  TString hNames[17]={"hMbc","hDeltaE","hMinvEta","hMinvEtaP","hMinvK0S","hPIDpi","hDLLKaon","hD0pi","hZ0pi","hNPxdHitspi","hVtxPValueK0S","hVtxPValueEta","hVtxPValueEtaP","hVtxPValueB0","hBDT","hMLP","hSVM"};
  for (int i=0; i<17; ++i) 
    ((TH1F*)gDirectory->Get(hNames[i]))->Write();
  ofile->cd();
}

void B0_TMVA_ch1::fillHistos(const TString& dir) {
  ofile->cd(dir);
  ((TH1F*)gDirectory->Get("hMbc"))->Fill(B0_mbc);
  ((TH1F*)gDirectory->Get("hDeltaE"))->Fill(B0_deltae);
  ((TH1F*)gDirectory->Get("hMinvEta"))->Fill(B0_etaP_eta_M);
  ((TH1F*)gDirectory->Get("hMinvEtaP"))->Fill(B0_etaP_M);
  ((TH1F*)gDirectory->Get("hMinvK0S"))->Fill(B0_K_S0_M);

  ((TH1F*)gDirectory->Get("hPIDpi"))->Fill(B0_etaP_pi0_PIDpi);
  ((TH1F*)gDirectory->Get("hPIDpi"))->Fill(B0_etaP_pi1_PIDpi);
  ((TH1F*)gDirectory->Get("hDLLKaon"))->Fill(B0_etaP_pi0_DLLKaon);
  ((TH1F*)gDirectory->Get("hDLLKaon"))->Fill(B0_etaP_pi1_DLLKaon);
  ((TH1F*)gDirectory->Get("hD0pi"))->Fill(B0_etaP_pi0_d0);
  ((TH1F*)gDirectory->Get("hD0pi"))->Fill(B0_etaP_pi1_d0);
  ((TH1F*)gDirectory->Get("hZ0pi"))->Fill(B0_etaP_pi0_z0);
  ((TH1F*)gDirectory->Get("hZ0pi"))->Fill(B0_etaP_pi1_z0);
  ((TH1F*)gDirectory->Get("hNPxdHitspi"))->Fill(B0_etaP_pi0_nPXDHits);
  ((TH1F*)gDirectory->Get("hNPxdHitspi"))->Fill(B0_etaP_pi1_nPXDHits);

  ((TH1F*)gDirectory->Get("hVtxPValueK0S"))->Fill(B0_K_S0_VtxPvalue);
  ((TH1F*)gDirectory->Get("hVtxPValueEta"))->Fill(B0_etaP_eta_VtxPvalue);
  ((TH1F*)gDirectory->Get("hVtxPValueEtaP"))->Fill(B0_etaP_VtxPvalue);
  ((TH1F*)gDirectory->Get("hVtxPValueB0"))->Fill(B0_VtxPvalue);

  ((TH1F*)gDirectory->Get("hBDT"))->Fill(bdt);
  ((TH1F*)gDirectory->Get("hMLP"))->Fill(mlp);
  ((TH1F*)gDirectory->Get("hSVM"))->Fill(svm);
  ofile->cd();
}

void B0_TMVA_ch1::fillHisto(const TString& dir, const TString& hname, const double& value) {
  TH1F* htmp=(TH1F*)ofile->Get(dir+"/"+hname);
  if (htmp) htmp->Fill(value);
}

Int_t B0_TMVA_ch1::Cut(Long64_t entry)
{
  Long64_t nb = fChain->GetEntry(entry);
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns <0 otherwise.
  if (B0_mbc<5.25) return -1;
  if (fabs(B0_deltae)>0.1) return -2;
  if (B0_etaP_eta_M<0.45 || B0_etaP_eta_M>0.57) return -3;
  if (B0_etaP_M<0.93 || B0_etaP_M>0.98) return -4;
  if (B0_K_S0_M<0.48 || B0_K_S0_M>0.52) return -5;
  //if (B0_etaP_pi0_PIDpi<0.2 || B0_etaP_pi1_PIDpi<0.2) return -6;
  if (B0_etaP_pi0_DLLKaon<-10 || B0_etaP_pi1_DLLKaon<-10) return -6;
  if (fabs(B0_etaP_pi0_d0)>0.08) return -7;
  if (fabs(B0_etaP_pi0_z0)>0.1) return -8;
  if (B0_etaP_pi0_nPXDHits<1 || B0_etaP_pi1_nPXDHits<1) return -9;
  if (B0_K_S0_VtxPvalue<1E-5 || B0_etaP_VtxPvalue<1E-5 || B0_VtxPvalue<1E-5) return -10;

  return 1;
}

Long64_t B0_TMVA_ch1::selectBestCand(Long64_t jentry, Long64_t nCandsCurrent) {
  static double etaP_M_pdg=0.95778;
  static double sigma_etaP=0.0094;
  static double eta_M_pdg=0.547862;
  static double sigma_eta=0.0177;
  static double K_S0_M_pdg=0.497611;
  static double sigma_KS=0.00326;

  double PvtxMax=-1;
  double chi2Min=99999;
  Long64_t iResult=-1;
  for (Long64_t i=jentry; i<jentry+nCandsCurrent; ++i) {
    Long64_t nb = fChain->GetEntry(i); 
    //int cut=Cut(i);
    //cout << "nCands " << nCands << " iCand " << iCand << " CUT " << cut << " B0_VtxPvalue " << B0_VtxPvalue << " B0_etaP_VtxPvalue " << B0_etaP_VtxPvalue << " B0_etaP_eta_VtxPvalue " <<  B0_etaP_eta_VtxPvalue << " B0_K_S0_VtxPvalue " << B0_K_S0_VtxPvalue << " M " << B0_M << endl;
    if (Cut(i)>0) {
      double chi2=
        pow((B0_etaP_M-etaP_M_pdg)/sigma_etaP,2)+
        pow((B0_etaP_eta_M-eta_M_pdg)/sigma_eta,2)+
        pow((B0_K_S0_M-K_S0_M_pdg)/sigma_KS,2);
      if (B0_VtxPvalue>0 && B0_etaP_VtxPvalue>0 && B0_etaP_eta_VtxPvalue >0 && B0_K_S0_VtxPvalue>0 && chi2<chi2Min) {
        iResult=i;
        chi2Min=chi2;
      }

      // double discriminator=B0_VtxPvalue*B0_etaP_VtxPvalue*B0_etaP_eta_VtxPvalue*B0_K_S0_VtxPvalue;
      // if (B0_VtxPvalue>0 && B0_etaP_VtxPvalue>0 && B0_etaP_eta_VtxPvalue >0 && B0_K_S0_VtxPvalue>0 && discriminator>PvtxMax) {
      //   iResult=i;
      //   PvtxMax=discriminator;
      // }
    }
  }
  return iResult;
}

void  B0_TMVA_ch1::initTMVA() {
  theReader->AddVariable("B0_ThrustB",&B0_ThrustB );
  theReader->AddVariable("B0_ThrustO",&B0_ThrustO );
  theReader->AddVariable("B0_CosTBTO",&B0_CosTBTO );
  theReader->AddVariable("B0_CosTBz",&B0_CosTBz );
  theReader->AddVariable("B0_R2",&B0_R2 );
  theReader->AddVariable("B0_cc1",&B0_cc1 );
  theReader->AddVariable("B0_cc2",&B0_cc2 );
  theReader->AddVariable("B0_cc3",&B0_cc3 );
  theReader->AddVariable("B0_cc4",&B0_cc4 );
  theReader->AddVariable("B0_cc5",&B0_cc5 );
  theReader->AddVariable("B0_cc6",&B0_cc6 );
  theReader->AddVariable("B0_cc7",&B0_cc7 );
  theReader->AddVariable("B0_cc8",&B0_cc8 );
  theReader->AddVariable("B0_cc9",&B0_cc9 );
  theReader->AddVariable("B0_mm2",&B0_mm2 );
  theReader->AddVariable("B0_et",&B0_et );
  theReader->AddVariable("B0_hso00",&B0_hso00 );
  // theReader->AddVariable("B0_hso0("1",& );
  theReader->AddVariable("B0_hso02",&B0_hso02 );
  //theReader->AddVariable("B0_hso0("3",& );
  theReader->AddVariable("B0_hso04",&B0_hso04 );
  theReader->AddVariable("B0_hso10",&B0_hso10 );
  theReader->AddVariable("B0_hso12",&B0_hso12 );
  theReader->AddVariable("B0_hso14",&B0_hso14 );
  theReader->AddVariable("B0_hso20",&B0_hso20 );
  theReader->AddVariable("B0_hso22",&B0_hso22 );
  theReader->AddVariable("B0_hso24",&B0_hso24 );
  theReader->AddVariable("B0_hoo0",&B0_hoo0 );
  theReader->AddVariable("B0_hoo1",&B0_hoo1 );
  theReader->AddVariable("B0_hoo2",&B0_hoo2 );
  theReader->AddVariable("B0_hoo3",&B0_hoo3 );
  theReader->AddVariable("B0_hoo4",&B0_hoo4 );

  theReader->BookMVA("BDT method", "weights/MVAnalysis_BDT.weights.xml");
  theReader->BookMVA("MLP method", "weights/MVAnalysis_MLPBNN.weights.xml");
  theReader->BookMVA("SVM method", "weights/MVAnalysis_SVM.weights.xml");
}
