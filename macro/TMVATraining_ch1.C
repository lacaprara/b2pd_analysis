#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

void TMVATraining_ch1( )
{

  TFile* outputFile = TFile::Open( "TMVA_ch1.root", "RECREATE" );
  TMVA::Factory *factory = new TMVA::Factory( "MVAnalysis", outputFile,"!V");
  TFile *signal = TFile::Open("../production/BGx0/Prod2_iptubeK0/B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal_iptubeK0.root");
  TFile *background = TFile::Open("../production/BGx0/Prod2_iptubeK0/B0_etapr-eta-gg2pi_KS-pi+pi-_output_ccbar_iptubeK0.root");
  factory->AddSignalTree ( (TTree*)signal->Get("B0"), 1.0 );
  factory->AddBackgroundTree ( (TTree*)background->Get("B0"), 1.0 );
  sigCut = TCut("B0__isContinuumEvent==0");
  bgCut = TCut("B0__isContinuumEvent==1");

  factory->AddVariable("B0_ThrustB",'F');
  factory->AddVariable("B0_ThrustO",'F');
  factory->AddVariable("B0_CosTBTO",'F');
  factory->AddVariable("B0_CosTBz",'F');
  factory->AddVariable("B0_R2",'F');
  factory->AddVariable("B0_cc1",'F');
  factory->AddVariable("B0_cc2",'F');
  factory->AddVariable("B0_cc3",'F');
  factory->AddVariable("B0_cc4",'F');
  factory->AddVariable("B0_cc5",'F');
  factory->AddVariable("B0_cc6",'F');
  factory->AddVariable("B0_cc7",'F');
  factory->AddVariable("B0_cc8",'F');
  factory->AddVariable("B0_cc9",'F');
  factory->AddVariable("B0_mm2",'F');
  factory->AddVariable("B0_et",'F');
  factory->AddVariable("B0_hso00",'F');
  // factory->AddVariable("B0_hso01",'F');
  factory->AddVariable("B0_hso02",'F');
  //factory->AddVariable("B0_hso03",'F');
  factory->AddVariable("B0_hso04",'F');
  factory->AddVariable("B0_hso10",'F');
  factory->AddVariable("B0_hso12",'F');
  factory->AddVariable("B0_hso14",'F');
  factory->AddVariable("B0_hso20",'F');
  factory->AddVariable("B0_hso22",'F');
  factory->AddVariable("B0_hso24",'F');
  factory->AddVariable("B0_hoo0",'F');
  factory->AddVariable("B0_hoo1",'F');
  factory->AddVariable("B0_hoo2",'F');
  factory->AddVariable("B0_hoo3",'F');
  factory->AddVariable("B0_hoo4",'F');

  factory->PrepareTrainingAndTestTree(sigCut, bgCut, "!V:nTrain_Signal=10000:nTest_Signal=10000:nTrain_Background=10000:nTest_Background=10000:SplitMode=Random:NormMode=NumEvents" );

  //factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood", "H:V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA");
  //factory->BookMethod( TMVA::Types::kMLP, "MLP", "!V:NCycles=200:HiddenLayers=N+1,N:TestRate=5" );
  factory->BookMethod( TMVA::Types::kMLP, "MLPBNN", "H:!V:NeuronType=tanh:VarTransform=N:NCycles=600:HiddenLayers=N+5:TestRate=5:TrainingMethod=BFGS:UseRegulator" );
  factory->BookMethod( TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );
  factory->BookMethod( TMVA::Types::kSVM, "SVM", "!H:!V:Gamma=0.25:Tol=0.001:VarTransform=Norm" );

  //factory->BookMethod( TMVA::Types::kBDT, "FastBDT", "!H:!V:CreateMVAPdfs:NbinsMVAPdf=40:NTrees=100:Shrinkage=0.10"); //:RandRatio=0.5:NCutLevel=8:NTreeLayers=3");

  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();
  outputFile->Close();
  delete factory;

  // Launch the GUI for the root macros
  if (!gROOT->IsBatch()) TMVA::TMVAGui( "TMVA_ch1.root" );
}
