//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Dec 17 16:14:31 2015 by ROOT version 5.34/25
// from TTree B0/
// found on file: ../steering_files/B0_etapr-eta-gg2pi_KS-pi0pi0_output_signal.root
//////////////////////////////////////////////////////////

#ifndef B0_ch4_h
#define B0_ch4_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class B0_ch4 {
  public :
    TTree          *fChain;   //!pointer to the analyzed TTree or TChain
    Int_t           fCurrent; //!current Tree number in a TChain

    // Declaration of leaf types
    Int_t           exp_no;
    Int_t           run_no;
    Int_t           evt_no;
    Float_t         B0_M;
    Float_t         B0_ErrM;
    Float_t         B0_SigM;
    Float_t         B0_etaP_M;
    Float_t         B0_etaP_ErrM;
    Float_t         B0_etaP_SigM;
    Float_t         B0_etaP_eta_M;
    Float_t         B0_etaP_eta_ErrM;
    Float_t         B0_etaP_eta_SigM;
    Float_t         B0_etaP_eta_pi0_M;
    Float_t         B0_etaP_eta_pi0_ErrM;
    Float_t         B0_etaP_eta_pi0_SigM;
    Int_t           B0_etaP_eta_pi0_charge;
    Int_t           B0_etaP_eta_pi1_charge;
    Int_t           B0_etaP_pi0_charge;
    Int_t           B0_etaP_pi1_charge;
    Float_t         B0_K_S0_M;
    Float_t         B0_K_S0_ErrM;
    Float_t         B0_K_S0_SigM;
    Float_t         B0_P;
    Float_t         B0_P4[4];
    Float_t         B0_etaP_P;
    Float_t         B0_etaP_P4[4];
    Float_t         B0_etaP_eta_P;
    Float_t         B0_etaP_eta_P4[4];
    Float_t         B0_K_S0_P;
    Float_t         B0_K_S0_P4[4];
    Float_t         B0_Pcms;
    Float_t         B0_P4cms[4];
    Float_t         B0_etaP_Pcms;
    Float_t         B0_etaP_P4cms[4];
    Float_t         B0_etaP_eta_Pcms;
    Float_t         B0_etaP_eta_P4cms[4];
    Float_t         B0_K_S0_Pcms;
    Float_t         B0_K_S0_P4cms[4];
    Int_t           B0_mcPDG;
    Int_t           B0_mcErrors;
    Int_t           B0_etaP_mcPDG;
    Int_t           B0_etaP_mcErrors;
    Int_t           B0_etaP_eta_mcPDG;
    Int_t           B0_etaP_eta_mcErrors;
    Int_t           B0_K_S0_mcPDG;
    Int_t           B0_K_S0_mcErrors;
    Float_t         B0_deltae;
    Float_t         B0_mbc;
    Float_t         B0_etaP_eta_pi0_PIDk;
    Float_t         B0_etaP_eta_pi0_PIDpi;
    Float_t         B0_etaP_eta_pi0_PIDe;
    Float_t         B0_etaP_eta_pi0_PIDmu;
    Float_t         B0_etaP_eta_pi0_PIDp;
    Float_t         B0_etaP_eta_pi1_PIDk;
    Float_t         B0_etaP_eta_pi1_PIDpi;
    Float_t         B0_etaP_eta_pi1_PIDe;
    Float_t         B0_etaP_eta_pi1_PIDmu;
    Float_t         B0_etaP_eta_pi1_PIDp;
    Float_t         B0_etaP_pi0_PIDk;
    Float_t         B0_etaP_pi0_PIDpi;
    Float_t         B0_etaP_pi0_PIDe;
    Float_t         B0_etaP_pi0_PIDmu;
    Float_t         B0_etaP_pi0_PIDp;
    Float_t         B0_etaP_pi1_PIDk;
    Float_t         B0_etaP_pi1_PIDpi;
    Float_t         B0_etaP_pi1_PIDe;
    Float_t         B0_etaP_pi1_PIDmu;
    Float_t         B0_etaP_pi1_PIDp;
    Float_t         B0_etaP_pi0_PIDk;
    Float_t         B0_etaP_pi0_PIDpi;
    Float_t         B0_etaP_pi0_PIDe;
    Float_t         B0_etaP_pi0_PIDmu;
    Float_t         B0_etaP_pi0_PIDp;
    Float_t         B0_etaP_pi1_PIDk;
    Float_t         B0_etaP_pi1_PIDpi;
    Float_t         B0_etaP_pi1_PIDe;
    Float_t         B0_etaP_pi1_PIDmu;
    Float_t         B0_etaP_pi1_PIDp;
    Float_t         B0_etaP_eta_pi0_d0;
    Float_t         B0_etaP_eta_pi0_z0;
    Float_t         B0_etaP_eta_pi0_TrPval;
    Float_t         B0_etaP_eta_pi1_d0;
    Float_t         B0_etaP_eta_pi1_z0;
    Float_t         B0_etaP_eta_pi1_TrPval;
    Float_t         B0_etaP_pi0_d0;
    Float_t         B0_etaP_pi0_z0;
    Float_t         B0_etaP_pi0_TrPval;
    Float_t         B0_etaP_pi1_d0;
    Float_t         B0_etaP_pi1_z0;
    Float_t         B0_etaP_pi1_TrPval;
    Int_t           B0_etaP_nCDCHits;
    Int_t           B0_etaP_nSVDHits;
    Int_t           B0_etaP_nPXDHits;
    Int_t           B0_etaP_eta_pi0_nCDCHits;
    Int_t           B0_etaP_eta_pi0_nSVDHits;
    Int_t           B0_etaP_eta_pi0_nPXDHits;
    Int_t           B0_etaP_eta_pi1_nCDCHits;
    Int_t           B0_etaP_eta_pi1_nSVDHits;
    Int_t           B0_etaP_eta_pi1_nPXDHits;
    Int_t           B0_etaP_pi0_nCDCHits;
    Int_t           B0_etaP_pi0_nSVDHits;
    Int_t           B0_etaP_pi0_nPXDHits;
    Int_t           B0_etaP_pi1_nCDCHits;
    Int_t           B0_etaP_pi1_nSVDHits;
    Int_t           B0_etaP_pi1_nPXDHits;
    Int_t           B0_MC_MOTHER_ID;
    Int_t           B0_MC_GD_MOTHER_ID;
    Int_t           B0_MC_GD_GD_MOTHER_ID;
    Int_t           B0_etaP_MC_MOTHER_ID;
    Int_t           B0_etaP_MC_GD_MOTHER_ID;
    Int_t           B0_etaP_MC_GD_GD_MOTHER_ID;
    Int_t           B0_etaP_eta_MC_MOTHER_ID;
    Int_t           B0_etaP_eta_MC_GD_MOTHER_ID;
    Int_t           B0_etaP_eta_MC_GD_GD_MOTHER_ID;
    Int_t           B0_K_S0_MC_MOTHER_ID;
    Int_t           B0_K_S0_MC_GD_MOTHER_ID;
    Int_t           B0_K_S0_MC_GD_GD_MOTHER_ID;
    Float_t         B0_TruthP;
    Float_t         B0_TruthP4[4];
    Float_t         B0_TruthM;
    Float_t         B0_etaP_TruthP;
    Float_t         B0_etaP_TruthP4[4];
    Float_t         B0_etaP_TruthM;
    Float_t         B0_etaP_eta_TruthP;
    Float_t         B0_etaP_eta_TruthP4[4];
    Float_t         B0_etaP_eta_TruthM;
    Float_t         B0_K_S0_TruthP;
    Float_t         B0_K_S0_TruthP4[4];
    Float_t         B0_K_S0_TruthM;
    Float_t         B0_X;
    Float_t         B0_ErrX;
    Float_t         B0_Y;
    Float_t         B0_ErrY;
    Float_t         B0_Z;
    Float_t         B0_ErrZ;
    Float_t         B0_Rho;
    Float_t         B0_VtxPvalue;
    Float_t         B0_etaP_X;
    Float_t         B0_etaP_ErrX;
    Float_t         B0_etaP_Y;
    Float_t         B0_etaP_ErrY;
    Float_t         B0_etaP_Z;
    Float_t         B0_etaP_ErrZ;
    Float_t         B0_etaP_Rho;
    Float_t         B0_etaP_VtxPvalue;
    Float_t         B0_etaP_eta_X;
    Float_t         B0_etaP_eta_ErrX;
    Float_t         B0_etaP_eta_Y;
    Float_t         B0_etaP_eta_ErrY;
    Float_t         B0_etaP_eta_Z;
    Float_t         B0_etaP_eta_ErrZ;
    Float_t         B0_etaP_eta_Rho;
    Float_t         B0_etaP_eta_VtxPvalue;
    Float_t         B0_etaP_eta_pi0_X;
    Float_t         B0_etaP_eta_pi0_ErrX;
    Float_t         B0_etaP_eta_pi0_Y;
    Float_t         B0_etaP_eta_pi0_ErrY;
    Float_t         B0_etaP_eta_pi0_Z;
    Float_t         B0_etaP_eta_pi0_ErrZ;
    Float_t         B0_etaP_eta_pi0_Rho;
    Float_t         B0_etaP_eta_pi0_VtxPvalue;
    Float_t         B0_etaP_eta_pi1_X;
    Float_t         B0_etaP_eta_pi1_ErrX;
    Float_t         B0_etaP_eta_pi1_Y;
    Float_t         B0_etaP_eta_pi1_ErrY;
    Float_t         B0_etaP_eta_pi1_Z;
    Float_t         B0_etaP_eta_pi1_ErrZ;
    Float_t         B0_etaP_eta_pi1_Rho;
    Float_t         B0_etaP_eta_pi1_VtxPvalue;
    Float_t         B0_etaP_pi0_X;
    Float_t         B0_etaP_pi0_ErrX;
    Float_t         B0_etaP_pi0_Y;
    Float_t         B0_etaP_pi0_ErrY;
    Float_t         B0_etaP_pi0_Z;
    Float_t         B0_etaP_pi0_ErrZ;
    Float_t         B0_etaP_pi0_Rho;
    Float_t         B0_etaP_pi0_VtxPvalue;
    Float_t         B0_etaP_pi1_X;
    Float_t         B0_etaP_pi1_ErrX;
    Float_t         B0_etaP_pi1_Y;
    Float_t         B0_etaP_pi1_ErrY;
    Float_t         B0_etaP_pi1_Z;
    Float_t         B0_etaP_pi1_ErrZ;
    Float_t         B0_etaP_pi1_Rho;
    Float_t         B0_etaP_pi1_VtxPvalue;
    Float_t         B0_K_S0_X;
    Float_t         B0_K_S0_ErrX;
    Float_t         B0_K_S0_Y;
    Float_t         B0_K_S0_ErrY;
    Float_t         B0_K_S0_Z;
    Float_t         B0_K_S0_ErrZ;
    Float_t         B0_K_S0_Rho;
    Float_t         B0_K_S0_VtxPvalue;
    Float_t         B0_TruthX;
    Float_t         B0_TruthY;
    Float_t         B0_TruthZ;
    Float_t         B0_TruthRho;
    Float_t         B0_etaP_TruthX;
    Float_t         B0_etaP_TruthY;
    Float_t         B0_etaP_TruthZ;
    Float_t         B0_etaP_TruthRho;
    Float_t         B0_etaP_eta_TruthX;
    Float_t         B0_etaP_eta_TruthY;
    Float_t         B0_etaP_eta_TruthZ;
    Float_t         B0_etaP_eta_TruthRho;
    Float_t         B0_etaP_eta_pi0_TruthX;
    Float_t         B0_etaP_eta_pi0_TruthY;
    Float_t         B0_etaP_eta_pi0_TruthZ;
    Float_t         B0_etaP_eta_pi0_TruthRho;
    Float_t         B0_etaP_eta_pi1_TruthX;
    Float_t         B0_etaP_eta_pi1_TruthY;
    Float_t         B0_etaP_eta_pi1_TruthZ;
    Float_t         B0_etaP_eta_pi1_TruthRho;
    Float_t         B0_etaP_pi0_TruthX;
    Float_t         B0_etaP_pi0_TruthY;
    Float_t         B0_etaP_pi0_TruthZ;
    Float_t         B0_etaP_pi0_TruthRho;
    Float_t         B0_etaP_pi1_TruthX;
    Float_t         B0_etaP_pi1_TruthY;
    Float_t         B0_etaP_pi1_TruthZ;
    Float_t         B0_etaP_pi1_TruthRho;
    Float_t         B0_K_S0_TruthX;
    Float_t         B0_K_S0_TruthY;
    Float_t         B0_K_S0_TruthZ;
    Float_t         B0_K_S0_TruthRho;
    Float_t         B0_TagVx;
    Float_t         B0_TagVy;
    Float_t         B0_TagVz;
    Float_t         B0_TagVex;
    Float_t         B0_TagVey;
    Float_t         B0_TagVez;
    Float_t         B0_TagVPvalue;
    Float_t         B0_TruthTagVx;
    Float_t         B0_TruthTagVy;
    Float_t         B0_TruthTagVz;
    Float_t         B0_DeltaT;
    Int_t           B0_mcTagPDG;
    Float_t         B0_TruthDeltaT;
    Float_t         B0_ThrustB;
    Float_t         B0_ThrustO;
    Float_t         B0_CosTBTO;
    Float_t         B0_CosTBz;
    Float_t         B0_R2;
    Float_t         B0_cc1;
    Float_t         B0_cc2;
    Float_t         B0_cc3;
    Float_t         B0_cc4;
    Float_t         B0_cc5;
    Float_t         B0_cc6;
    Float_t         B0_cc7;
    Float_t         B0_cc8;
    Float_t         B0_cc9;
    Float_t         B0_mm2;
    Float_t         B0_et;
    Float_t         B0_hso00;
    Float_t         B0_hso01;
    Float_t         B0_hso02;
    Float_t         B0_hso03;
    Float_t         B0_hso04;
    Float_t         B0_hso10;
    Float_t         B0_hso12;
    Float_t         B0_hso14;
    Float_t         B0_hso20;
    Float_t         B0_hso22;
    Float_t         B0_hso24;
    Float_t         B0_hoo0;
    Float_t         B0_hoo1;
    Float_t         B0_hoo2;
    Float_t         B0_hoo3;
    Float_t         B0_hoo4;
    Float_t         B0__isSignal;
    Float_t         B0_etaP__isSignal;
    Float_t         B0_etaP_eta__isSignal;
    Float_t         B0_etaP_eta_pi0__isSignal;
    Float_t         B0_K_S0__isSignal;
    Int_t           nCands;
    Int_t           iCand;

    // List of branches
    TBranch        *b_exp_no;   //!
    TBranch        *b_run_no;   //!
    TBranch        *b_evt_no;   //!
    TBranch        *b_B0_M;   //!
    TBranch        *b_B0_ErrM;   //!
    TBranch        *b_B0_SigM;   //!
    TBranch        *b_B0_etaP_M;   //!
    TBranch        *b_B0_etaP_ErrM;   //!
    TBranch        *b_B0_etaP_SigM;   //!
    TBranch        *b_B0_etaP_eta_M;   //!
    TBranch        *b_B0_etaP_eta_ErrM;   //!
    TBranch        *b_B0_etaP_eta_SigM;   //!
    TBranch        *b_B0_etaP_eta_pi0_M;   //!
    TBranch        *b_B0_etaP_eta_pi0_ErrM;   //!
    TBranch        *b_B0_etaP_eta_pi0_SigM;   //!
    TBranch        *b_B0_etaP_eta_pi0_charge;   //!
    TBranch        *b_B0_etaP_eta_pi1_charge;   //!
    TBranch        *b_B0_etaP_pi0_charge;   //!
    TBranch        *b_B0_etaP_pi1_charge;   //!
    TBranch        *b_B0_K_S0_M;   //!
    TBranch        *b_B0_K_S0_ErrM;   //!
    TBranch        *b_B0_K_S0_SigM;   //!
    TBranch        *b_B0_etaP_pi0_charge;   //!
    TBranch        *b_B0_etaP_pi1_charge;   //!
    TBranch        *b_B0_P;   //!
    TBranch        *b_B0_P4;   //!
    TBranch        *b_B0_etaP_P;   //!
    TBranch        *b_B0_etaP_P4;   //!
    TBranch        *b_B0_etaP_eta_P;   //!
    TBranch        *b_B0_etaP_eta_P4;   //!
    TBranch        *b_B0_K_S0_P;   //!
    TBranch        *b_B0_K_S0_P4;   //!
    TBranch        *b_B0_Pcms;   //!
    TBranch        *b_B0_P4cms;   //!
    TBranch        *b_B0_etaP_Pcms;   //!
    TBranch        *b_B0_etaP_P4cms;   //!
    TBranch        *b_B0_etaP_eta_Pcms;   //!
    TBranch        *b_B0_etaP_eta_P4cms;   //!
    TBranch        *b_B0_K_S0_Pcms;   //!
    TBranch        *b_B0_K_S0_P4cms;   //!
    TBranch        *b_B0_mcPDG;   //!
    TBranch        *b_B0_mcErrors;   //!
    TBranch        *b_B0_etaP_mcPDG;   //!
    TBranch        *b_B0_etaP_mcErrors;   //!
    TBranch        *b_B0_etaP_eta_mcPDG;   //!
    TBranch        *b_B0_etaP_eta_mcErrors;   //!
    TBranch        *b_B0_K_S0_mcPDG;   //!
    TBranch        *b_B0_K_S0_mcErrors;   //!
    TBranch        *b_B0_deltae;   //!
    TBranch        *b_B0_mbc;   //!
    TBranch        *b_B0_etaP_eta_pi0_PIDk;   //!
    TBranch        *b_B0_etaP_eta_pi0_PIDpi;   //!
    TBranch        *b_B0_etaP_eta_pi0_PIDe;   //!
    TBranch        *b_B0_etaP_eta_pi0_PIDmu;   //!
    TBranch        *b_B0_etaP_eta_pi0_PIDp;   //!
    TBranch        *b_B0_etaP_eta_pi1_PIDk;   //!
    TBranch        *b_B0_etaP_eta_pi1_PIDpi;   //!
    TBranch        *b_B0_etaP_eta_pi1_PIDe;   //!
    TBranch        *b_B0_etaP_eta_pi1_PIDmu;   //!
    TBranch        *b_B0_etaP_eta_pi1_PIDp;   //!
    TBranch        *b_B0_etaP_pi0_PIDk;   //!
    TBranch        *b_B0_etaP_pi0_PIDpi;   //!
    TBranch        *b_B0_etaP_pi0_PIDe;   //!
    TBranch        *b_B0_etaP_pi0_PIDmu;   //!
    TBranch        *b_B0_etaP_pi0_PIDp;   //!
    TBranch        *b_B0_etaP_pi1_PIDk;   //!
    TBranch        *b_B0_etaP_pi1_PIDpi;   //!
    TBranch        *b_B0_etaP_pi1_PIDe;   //!
    TBranch        *b_B0_etaP_pi1_PIDmu;   //!
    TBranch        *b_B0_etaP_pi1_PIDp;   //!
    TBranch        *b_B0_etaP_eta_pi0_d0;   //!
    TBranch        *b_B0_etaP_eta_pi0_z0;   //!
    TBranch        *b_B0_etaP_eta_pi0_TrPval;   //!
    TBranch        *b_B0_etaP_eta_pi1_d0;   //!
    TBranch        *b_B0_etaP_eta_pi1_z0;   //!
    TBranch        *b_B0_etaP_eta_pi1_TrPval;   //!
    TBranch        *b_B0_etaP_pi0_d0;   //!
    TBranch        *b_B0_etaP_pi0_z0;   //!
    TBranch        *b_B0_etaP_pi0_TrPval;   //!
    TBranch        *b_B0_etaP_pi1_d0;   //!
    TBranch        *b_B0_etaP_pi1_z0;   //!
    TBranch        *b_B0_etaP_pi1_TrPval;   //!
    TBranch        *b_B0_etaP_eta_pi0_nCDCHits;   //!
    TBranch        *b_B0_etaP_eta_pi0_nSVDHits;   //!
    TBranch        *b_B0_etaP_eta_pi0_nPXDHits;   //!
    TBranch        *b_B0_etaP_eta_pi1_nCDCHits;   //!
    TBranch        *b_B0_etaP_eta_pi1_nSVDHits;   //!
    TBranch        *b_B0_etaP_eta_pi1_nPXDHits;   //!
    TBranch        *b_B0_etaP_pi0_nCDCHits;   //!
    TBranch        *b_B0_etaP_pi0_nSVDHits;   //!
    TBranch        *b_B0_etaP_pi0_nPXDHits;   //!
    TBranch        *b_B0_etaP_pi1_nCDCHits;   //!
    TBranch        *b_B0_etaP_pi1_nSVDHits;   //!
    TBranch        *b_B0_etaP_pi1_nPXDHits;   //!
    TBranch        *b_B0_etaP_pi0_nCDCHits;   //!
    TBranch        *b_B0_etaP_pi0_nSVDHits;   //!
    TBranch        *b_B0_etaP_pi0_nPXDHits;   //!
    TBranch        *b_B0_etaP_pi1_nCDCHits;   //!
    TBranch        *b_B0_etaP_pi1_nSVDHits;   //!
    TBranch        *b_B0_etaP_pi1_nPXDHits;   //!
    TBranch        *b_B0_MC_MOTHER_ID;   //!
    TBranch        *b_B0_MC_GD_MOTHER_ID;   //!
    TBranch        *b_B0_MC_GD_GD_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_MC_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_MC_GD_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_MC_GD_GD_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_eta_MC_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_eta_MC_GD_MOTHER_ID;   //!
    TBranch        *b_B0_etaP_eta_MC_GD_GD_MOTHER_ID;   //!
    TBranch        *b_B0_K_S0_MC_MOTHER_ID;   //!
    TBranch        *b_B0_K_S0_MC_GD_MOTHER_ID;   //!
    TBranch        *b_B0_K_S0_MC_GD_GD_MOTHER_ID;   //!
    TBranch        *b_B0_TruthP;   //!
    TBranch        *b_B0_TruthP4;   //!
    TBranch        *b_B0_TruthM;   //!
    TBranch        *b_B0_etaP_TruthP;   //!
    TBranch        *b_B0_etaP_TruthP4;   //!
    TBranch        *b_B0_etaP_TruthM;   //!
    TBranch        *b_B0_etaP_eta_TruthP;   //!
    TBranch        *b_B0_etaP_eta_TruthP4;   //!
    TBranch        *b_B0_etaP_eta_TruthM;   //!
    TBranch        *b_B0_K_S0_TruthP;   //!
    TBranch        *b_B0_K_S0_TruthP4;   //!
    TBranch        *b_B0_K_S0_TruthM;   //!
    TBranch        *b_B0_X;   //!
    TBranch        *b_B0_ErrX;   //!
    TBranch        *b_B0_Y;   //!
    TBranch        *b_B0_ErrY;   //!
    TBranch        *b_B0_Z;   //!
    TBranch        *b_B0_ErrZ;   //!
    TBranch        *b_B0_Rho;   //!
    TBranch        *b_B0_VtxPvalue;   //!
    TBranch        *b_B0_etaP_X;   //!
    TBranch        *b_B0_etaP_ErrX;   //!
    TBranch        *b_B0_etaP_Y;   //!
    TBranch        *b_B0_etaP_ErrY;   //!
    TBranch        *b_B0_etaP_Z;   //!
    TBranch        *b_B0_etaP_ErrZ;   //!
    TBranch        *b_B0_etaP_Rho;   //!
    TBranch        *b_B0_etaP_VtxPvalue;   //!
    TBranch        *b_B0_etaP_eta_X;   //!
    TBranch        *b_B0_etaP_eta_ErrX;   //!
    TBranch        *b_B0_etaP_eta_Y;   //!
    TBranch        *b_B0_etaP_eta_ErrY;   //!
    TBranch        *b_B0_etaP_eta_Z;   //!
    TBranch        *b_B0_etaP_eta_ErrZ;   //!
    TBranch        *b_B0_etaP_eta_Rho;   //!
    TBranch        *b_B0_etaP_eta_VtxPvalue;   //!
    TBranch        *b_B0_etaP_eta_pi0_X;   //!
    TBranch        *b_B0_etaP_eta_pi0_ErrX;   //!
    TBranch        *b_B0_etaP_eta_pi0_Y;   //!
    TBranch        *b_B0_etaP_eta_pi0_ErrY;   //!
    TBranch        *b_B0_etaP_eta_pi0_Z;   //!
    TBranch        *b_B0_etaP_eta_pi0_ErrZ;   //!
    TBranch        *b_B0_etaP_eta_pi0_Rho;   //!
    TBranch        *b_B0_etaP_eta_pi0_VtxPvalue;   //!
    TBranch        *b_B0_etaP_eta_pi1_X;   //!
    TBranch        *b_B0_etaP_eta_pi1_ErrX;   //!
    TBranch        *b_B0_etaP_eta_pi1_Y;   //!
    TBranch        *b_B0_etaP_eta_pi1_ErrY;   //!
    TBranch        *b_B0_etaP_eta_pi1_Z;   //!
    TBranch        *b_B0_etaP_eta_pi1_ErrZ;   //!
    TBranch        *b_B0_etaP_eta_pi1_Rho;   //!
    TBranch        *b_B0_etaP_eta_pi1_VtxPvalue;   //!
    TBranch        *b_B0_etaP_pi0_X;   //!
    TBranch        *b_B0_etaP_pi0_ErrX;   //!
    TBranch        *b_B0_etaP_pi0_Y;   //!
    TBranch        *b_B0_etaP_pi0_ErrY;   //!
    TBranch        *b_B0_etaP_pi0_Z;   //!
    TBranch        *b_B0_etaP_pi0_ErrZ;   //!
    TBranch        *b_B0_etaP_pi0_Rho;   //!
    TBranch        *b_B0_etaP_pi0_VtxPvalue;   //!
    TBranch        *b_B0_etaP_pi1_X;   //!
    TBranch        *b_B0_etaP_pi1_ErrX;   //!
    TBranch        *b_B0_etaP_pi1_Y;   //!
    TBranch        *b_B0_etaP_pi1_ErrY;   //!
    TBranch        *b_B0_etaP_pi1_Z;   //!
    TBranch        *b_B0_etaP_pi1_ErrZ;   //!
    TBranch        *b_B0_etaP_pi1_Rho;   //!
    TBranch        *b_B0_etaP_pi1_VtxPvalue;   //!
    TBranch        *b_B0_K_S0_X;   //!
    TBranch        *b_B0_K_S0_ErrX;   //!
    TBranch        *b_B0_K_S0_Y;   //!
    TBranch        *b_B0_K_S0_ErrY;   //!
    TBranch        *b_B0_K_S0_Z;   //!
    TBranch        *b_B0_K_S0_ErrZ;   //!
    TBranch        *b_B0_K_S0_Rho;   //!
    TBranch        *b_B0_K_S0_VtxPvalue;   //!
    TBranch        *b_B0_TruthX;   //!
    TBranch        *b_B0_TruthY;   //!
    TBranch        *b_B0_TruthZ;   //!
    TBranch        *b_B0_TruthRho;   //!
    TBranch        *b_B0_etaP_TruthX;   //!
    TBranch        *b_B0_etaP_TruthY;   //!
    TBranch        *b_B0_etaP_TruthZ;   //!
    TBranch        *b_B0_etaP_TruthRho;   //!
    TBranch        *b_B0_etaP_eta_TruthX;   //!
    TBranch        *b_B0_etaP_eta_TruthY;   //!
    TBranch        *b_B0_etaP_eta_TruthZ;   //!
    TBranch        *b_B0_etaP_eta_TruthRho;   //!
    TBranch        *b_B0_etaP_eta_pi0_TruthX;   //!
    TBranch        *b_B0_etaP_eta_pi0_TruthY;   //!
    TBranch        *b_B0_etaP_eta_pi0_TruthZ;   //!
    TBranch        *b_B0_etaP_eta_pi0_TruthRho;   //!
    TBranch        *b_B0_etaP_eta_pi1_TruthX;   //!
    TBranch        *b_B0_etaP_eta_pi1_TruthY;   //!
    TBranch        *b_B0_etaP_eta_pi1_TruthZ;   //!
    TBranch        *b_B0_etaP_eta_pi1_TruthRho;   //!
    TBranch        *b_B0_etaP_pi0_TruthX;   //!
    TBranch        *b_B0_etaP_pi0_TruthY;   //!
    TBranch        *b_B0_etaP_pi0_TruthZ;   //!
    TBranch        *b_B0_etaP_pi0_TruthRho;   //!
    TBranch        *b_B0_etaP_pi1_TruthX;   //!
    TBranch        *b_B0_etaP_pi1_TruthY;   //!
    TBranch        *b_B0_etaP_pi1_TruthZ;   //!
    TBranch        *b_B0_etaP_pi1_TruthRho;   //!
    TBranch        *b_B0_K_S0_TruthX;   //!
    TBranch        *b_B0_K_S0_TruthY;   //!
    TBranch        *b_B0_K_S0_TruthZ;   //!
    TBranch        *b_B0_K_S0_TruthRho;   //!
    TBranch        *b_B0_TagVx;   //!
    TBranch        *b_B0_TagVy;   //!
    TBranch        *b_B0_TagVz;   //!
    TBranch        *b_B0_TagVex;   //!
    TBranch        *b_B0_TagVey;   //!
    TBranch        *b_B0_TagVez;   //!
    TBranch        *b_B0_TagVPvalue;   //!
    TBranch        *b_B0_TruthTagVx;   //!
    TBranch        *b_B0_TruthTagVy;   //!
    TBranch        *b_B0_TruthTagVz;   //!
    TBranch        *b_B0_DeltaT;   //!
    TBranch        *b_B0_mcTagPDG;   //!
    TBranch        *b_B0_TruthDeltaT;   //!
    TBranch        *b_B0_ThrustB;   //!
    TBranch        *b_B0_ThrustO;   //!
    TBranch        *b_B0_CosTBTO;   //!
    TBranch        *b_B0_CosTBz;   //!
    TBranch        *b_B0_R2;   //!
    TBranch        *b_B0_cc1;   //!
    TBranch        *b_B0_cc2;   //!
    TBranch        *b_B0_cc3;   //!
    TBranch        *b_B0_cc4;   //!
    TBranch        *b_B0_cc5;   //!
    TBranch        *b_B0_cc6;   //!
    TBranch        *b_B0_cc7;   //!
    TBranch        *b_B0_cc8;   //!
    TBranch        *b_B0_cc9;   //!
    TBranch        *b_B0_mm2;   //!
    TBranch        *b_B0_et;   //!
    TBranch        *b_B0_hso00;   //!
    TBranch        *b_B0_hso01;   //!
    TBranch        *b_B0_hso02;   //!
    TBranch        *b_B0_hso03;   //!
    TBranch        *b_B0_hso04;   //!
    TBranch        *b_B0_hso10;   //!
    TBranch        *b_B0_hso12;   //!
    TBranch        *b_B0_hso14;   //!
    TBranch        *b_B0_hso20;   //!
    TBranch        *b_B0_hso22;   //!
    TBranch        *b_B0_hso24;   //!
    TBranch        *b_B0_hoo0;   //!
    TBranch        *b_B0_hoo1;   //!
    TBranch        *b_B0_hoo2;   //!
    TBranch        *b_B0_hoo3;   //!
    TBranch        *b_B0_hoo4;   //!
    TBranch        *b_B0__isSignal;   //!
    TBranch        *b_B0_etaP__isSignal;   //!
    TBranch        *b_B0_etaP_eta__isSignal;   //!
    TBranch        *b_B0_etaP_eta_pi0__isSignal;   //!
    TBranch        *b_B0_K_S0__isSignal;   //!
    TBranch        *b_m_nCands;   //!
    TBranch        *b_m_iCand;   //!

    B0_ch4(TTree *tree=0);
    virtual ~B0_ch4();
    virtual Int_t    Cut(Long64_t entry);
    virtual Int_t    GetEntry(Long64_t entry);
    virtual Long64_t LoadTree(Long64_t entry);
    virtual void     Init(TTree *tree);
    virtual void     Loop(Long64_t maxEv=0);
    virtual Bool_t   Notify();
    virtual void     Show(Long64_t entry = -1);
    Long64_t selectBestCand(Long64_t jentry, Long64_t nCandsCurrent) ;
    void             createHisto(const TString& dir) ;
    void             fillHisto(const TString& dir, const TString& hname, const double& value) ;
    void             saveHisto(const TString& dir) ;
    void             fillHistos(const TString& dir) ;
  private:
    TFile* ofile;
};

