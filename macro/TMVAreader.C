#include "TMVA/Reader.h"
#include "TMVA/Tools.h"

void TMVAtest( )
{

  TMVA::Reader* reader = new TMVA::Reader( “Verbose“ );

  TFile* outputFile = TFile::Open( "TMVA.root", "RECREATE" );
  TMVA::Factory *factory = new TMVA::Factory( "MVAnalysis", outputFile,"!V");
  TFile *input = TFile::Open("../steering_files/training_ch1/B0_EtaPrK0_ch1_TMVA.root");
  factory->AddSignalTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  factory->AddBackgroundTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  sigCut = TCut("isContinuumEvent==0");
  bgCut = TCut("isContinuumEvent==1");

  reader->AddVariable("cosTBTO", 'F');
  reader->AddVariable("KSFWVariables__boet__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso10__bc", 'F');
  reader->AddVariable("KSFWVariables__bohoo0__bc", 'F');
  reader->AddVariable("R2", 'F');
  reader->AddVariable("KSFWVariables__bohso02__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso12__bc", 'F');
  reader->AddVariable("cosTBz", 'F');
  reader->AddVariable("CleoCone__bo9__bc", 'F');
  reader->AddVariable("thrustBm", 'F');
  reader->AddVariable("thrustOm", 'F');
  reader->AddVariable("KSFWVariables__bomm2__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso00__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso04__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso14__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso20__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso22__bc", 'F');
  reader->AddVariable("KSFWVariables__bohso24__bc", 'F');
  reader->AddVariable("KSFWVariables__bohoo1__bc", 'F');
  reader->AddVariable("KSFWVariables__bohoo2__bc", 'F');
  reader->AddVariable("KSFWVariables__bohoo3__bc", 'F');
  reader->AddVariable("KSFWVariables__bohoo4__bc", 'F');
  reader->AddVariable("CleoCone__bo1__bc", 'F');
  reader->AddVariable("CleoCone__bo2__bc", 'F');
  reader->AddVariable("CleoCone__bo3__bc", 'F');
  reader->AddVariable("CleoCone__bo4__bc", 'F');
  reader->AddVariable("CleoCone__bo5__bc", 'F');
  reader->AddVariable("CleoCone__bo6__bc", 'F');
  reader->AddVariable("CleoCone__bo7__bc", 'F');
  reader->AddVariable("CleoCone__bo8__bc", 'F');

  factory->PrepareTrainingAndTestTree(sigCut, bgCut, "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

  //factory->BookMethod( TMVA::Types::kLikelihood, "Likelihood", "H:V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA");
  //factory->BookMethod( TMVA::Types::kMLP, "MLP", "!V:NCycles=200:HiddenLayers=N+1,N:TestRate=5" );
  factory->BookMethod( TMVA::Types::kBDT, "BDT", "!H:!V:NTrees=850:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:UseBaggedBoost:BaggedSampleFraction=0.5:SeparationType=GiniIndex:nCuts=20" );
  factory->BookMethod( TMVA::Types::kBDT, "FastBDT", "!H:!V:CreateMVAPdfs:NbinsMVAPdf=40:NTrees=100:Shrinkage=0.10"); //:RandRatio=0.5:NCutLevel=8:NTreeLayers=3");

  factory->TrainAllMethods();
  factory->TestAllMethods();
  factory->EvaluateAllMethods();
  outputFile->Close();
  delete factory;

  // Launch the GUI for the root macros
  if (!gROOT->IsBatch()) TMVA::TMVAGui( "TMVA.root" );
}
