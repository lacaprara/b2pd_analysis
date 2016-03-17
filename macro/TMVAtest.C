#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

void TMVAtest( )
{

  TFile* outputFile = TFile::Open( "TMVA.root", "RECREATE" );
  TMVA::Factory *factory = new TMVA::Factory( "MVAnalysis", outputFile,"!V");
  TFile *input = TFile::Open("../steering_files/training_ch1/B0_EtaPrK0_ch1_TMVA.root");
  factory->AddSignalTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  factory->AddBackgroundTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  sigCut = TCut("isContinuumEvent==1");
  bgCut = TCut("isContinuumEvent==0");

  factory->AddVariable("cosTBTO", 'F');
  factory->AddVariable("KSFWVariables__boet__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso10__bc", 'F');
  factory->AddVariable("KSFWVariables__bohoo0__bc", 'F');
  factory->AddVariable("R2", 'F');
  factory->AddVariable("KSFWVariables__bohso02__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso12__bc", 'F');
  factory->AddVariable("cosTBz", 'F');
  factory->AddVariable("CleoCone__bo9__bc", 'F');
  factory->AddVariable("thrustBm", 'F');
  factory->AddVariable("thrustOm", 'F');
  factory->AddVariable("KSFWVariables__bomm2__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso00__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso04__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso14__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso20__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso22__bc", 'F');
  factory->AddVariable("KSFWVariables__bohso24__bc", 'F');
  factory->AddVariable("KSFWVariables__bohoo1__bc", 'F');
  factory->AddVariable("KSFWVariables__bohoo2__bc", 'F');
  factory->AddVariable("KSFWVariables__bohoo3__bc", 'F');
  factory->AddVariable("KSFWVariables__bohoo4__bc", 'F');
  factory->AddVariable("CleoCone__bo1__bc", 'F');
  factory->AddVariable("CleoCone__bo2__bc", 'F');
  factory->AddVariable("CleoCone__bo3__bc", 'F');
  factory->AddVariable("CleoCone__bo3__bc", 'F');
  factory->AddVariable("CleoCone__bo4__bc", 'F');
  factory->AddVariable("CleoCone__bo5__bc", 'F');
  factory->AddVariable("CleoCone__bo6__bc", 'F');
  factory->AddVariable("CleoCone__bo7__bc", 'F');
  factory->AddVariable("CleoCone__bo8__bc", 'F');
  factory->PrepareTrainingAndTestTree(sigCut, bgCut, "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

  factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood", "H:V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA");
  //factory->BookMethod( TMVA::Types::kMLP, "MLP", "!V:NCycles=200:HiddenLayers=N+1,N:TestRate=5" );
  factory->BookMethod( TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );
  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();
  outputFile->Close();
  delete factory;

  // Launch the GUI for the root macros
  if (!gROOT->IsBatch()) TMVA::TMVAGui( "TMVA.root" );
}
