#define B0_ch2_cxx
#include "B0_ch2.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void B0_ch2::Loop(Long64_t maxEv)
{
    TRandom* random1 = new TRandom;
//   In a ROOT session, you can do:
//      Root > .L B0_ch2.C
//      Root > B0_ch2 t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TH1F *hNCands= new TH1F("hNCands",";N candidates", 20, 0, 20);
   TH1F *hNGoodCands= new TH1F("hNGoodCands",";N good candidates", 20, 0, 20);
   TH1F *hEvents= new TH1F("hEvents","Events statistics", 20, 1, 21);

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
   TH1F *hDT_TrueB0_best  = new TH1F("hDT_TrueB0_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hDT_TrueB0bar_best  = new TH1F("hDT_TrueB0bar_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hDT_TagB0_best  = new TH1F("hDT_TagB0_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hDT_TagB0bar_best  = new TH1F("hDT_TagB0bar_best",";#Deltat (ps)", 20, -10., 10.);

   TH1F *hTrueDT_best  = new TH1F("hTrueDT_best",";#Deltat (ps)", 100, -20., 20.);
   TH1F *hTrueDT_TrueB0_best  = new TH1F("hTrueDT_TrueB0_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hTrueDT_TrueB0bar_best  = new TH1F("hTrueDT_TrueB0bar_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hTrueDT_TagB0_best  = new TH1F("hTrueDT_TagB0_best",";#Deltat (ps)", 20, -10., 10.);
   TH1F *hTrueDT_TagB0bar_best  = new TH1F("hTrueDT_TagB0bar_best",";#Deltat (ps)", 20, -10., 10.);

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
       if (nev > maxEv) break;
       hNCands->Fill(nCandsLast);
       hEvents->Fill(1);
       if (nGoodCands) {
         hNGoodCands->Fill(nGoodCands);
         hEvents->Fill(2);
       }
       //cout << " nCands " << nCandsLast << " good " << nGoodCands << endl;
       nGoodCands=0;
       lastEvt=evt_no;
     }
     nCandsLast=nCands;
     if (_skipIfSignal && B0__isSignal)  continue;

     fillHistos("AllCandidates");

     if (B0__isSignal)  fillHistos("AllCandidatesIsSignal");
     // apply cuts
     if (Cut(ientry) > 0) {
       // cout << " Good " ;
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
       hEvents->Fill(10);
       nb = fChain->GetEntry(jentry);   nbytes += nb;

       Long64_t nCandsCurrent=nCands;
       // cout << "nCands = " << nCandsCurrent << endl;
       if (!(_skipIfSignal && B0__isSignal)) {

         Long64_t iBest = selectBestCand(jentry, nCandsCurrent);
         if (iBest>=0) {
           hEvents->Fill(11);
           // cout << "Best: " << iBest << endl;

           nb = fChain->GetEntry(iBest);
           //cout << "MB " << B0_M<< endl;

           fillHistos("BestCandidates");

           // Plot Dt, reco and MC
           hDT_best->Fill(B0_DeltaT);
           hTrueDT_best->Fill(B0_TruthDeltaT);

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
             int recoFlavourTag=B0_mcTagPDG;

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


           if (B0__isSignal) {
             hEvents->Fill(12);
             fillHistos("BestCandidatesIsSignal");
           } else {
             hEvents->Fill(13);
             fillHistos("BestCandidatesIsNotSignal");
           }
           //Show(iBest);
         }
       }

       // next events
       jentry+=nCandsCurrent;
       nev++;

     } while (nev< maxEv && jentry <nentries); 


     ofile->cd();
     hEvents->Write();
     saveHisto("BestCandidates");

     saveHisto("BestCandidatesIsSignal");

     saveHisto("BestCandidatesIsNotSignal");

     ofile->cd();
     ofile->mkdir("BestCandidatesDeltaT");
     ofile->cd("BestCandidatesDeltaT");
     hDT_best->Write();
     hDT_TrueB0_best->Write();
     hDT_TrueB0bar_best->Write();
     hDT_TagB0_best->Write();
     hDT_TagB0bar_best->Write();

     hTrueDT_best->Write();
     hTrueDT_TrueB0_best->Write();
     hTrueDT_TrueB0bar_best->Write();
     hTrueDT_TagB0_best->Write();
     hTrueDT_TagB0bar_best->Write();
   }

   ofile->Close();
}

Bool_t B0_ch2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void B0_ch2::createHisto(const TString& dir) {
  ofile->cd();
  ofile->mkdir(dir);
  ofile->cd(dir);
  new TH1F("hMbc","Mbc;M_{bc}", 100, 5.25,5.29);
  new TH1F("hDeltaE",";#DeltaE", 100, -0.2,0.3);
  new TH1F("hMinvEta",";M_{#eta}", 100, 0.4,0.7);
  new TH1F("hMinvEtaP",";M_{#eta'}", 100, 0.85,1.15);
  new TH1F("hMinvPi0",";M_{#pi^{0}}", 100, 0.07, 0.2);
  new TH1F("hMinvK0S",";M_{K^{0}_{S}}", 100, 0.3, 0.7);

  new TH1F("hPIDpi",";PID_{#pi}", 100, 0, 1.);
  new TH1F("hD0pi",";d_{0}(#pi)", 100, -.2, .2);
  new TH1F("hZ0pi",";z_{0}(#pi)", 100, -.5, .5);
  new TH1F("hNPxdHitspi",";n PXD hits (#pi)", 4, 0, 4);

  new TH1F("hVtxPValueK0S",";P_{vtx}(K^{0}_{S})", 100, 0, 1);
  new TH1F("hVtxPValueEta",";P_{vtx}(#eta)", 100, 0, 1);
  new TH1F("hVtxPValueEtaP",";P_{vtx}(#eta')", 100, 0, 1);
  new TH1F("hVtxPValueB0",";P_{vtx}(B_{0})", 100, 0, 1);
  ofile->cd();
}

void B0_ch2::saveHisto(const TString& dir) {
  ofile->cd();
  ofile->cd(dir);
  cout << "Saving " << endl;
  TString hNames[14]={"hMbc","hDeltaE","hMinvEta","hMinvEtaP","hMinvPi0","hMinvK0S","hPIDpi","hD0pi","hZ0pi","hNPxdHitspi","hVtxPValueK0S","hVtxPValueEta","hVtxPValueEtaP","hVtxPValueB0"};
  for (int i=0; i<14; ++i) 
    ((TH1F*)gDirectory->Get(hNames[i]))->Write();
  ofile->cd();
}

void B0_ch2::fillHistos(const TString& dir) {
  ofile->cd(dir);
  ((TH1F*)gDirectory->Get("hMbc"))->Fill(B0_mbc);
  ((TH1F*)gDirectory->Get("hDeltaE"))->Fill(B0_deltae);
  ((TH1F*)gDirectory->Get("hMinvEta"))->Fill(B0_etaP_eta_M);
  ((TH1F*)gDirectory->Get("hMinvEtaP"))->Fill(B0_etaP_M);
  ((TH1F*)gDirectory->Get("hMinvPi0"))->Fill(B0_K_S0_pi00_M);
  ((TH1F*)gDirectory->Get("hMinvPi0"))->Fill(B0_K_S0_pi01_M);
  ((TH1F*)gDirectory->Get("hMinvK0S"))->Fill(B0_K_S0_M);
          
  ((TH1F*)gDirectory->Get("hPIDpi"))->Fill(B0_etaP_pi0_PIDpi);
  ((TH1F*)gDirectory->Get("hPIDpi"))->Fill(B0_etaP_pi1_PIDpi);
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
  ofile->cd();
}

void B0_ch2::fillHisto(const TString& dir, const TString& hname, const double& value) {
  TH1F* htmp=(TH1F*)ofile->Get(dir+"/"+hname);
  if (htmp) htmp->Fill(value);
}

Int_t B0_ch2::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
  if (B0_mbc<5.25) return 0;
  if (B0_deltae<-0.15 || B0_deltae>0.25) return 0;
  if (B0_etaP_eta_M<0.48 || B0_etaP_eta_M>0.57) return 0;
  if (B0_etaP_M<0.93 || B0_etaP_M>0.98) return 0;
  if (B0_K_S0_pi00_M<0.1 || B0_K_S0_pi00_M>0.150 || B0_K_S0_pi01_M<0.1 || B0_K_S0_pi01_M>0.150) return 0;
  if (B0_K_S0_M<0.42 || B0_K_S0_M>0.52) return 0;
  if (B0_etaP_pi0_PIDpi<0.2 || B0_etaP_pi1_PIDpi<0.2) return 0;
  if (fabs(B0_etaP_pi0_d0)>0.08) return 0;
  if (fabs(B0_etaP_pi0_z0)>0.15) return 0;
  if (B0_etaP_pi0_nPXDHits<1 || B0_etaP_pi1_nPXDHits<1) return 0;
  if (B0_etaP_eta_VtxPvalue<1E-5 || B0_etaP_VtxPvalue<1E-5 || B0_VtxPvalue<1E-5) return 0;
//if (B0_K_S0_VtxPvalue<1E-5 || B0_etaP_eta_VtxPvalue<1E-5 || B0_etaP_VtxPvalue<1E-5 || B0_VtxPvalue<1E-5) return 0;

   return 1;
}

Long64_t B0_ch2::selectBestCand(Long64_t jentry, Long64_t nCandsCurrent) {

  double PvtxMax=-1;
  Long64_t iResult=-1;
  for (Long64_t i=jentry; i<jentry+nCandsCurrent; ++i) {
    Long64_t nb = fChain->GetEntry(i); 
    if (Cut(jentry) > 0 ) {
      //cout << "iCands " << iCand << " B0_VtxPvalue " << B0_VtxPvalue << " B0_etaP_VtxPvalue " << B0_etaP_VtxPvalue << " B0_etaP_eta_VtxPvalue " <<  B0_etaP_eta_VtxPvalue << " B0_K_S0_VtxPvalue " << B0_K_S0_VtxPvalue << " M " << B0_M << endl;
      double discriminator=B0_VtxPvalue*B0_etaP_VtxPvalue*B0_etaP_eta_VtxPvalue*B0_K_S0_VtxPvalue;
      if (B0_VtxPvalue>0 && B0_etaP_VtxPvalue>0 && B0_etaP_eta_VtxPvalue >0 && B0_K_S0_VtxPvalue>0 && discriminator>PvtxMax) {
        iResult=i;
        PvtxMax=discriminator;
      }
    }
  }
  return iResult;
}