#endif

#ifdef B0_ch4_cxx
B0_ch4::B0_ch4(TTree *tree) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../root_files/B0_etapr-eta-3pi2pi_KS-pi+pi-_output_signal.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("../root_files/B0_etapr-eta-3pi2pi_KS-pi+pi-_output_signal.root");
    }
    f->GetObject("B0",tree);

  }
  Init(tree);

  ofile=new TFile("Histo_ch4.root","RECREATE");
}

B0_ch4::~B0_ch4()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t B0_ch4::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t B0_ch4::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void B0_ch4::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("exp_no", &exp_no, &b_exp_no);
  fChain->SetBranchAddress("run_no", &run_no, &b_run_no);
  fChain->SetBranchAddress("evt_no", &evt_no, &b_evt_no);
  fChain->SetBranchAddress("B0_M", &B0_M, &b_B0_M);
  fChain->SetBranchAddress("B0_ErrM", &B0_ErrM, &b_B0_ErrM);
  fChain->SetBranchAddress("B0_SigM", &B0_SigM, &b_B0_SigM);
  fChain->SetBranchAddress("B0_eta'_M", &B0_etaP_M, &b_B0_etaP_M);
  fChain->SetBranchAddress("B0_eta'_ErrM", &B0_etaP_ErrM, &b_B0_etaP_ErrM);
  fChain->SetBranchAddress("B0_eta'_SigM", &B0_etaP_SigM, &b_B0_etaP_SigM);
  fChain->SetBranchAddress("B0_eta'_eta_M", &B0_etaP_eta_M, &b_B0_etaP_eta_M);
  fChain->SetBranchAddress("B0_eta'_eta_ErrM", &B0_etaP_eta_ErrM, &b_B0_etaP_eta_ErrM);
  fChain->SetBranchAddress("B0_eta'_eta_SigM", &B0_etaP_eta_SigM, &b_B0_etaP_eta_SigM);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_M", &B0_etaP_eta_pi0_M, &b_B0_etaP_eta_pi0_M);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_ErrM", &B0_etaP_eta_pi0_ErrM, &b_B0_etaP_eta_pi0_ErrM);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_SigM", &B0_etaP_eta_pi0_SigM, &b_B0_etaP_eta_pi0_SigM);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_charge", &B0_etaP_eta_pi0_charge, &b_B0_etaP_eta_pi0_charge);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_charge", &B0_etaP_eta_pi1_charge, &b_B0_etaP_eta_pi1_charge);
  fChain->SetBranchAddress("B0_eta'_pi0_charge", &B0_etaP_pi0_charge, &b_B0_etaP_pi0_charge);
  fChain->SetBranchAddress("B0_eta'_pi1_charge", &B0_etaP_pi1_charge, &b_B0_etaP_pi1_charge);
  fChain->SetBranchAddress("B0_K_S0_M", &B0_K_S0_M, &b_B0_K_S0_M);
  fChain->SetBranchAddress("B0_K_S0_ErrM", &B0_K_S0_ErrM, &b_B0_K_S0_ErrM);
  fChain->SetBranchAddress("B0_K_S0_SigM", &B0_K_S0_SigM, &b_B0_K_S0_SigM);
  fChain->SetBranchAddress("B0_P", &B0_P, &b_B0_P);
  fChain->SetBranchAddress("B0_P4", B0_P4, &b_B0_P4);
  fChain->SetBranchAddress("B0_eta'_P", &B0_etaP_P, &b_B0_etaP_P);
  fChain->SetBranchAddress("B0_eta'_P4", B0_etaP_P4, &b_B0_etaP_P4);
  fChain->SetBranchAddress("B0_eta'_eta_P", &B0_etaP_eta_P, &b_B0_etaP_eta_P);
  fChain->SetBranchAddress("B0_eta'_eta_P4", B0_etaP_eta_P4, &b_B0_etaP_eta_P4);
  fChain->SetBranchAddress("B0_K_S0_P", &B0_K_S0_P, &b_B0_K_S0_P);
  fChain->SetBranchAddress("B0_K_S0_P4", B0_K_S0_P4, &b_B0_K_S0_P4);
  fChain->SetBranchAddress("B0_Pcms", &B0_Pcms, &b_B0_Pcms);
  fChain->SetBranchAddress("B0_P4cms", B0_P4cms, &b_B0_P4cms);
  fChain->SetBranchAddress("B0_eta'_Pcms", &B0_etaP_Pcms, &b_B0_etaP_Pcms);
  fChain->SetBranchAddress("B0_eta'_P4cms", B0_etaP_P4cms, &b_B0_etaP_P4cms);
  fChain->SetBranchAddress("B0_eta'_eta_Pcms", &B0_etaP_eta_Pcms, &b_B0_etaP_eta_Pcms);
  fChain->SetBranchAddress("B0_eta'_eta_P4cms", B0_etaP_eta_P4cms, &b_B0_etaP_eta_P4cms);
  fChain->SetBranchAddress("B0_K_S0_Pcms", &B0_K_S0_Pcms, &b_B0_K_S0_Pcms);
  fChain->SetBranchAddress("B0_K_S0_P4cms", B0_K_S0_P4cms, &b_B0_K_S0_P4cms);
  fChain->SetBranchAddress("B0_mcPDG", &B0_mcPDG, &b_B0_mcPDG);
  fChain->SetBranchAddress("B0_mcErrors", &B0_mcErrors, &b_B0_mcErrors);
  fChain->SetBranchAddress("B0_eta'_mcPDG", &B0_etaP_mcPDG, &b_B0_etaP_mcPDG);
  fChain->SetBranchAddress("B0_eta'_mcErrors", &B0_etaP_mcErrors, &b_B0_etaP_mcErrors);
  fChain->SetBranchAddress("B0_eta'_eta_mcPDG", &B0_etaP_eta_mcPDG, &b_B0_etaP_eta_mcPDG);
  fChain->SetBranchAddress("B0_eta'_eta_mcErrors", &B0_etaP_eta_mcErrors, &b_B0_etaP_eta_mcErrors);
  fChain->SetBranchAddress("B0_K_S0_mcPDG", &B0_K_S0_mcPDG, &b_B0_K_S0_mcPDG);
  fChain->SetBranchAddress("B0_K_S0_mcErrors", &B0_K_S0_mcErrors, &b_B0_K_S0_mcErrors);
  fChain->SetBranchAddress("B0_deltae", &B0_deltae, &b_B0_deltae);
  fChain->SetBranchAddress("B0_mbc", &B0_mbc, &b_B0_mbc);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_PIDk", &B0_etaP_eta_pi0_PIDk, &b_B0_etaP_eta_pi0_PIDk);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_PIDpi", &B0_etaP_eta_pi0_PIDpi, &b_B0_etaP_eta_pi0_PIDpi);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_PIDe", &B0_etaP_eta_pi0_PIDe, &b_B0_etaP_eta_pi0_PIDe);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_PIDmu", &B0_etaP_eta_pi0_PIDmu, &b_B0_etaP_eta_pi0_PIDmu);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_PIDp", &B0_etaP_eta_pi0_PIDp, &b_B0_etaP_eta_pi0_PIDp);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_PIDk", &B0_etaP_eta_pi1_PIDk, &b_B0_etaP_eta_pi1_PIDk);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_PIDpi", &B0_etaP_eta_pi1_PIDpi, &b_B0_etaP_eta_pi1_PIDpi);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_PIDe", &B0_etaP_eta_pi1_PIDe, &b_B0_etaP_eta_pi1_PIDe);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_PIDmu", &B0_etaP_eta_pi1_PIDmu, &b_B0_etaP_eta_pi1_PIDmu);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_PIDp", &B0_etaP_eta_pi1_PIDp, &b_B0_etaP_eta_pi1_PIDp);
  fChain->SetBranchAddress("B0_eta'_pi0_PIDk", &B0_etaP_pi0_PIDk, &b_B0_etaP_pi0_PIDk);
  fChain->SetBranchAddress("B0_eta'_pi0_PIDpi", &B0_etaP_pi0_PIDpi, &b_B0_etaP_pi0_PIDpi);
  fChain->SetBranchAddress("B0_eta'_pi0_PIDe", &B0_etaP_pi0_PIDe, &b_B0_etaP_pi0_PIDe);
  fChain->SetBranchAddress("B0_eta'_pi0_PIDmu", &B0_etaP_pi0_PIDmu, &b_B0_etaP_pi0_PIDmu);
  fChain->SetBranchAddress("B0_eta'_pi0_PIDp", &B0_etaP_pi0_PIDp, &b_B0_etaP_pi0_PIDp);
  fChain->SetBranchAddress("B0_eta'_pi1_PIDk", &B0_etaP_pi1_PIDk, &b_B0_etaP_pi1_PIDk);
  fChain->SetBranchAddress("B0_eta'_pi1_PIDpi", &B0_etaP_pi1_PIDpi, &b_B0_etaP_pi1_PIDpi);
  fChain->SetBranchAddress("B0_eta'_pi1_PIDe", &B0_etaP_pi1_PIDe, &b_B0_etaP_pi1_PIDe);
  fChain->SetBranchAddress("B0_eta'_pi1_PIDmu", &B0_etaP_pi1_PIDmu, &b_B0_etaP_pi1_PIDmu);
  fChain->SetBranchAddress("B0_eta'_pi1_PIDp", &B0_etaP_pi1_PIDp, &b_B0_etaP_pi1_PIDp);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_d0", &B0_etaP_eta_pi0_d0, &b_B0_etaP_eta_pi0_d0);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_z0", &B0_etaP_eta_pi0_z0, &b_B0_etaP_eta_pi0_z0);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_TrPval", &B0_etaP_eta_pi0_TrPval, &b_B0_etaP_eta_pi0_TrPval);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_d0", &B0_etaP_eta_pi1_d0, &b_B0_etaP_eta_pi1_d0);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_z0", &B0_etaP_eta_pi1_z0, &b_B0_etaP_eta_pi1_z0);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_TrPval", &B0_etaP_eta_pi1_TrPval, &b_B0_etaP_eta_pi1_TrPval);
  fChain->SetBranchAddress("B0_eta'_pi0_d0", &B0_etaP_pi0_d0, &b_B0_etaP_pi0_d0);
  fChain->SetBranchAddress("B0_eta'_pi0_z0", &B0_etaP_pi0_z0, &b_B0_etaP_pi0_z0);
  fChain->SetBranchAddress("B0_eta'_pi0_TrPval", &B0_etaP_pi0_TrPval, &b_B0_etaP_pi0_TrPval);
  fChain->SetBranchAddress("B0_eta'_pi1_d0", &B0_etaP_pi1_d0, &b_B0_etaP_pi1_d0);
  fChain->SetBranchAddress("B0_eta'_pi1_z0", &B0_etaP_pi1_z0, &b_B0_etaP_pi1_z0);
  fChain->SetBranchAddress("B0_eta'_pi1_TrPval", &B0_etaP_pi1_TrPval, &b_B0_etaP_pi1_TrPval);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_nCDCHits", &B0_etaP_eta_pi0_nCDCHits, &b_B0_etaP_eta_pi0_nCDCHits);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_nSVDHits", &B0_etaP_eta_pi0_nSVDHits, &b_B0_etaP_eta_pi0_nSVDHits);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_nPXDHits", &B0_etaP_eta_pi0_nPXDHits, &b_B0_etaP_eta_pi0_nPXDHits);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_nCDCHits", &B0_etaP_eta_pi1_nCDCHits, &b_B0_etaP_eta_pi1_nCDCHits);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_nSVDHits", &B0_etaP_eta_pi1_nSVDHits, &b_B0_etaP_eta_pi1_nSVDHits);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_nPXDHits", &B0_etaP_eta_pi1_nPXDHits, &b_B0_etaP_eta_pi1_nPXDHits);
  fChain->SetBranchAddress("B0_eta'_pi0_nCDCHits", &B0_etaP_pi0_nCDCHits, &b_B0_etaP_pi0_nCDCHits);
  fChain->SetBranchAddress("B0_eta'_pi0_nSVDHits", &B0_etaP_pi0_nSVDHits, &b_B0_etaP_pi0_nSVDHits);
  fChain->SetBranchAddress("B0_eta'_pi0_nPXDHits", &B0_etaP_pi0_nPXDHits, &b_B0_etaP_pi0_nPXDHits);
  fChain->SetBranchAddress("B0_eta'_pi1_nCDCHits", &B0_etaP_pi1_nCDCHits, &b_B0_etaP_pi1_nCDCHits);
  fChain->SetBranchAddress("B0_eta'_pi1_nSVDHits", &B0_etaP_pi1_nSVDHits, &b_B0_etaP_pi1_nSVDHits);
  fChain->SetBranchAddress("B0_eta'_pi1_nPXDHits", &B0_etaP_pi1_nPXDHits, &b_B0_etaP_pi1_nPXDHits);
  fChain->SetBranchAddress("B0_MC_MOTHER_ID", &B0_MC_MOTHER_ID, &b_B0_MC_MOTHER_ID);
  fChain->SetBranchAddress("B0_MC_GD_MOTHER_ID", &B0_MC_GD_MOTHER_ID, &b_B0_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_MC_GD_GD_MOTHER_ID", &B0_MC_GD_GD_MOTHER_ID, &b_B0_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_MC_MOTHER_ID", &B0_etaP_MC_MOTHER_ID, &b_B0_etaP_MC_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_MC_GD_MOTHER_ID", &B0_etaP_MC_GD_MOTHER_ID, &b_B0_etaP_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_MC_GD_GD_MOTHER_ID", &B0_etaP_MC_GD_GD_MOTHER_ID, &b_B0_etaP_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_eta_MC_MOTHER_ID", &B0_etaP_eta_MC_MOTHER_ID, &b_B0_etaP_eta_MC_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_eta_MC_GD_MOTHER_ID", &B0_etaP_eta_MC_GD_MOTHER_ID, &b_B0_etaP_eta_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_eta'_eta_MC_GD_GD_MOTHER_ID", &B0_etaP_eta_MC_GD_GD_MOTHER_ID, &b_B0_etaP_eta_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_K_S0_MC_MOTHER_ID", &B0_K_S0_MC_MOTHER_ID, &b_B0_K_S0_MC_MOTHER_ID);
  fChain->SetBranchAddress("B0_K_S0_MC_GD_MOTHER_ID", &B0_K_S0_MC_GD_MOTHER_ID, &b_B0_K_S0_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_K_S0_MC_GD_GD_MOTHER_ID", &B0_K_S0_MC_GD_GD_MOTHER_ID, &b_B0_K_S0_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("B0_TruthP", &B0_TruthP, &b_B0_TruthP);
  fChain->SetBranchAddress("B0_TruthP4", B0_TruthP4, &b_B0_TruthP4);
  fChain->SetBranchAddress("B0_TruthM", &B0_TruthM, &b_B0_TruthM);
  fChain->SetBranchAddress("B0_eta'_TruthP", &B0_etaP_TruthP, &b_B0_etaP_TruthP);
  fChain->SetBranchAddress("B0_eta'_TruthP4", B0_etaP_TruthP4, &b_B0_etaP_TruthP4);
  fChain->SetBranchAddress("B0_eta'_TruthM", &B0_etaP_TruthM, &b_B0_etaP_TruthM);
  fChain->SetBranchAddress("B0_eta'_eta_TruthP", &B0_etaP_eta_TruthP, &b_B0_etaP_eta_TruthP);
  fChain->SetBranchAddress("B0_eta'_eta_TruthP4", B0_etaP_eta_TruthP4, &b_B0_etaP_eta_TruthP4);
  fChain->SetBranchAddress("B0_eta'_eta_TruthM", &B0_etaP_eta_TruthM, &b_B0_etaP_eta_TruthM);
  fChain->SetBranchAddress("B0_K_S0_TruthP", &B0_K_S0_TruthP, &b_B0_K_S0_TruthP);
  fChain->SetBranchAddress("B0_K_S0_TruthP4", B0_K_S0_TruthP4, &b_B0_K_S0_TruthP4);
  fChain->SetBranchAddress("B0_K_S0_TruthM", &B0_K_S0_TruthM, &b_B0_K_S0_TruthM);
  fChain->SetBranchAddress("B0_X", &B0_X, &b_B0_X);
  fChain->SetBranchAddress("B0_ErrX", &B0_ErrX, &b_B0_ErrX);
  fChain->SetBranchAddress("B0_Y", &B0_Y, &b_B0_Y);
  fChain->SetBranchAddress("B0_ErrY", &B0_ErrY, &b_B0_ErrY);
  fChain->SetBranchAddress("B0_Z", &B0_Z, &b_B0_Z);
  fChain->SetBranchAddress("B0_ErrZ", &B0_ErrZ, &b_B0_ErrZ);
  fChain->SetBranchAddress("B0_Rho", &B0_Rho, &b_B0_Rho);
  fChain->SetBranchAddress("B0_VtxPvalue", &B0_VtxPvalue, &b_B0_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_X", &B0_etaP_X, &b_B0_etaP_X);
  fChain->SetBranchAddress("B0_eta'_ErrX", &B0_etaP_ErrX, &b_B0_etaP_ErrX);
  fChain->SetBranchAddress("B0_eta'_Y", &B0_etaP_Y, &b_B0_etaP_Y);
  fChain->SetBranchAddress("B0_eta'_ErrY", &B0_etaP_ErrY, &b_B0_etaP_ErrY);
  fChain->SetBranchAddress("B0_eta'_Z", &B0_etaP_Z, &b_B0_etaP_Z);
  fChain->SetBranchAddress("B0_eta'_ErrZ", &B0_etaP_ErrZ, &b_B0_etaP_ErrZ);
  fChain->SetBranchAddress("B0_eta'_Rho", &B0_etaP_Rho, &b_B0_etaP_Rho);
  fChain->SetBranchAddress("B0_eta'_VtxPvalue", &B0_etaP_VtxPvalue, &b_B0_etaP_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_eta_X", &B0_etaP_eta_X, &b_B0_etaP_eta_X);
  fChain->SetBranchAddress("B0_eta'_eta_ErrX", &B0_etaP_eta_ErrX, &b_B0_etaP_eta_ErrX);
  fChain->SetBranchAddress("B0_eta'_eta_Y", &B0_etaP_eta_Y, &b_B0_etaP_eta_Y);
  fChain->SetBranchAddress("B0_eta'_eta_ErrY", &B0_etaP_eta_ErrY, &b_B0_etaP_eta_ErrY);
  fChain->SetBranchAddress("B0_eta'_eta_Z", &B0_etaP_eta_Z, &b_B0_etaP_eta_Z);
  fChain->SetBranchAddress("B0_eta'_eta_ErrZ", &B0_etaP_eta_ErrZ, &b_B0_etaP_eta_ErrZ);
  fChain->SetBranchAddress("B0_eta'_eta_Rho", &B0_etaP_eta_Rho, &b_B0_etaP_eta_Rho);
  fChain->SetBranchAddress("B0_eta'_eta_VtxPvalue", &B0_etaP_eta_VtxPvalue, &b_B0_etaP_eta_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_X", &B0_etaP_eta_pi0_X, &b_B0_etaP_eta_pi0_X);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_ErrX", &B0_etaP_eta_pi0_ErrX, &b_B0_etaP_eta_pi0_ErrX);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_Y", &B0_etaP_eta_pi0_Y, &b_B0_etaP_eta_pi0_Y);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_ErrY", &B0_etaP_eta_pi0_ErrY, &b_B0_etaP_eta_pi0_ErrY);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_Z", &B0_etaP_eta_pi0_Z, &b_B0_etaP_eta_pi0_Z);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_ErrZ", &B0_etaP_eta_pi0_ErrZ, &b_B0_etaP_eta_pi0_ErrZ);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_Rho", &B0_etaP_eta_pi0_Rho, &b_B0_etaP_eta_pi0_Rho);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_VtxPvalue", &B0_etaP_eta_pi0_VtxPvalue, &b_B0_etaP_eta_pi0_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_X", &B0_etaP_eta_pi1_X, &b_B0_etaP_eta_pi1_X);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_ErrX", &B0_etaP_eta_pi1_ErrX, &b_B0_etaP_eta_pi1_ErrX);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_Y", &B0_etaP_eta_pi1_Y, &b_B0_etaP_eta_pi1_Y);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_ErrY", &B0_etaP_eta_pi1_ErrY, &b_B0_etaP_eta_pi1_ErrY);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_Z", &B0_etaP_eta_pi1_Z, &b_B0_etaP_eta_pi1_Z);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_ErrZ", &B0_etaP_eta_pi1_ErrZ, &b_B0_etaP_eta_pi1_ErrZ);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_Rho", &B0_etaP_eta_pi1_Rho, &b_B0_etaP_eta_pi1_Rho);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_VtxPvalue", &B0_etaP_eta_pi1_VtxPvalue, &b_B0_etaP_eta_pi1_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_pi0_X", &B0_etaP_pi0_X, &b_B0_etaP_pi0_X);
  fChain->SetBranchAddress("B0_eta'_pi0_ErrX", &B0_etaP_pi0_ErrX, &b_B0_etaP_pi0_ErrX);
  fChain->SetBranchAddress("B0_eta'_pi0_Y", &B0_etaP_pi0_Y, &b_B0_etaP_pi0_Y);
  fChain->SetBranchAddress("B0_eta'_pi0_ErrY", &B0_etaP_pi0_ErrY, &b_B0_etaP_pi0_ErrY);
  fChain->SetBranchAddress("B0_eta'_pi0_Z", &B0_etaP_pi0_Z, &b_B0_etaP_pi0_Z);
  fChain->SetBranchAddress("B0_eta'_pi0_ErrZ", &B0_etaP_pi0_ErrZ, &b_B0_etaP_pi0_ErrZ);
  fChain->SetBranchAddress("B0_eta'_pi0_Rho", &B0_etaP_pi0_Rho, &b_B0_etaP_pi0_Rho);
  fChain->SetBranchAddress("B0_eta'_pi0_VtxPvalue", &B0_etaP_pi0_VtxPvalue, &b_B0_etaP_pi0_VtxPvalue);
  fChain->SetBranchAddress("B0_eta'_pi1_X", &B0_etaP_pi1_X, &b_B0_etaP_pi1_X);
  fChain->SetBranchAddress("B0_eta'_pi1_ErrX", &B0_etaP_pi1_ErrX, &b_B0_etaP_pi1_ErrX);
  fChain->SetBranchAddress("B0_eta'_pi1_Y", &B0_etaP_pi1_Y, &b_B0_etaP_pi1_Y);
  fChain->SetBranchAddress("B0_eta'_pi1_ErrY", &B0_etaP_pi1_ErrY, &b_B0_etaP_pi1_ErrY);
  fChain->SetBranchAddress("B0_eta'_pi1_Z", &B0_etaP_pi1_Z, &b_B0_etaP_pi1_Z);
  fChain->SetBranchAddress("B0_eta'_pi1_ErrZ", &B0_etaP_pi1_ErrZ, &b_B0_etaP_pi1_ErrZ);
  fChain->SetBranchAddress("B0_eta'_pi1_Rho", &B0_etaP_pi1_Rho, &b_B0_etaP_pi1_Rho);
  fChain->SetBranchAddress("B0_eta'_pi1_VtxPvalue", &B0_etaP_pi1_VtxPvalue, &b_B0_etaP_pi1_VtxPvalue);
  fChain->SetBranchAddress("B0_K_S0_X", &B0_K_S0_X, &b_B0_K_S0_X);
  fChain->SetBranchAddress("B0_K_S0_ErrX", &B0_K_S0_ErrX, &b_B0_K_S0_ErrX);
  fChain->SetBranchAddress("B0_K_S0_Y", &B0_K_S0_Y, &b_B0_K_S0_Y);
  fChain->SetBranchAddress("B0_K_S0_ErrY", &B0_K_S0_ErrY, &b_B0_K_S0_ErrY);
  fChain->SetBranchAddress("B0_K_S0_Z", &B0_K_S0_Z, &b_B0_K_S0_Z);
  fChain->SetBranchAddress("B0_K_S0_ErrZ", &B0_K_S0_ErrZ, &b_B0_K_S0_ErrZ);
  fChain->SetBranchAddress("B0_K_S0_Rho", &B0_K_S0_Rho, &b_B0_K_S0_Rho);
  fChain->SetBranchAddress("B0_K_S0_VtxPvalue", &B0_K_S0_VtxPvalue, &b_B0_K_S0_VtxPvalue);
  fChain->SetBranchAddress("B0_TruthX", &B0_TruthX, &b_B0_TruthX);
  fChain->SetBranchAddress("B0_TruthY", &B0_TruthY, &b_B0_TruthY);
  fChain->SetBranchAddress("B0_TruthZ", &B0_TruthZ, &b_B0_TruthZ);
  fChain->SetBranchAddress("B0_TruthRho", &B0_TruthRho, &b_B0_TruthRho);
  fChain->SetBranchAddress("B0_eta'_TruthX", &B0_etaP_TruthX, &b_B0_etaP_TruthX);
  fChain->SetBranchAddress("B0_eta'_TruthY", &B0_etaP_TruthY, &b_B0_etaP_TruthY);
  fChain->SetBranchAddress("B0_eta'_TruthZ", &B0_etaP_TruthZ, &b_B0_etaP_TruthZ);
  fChain->SetBranchAddress("B0_eta'_TruthRho", &B0_etaP_TruthRho, &b_B0_etaP_TruthRho);
  fChain->SetBranchAddress("B0_eta'_eta_TruthX", &B0_etaP_eta_TruthX, &b_B0_etaP_eta_TruthX);
  fChain->SetBranchAddress("B0_eta'_eta_TruthY", &B0_etaP_eta_TruthY, &b_B0_etaP_eta_TruthY);
  fChain->SetBranchAddress("B0_eta'_eta_TruthZ", &B0_etaP_eta_TruthZ, &b_B0_etaP_eta_TruthZ);
  fChain->SetBranchAddress("B0_eta'_eta_TruthRho", &B0_etaP_eta_TruthRho, &b_B0_etaP_eta_TruthRho);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_TruthX", &B0_etaP_eta_pi0_TruthX, &b_B0_etaP_eta_pi0_TruthX);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_TruthY", &B0_etaP_eta_pi0_TruthY, &b_B0_etaP_eta_pi0_TruthY);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_TruthZ", &B0_etaP_eta_pi0_TruthZ, &b_B0_etaP_eta_pi0_TruthZ);
  fChain->SetBranchAddress("B0_eta'_eta_pi0_TruthRho", &B0_etaP_eta_pi0_TruthRho, &b_B0_etaP_eta_pi0_TruthRho);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_TruthX", &B0_etaP_eta_pi1_TruthX, &b_B0_etaP_eta_pi1_TruthX);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_TruthY", &B0_etaP_eta_pi1_TruthY, &b_B0_etaP_eta_pi1_TruthY);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_TruthZ", &B0_etaP_eta_pi1_TruthZ, &b_B0_etaP_eta_pi1_TruthZ);
  fChain->SetBranchAddress("B0_eta'_eta_pi1_TruthRho", &B0_etaP_eta_pi1_TruthRho, &b_B0_etaP_eta_pi1_TruthRho);
  fChain->SetBranchAddress("B0_eta'_pi0_TruthX", &B0_etaP_pi0_TruthX, &b_B0_etaP_pi0_TruthX);
  fChain->SetBranchAddress("B0_eta'_pi0_TruthY", &B0_etaP_pi0_TruthY, &b_B0_etaP_pi0_TruthY);
  fChain->SetBranchAddress("B0_eta'_pi0_TruthZ", &B0_etaP_pi0_TruthZ, &b_B0_etaP_pi0_TruthZ);
  fChain->SetBranchAddress("B0_eta'_pi0_TruthRho", &B0_etaP_pi0_TruthRho, &b_B0_etaP_pi0_TruthRho);
  fChain->SetBranchAddress("B0_eta'_pi1_TruthX", &B0_etaP_pi1_TruthX, &b_B0_etaP_pi1_TruthX);
  fChain->SetBranchAddress("B0_eta'_pi1_TruthY", &B0_etaP_pi1_TruthY, &b_B0_etaP_pi1_TruthY);
  fChain->SetBranchAddress("B0_eta'_pi1_TruthZ", &B0_etaP_pi1_TruthZ, &b_B0_etaP_pi1_TruthZ);
  fChain->SetBranchAddress("B0_eta'_pi1_TruthRho", &B0_etaP_pi1_TruthRho, &b_B0_etaP_pi1_TruthRho);
  fChain->SetBranchAddress("B0_K_S0_TruthX", &B0_K_S0_TruthX, &b_B0_K_S0_TruthX);
  fChain->SetBranchAddress("B0_K_S0_TruthY", &B0_K_S0_TruthY, &b_B0_K_S0_TruthY);
  fChain->SetBranchAddress("B0_K_S0_TruthZ", &B0_K_S0_TruthZ, &b_B0_K_S0_TruthZ);
  fChain->SetBranchAddress("B0_K_S0_TruthRho", &B0_K_S0_TruthRho, &b_B0_K_S0_TruthRho);
  fChain->SetBranchAddress("B0_TagVx", &B0_TagVx, &b_B0_TagVx);
  fChain->SetBranchAddress("B0_TagVy", &B0_TagVy, &b_B0_TagVy);
  fChain->SetBranchAddress("B0_TagVz", &B0_TagVz, &b_B0_TagVz);
  fChain->SetBranchAddress("B0_TagVex", &B0_TagVex, &b_B0_TagVex);
  fChain->SetBranchAddress("B0_TagVey", &B0_TagVey, &b_B0_TagVey);
  fChain->SetBranchAddress("B0_TagVez", &B0_TagVez, &b_B0_TagVez);
  fChain->SetBranchAddress("B0_TagVPvalue", &B0_TagVPvalue, &b_B0_TagVPvalue);
  fChain->SetBranchAddress("B0_TruthTagVx", &B0_TruthTagVx, &b_B0_TruthTagVx);
  fChain->SetBranchAddress("B0_TruthTagVy", &B0_TruthTagVy, &b_B0_TruthTagVy);
  fChain->SetBranchAddress("B0_TruthTagVz", &B0_TruthTagVz, &b_B0_TruthTagVz);
  fChain->SetBranchAddress("B0_DeltaT", &B0_DeltaT, &b_B0_DeltaT);
  fChain->SetBranchAddress("B0_mcTagPDG", &B0_mcTagPDG, &b_B0_mcTagPDG);
  fChain->SetBranchAddress("B0_TruthDeltaT", &B0_TruthDeltaT, &b_B0_TruthDeltaT);
  fChain->SetBranchAddress("B0_ThrustB", &B0_ThrustB, &b_B0_ThrustB);
  fChain->SetBranchAddress("B0_ThrustO", &B0_ThrustO, &b_B0_ThrustO);
  fChain->SetBranchAddress("B0_CosTBTO", &B0_CosTBTO, &b_B0_CosTBTO);
  fChain->SetBranchAddress("B0_CosTBz", &B0_CosTBz, &b_B0_CosTBz);
  fChain->SetBranchAddress("B0_R2", &B0_R2, &b_B0_R2);
  fChain->SetBranchAddress("B0_cc1", &B0_cc1, &b_B0_cc1);
  fChain->SetBranchAddress("B0_cc2", &B0_cc2, &b_B0_cc2);
  fChain->SetBranchAddress("B0_cc3", &B0_cc3, &b_B0_cc3);
  fChain->SetBranchAddress("B0_cc4", &B0_cc4, &b_B0_cc4);
  fChain->SetBranchAddress("B0_cc5", &B0_cc5, &b_B0_cc5);
  fChain->SetBranchAddress("B0_cc6", &B0_cc6, &b_B0_cc6);
  fChain->SetBranchAddress("B0_cc7", &B0_cc7, &b_B0_cc7);
  fChain->SetBranchAddress("B0_cc8", &B0_cc8, &b_B0_cc8);
  fChain->SetBranchAddress("B0_cc9", &B0_cc9, &b_B0_cc9);
  fChain->SetBranchAddress("B0_mm2", &B0_mm2, &b_B0_mm2);
  fChain->SetBranchAddress("B0_et", &B0_et, &b_B0_et);
  fChain->SetBranchAddress("B0_hso00", &B0_hso00, &b_B0_hso00);
  fChain->SetBranchAddress("B0_hso01", &B0_hso01, &b_B0_hso01);
  fChain->SetBranchAddress("B0_hso02", &B0_hso02, &b_B0_hso02);
  fChain->SetBranchAddress("B0_hso03", &B0_hso03, &b_B0_hso03);
  fChain->SetBranchAddress("B0_hso04", &B0_hso04, &b_B0_hso04);
  fChain->SetBranchAddress("B0_hso10", &B0_hso10, &b_B0_hso10);
  fChain->SetBranchAddress("B0_hso12", &B0_hso12, &b_B0_hso12);
  fChain->SetBranchAddress("B0_hso14", &B0_hso14, &b_B0_hso14);
  fChain->SetBranchAddress("B0_hso20", &B0_hso20, &b_B0_hso20);
  fChain->SetBranchAddress("B0_hso22", &B0_hso22, &b_B0_hso22);
  fChain->SetBranchAddress("B0_hso24", &B0_hso24, &b_B0_hso24);
  fChain->SetBranchAddress("B0_hoo0", &B0_hoo0, &b_B0_hoo0);
  fChain->SetBranchAddress("B0_hoo1", &B0_hoo1, &b_B0_hoo1);
  fChain->SetBranchAddress("B0_hoo2", &B0_hoo2, &b_B0_hoo2);
  fChain->SetBranchAddress("B0_hoo3", &B0_hoo3, &b_B0_hoo3);
  fChain->SetBranchAddress("B0_hoo4", &B0_hoo4, &b_B0_hoo4);
  fChain->SetBranchAddress("B0__isSignal", &B0__isSignal, &b_B0__isSignal);
  fChain->SetBranchAddress("B0_eta'__isSignal", &B0_etaP__isSignal, &b_B0_etaP__isSignal);
  fChain->SetBranchAddress("B0_eta'_eta__isSignal", &B0_etaP_eta__isSignal, &b_B0_etaP_eta__isSignal);
  fChain->SetBranchAddress("B0_eta'_eta_pi0__isSignal", &B0_etaP_eta_pi0__isSignal, &b_B0_etaP_eta_pi0__isSignal);
  fChain->SetBranchAddress("B0_K_S0__isSignal", &B0_K_S0__isSignal, &b_B0_K_S0__isSignal);
  fChain->SetBranchAddress("nCands", &nCands, &b_m_nCands);
  fChain->SetBranchAddress("iCand", &iCand, &b_m_iCand);
  Notify();
}

void B0_ch4::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
#endif // #ifdef B0_ch4_cxx
