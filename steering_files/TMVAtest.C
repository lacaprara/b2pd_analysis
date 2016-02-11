#include "TMVA/Factory.h"
#include "TMVA/Tools.h"

void TMVAtest( )
{

  TMVA::Tools::Instance();
  TString thisdir = gSystem->DirName(gInterpreter->GetCurrentMacroName());
  gROOT->SetMacroPath(thisdir + ":" + gROOT->GetMacroPath() + ":/cvmfs/belle.cern.ch/sl6/externals/v00-05-09/share/root/tmva/");
  gROOT->ProcessLine(".L TMVAGui.C");

  TFile* outputFile = TFile::Open( "TMVA.root", "RECREATE" );
  TMVA::Factory *factory = new TMVA::Factory( "MVAnalysis", outputFile,"!V");
  TFile *input = TFile::Open("B0_EtaPrK0_ch1_TMVA.root");
  factory->AddSignalTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  factory->AddBackgroundTree ( (TTree*)input->Get("B0_EtaPrK0_ch1_TMVA_tree"), 1.0 );
  sigCut = TCut("isContinuumEvent==0");
  bgCut = TCut("isContinuumEvent==1");

  factory->AddVariable("R2", 'F');
  factory->AddVariable("cosTBTO", 'F');
  factory->AddVariable("KSFWVariableshso02", 'F');
  factory->AddVariable("KSFWVariableshso12", 'F');
  factory->AddVariable("cosTBz", 'F');
  factory->AddVariable("CleoCone9", 'F');
  factory->AddVariable("thrustBm", 'F');
  factory->AddVariable("thrustOm", 'F');
  factory->AddVariable("KSFWVariableset", 'F');
  factory->AddVariable("KSFWVariablesmm2", 'F');
  factory->AddVariable("KSFWVariableshso00", 'F');
  factory->AddVariable("KSFWVariableshso04", 'F');
  factory->AddVariable("KSFWVariableshso10", 'F');
  factory->AddVariable("KSFWVariableshso14", 'F');
  factory->AddVariable("KSFWVariableshso20", 'F');
  factory->AddVariable("KSFWVariableshso22", 'F');
  factory->AddVariable("KSFWVariableshso24", 'F');
  factory->AddVariable("KSFWVariableshoo0", 'F');
  factory->AddVariable("KSFWVariableshoo1", 'F');
  factory->AddVariable("KSFWVariableshoo2", 'F');
  factory->AddVariable("KSFWVariableshoo3", 'F');
  factory->AddVariable("KSFWVariableshoo4", 'F');
  factory->AddVariable("CleoCone1", 'F');
  factory->AddVariable("CleoCone2", 'F');
  factory->AddVariable("CleoCone3", 'F');
  factory->AddVariable("CleoCone4", 'F');
  factory->AddVariable("CleoCone5", 'F');
  factory->AddVariable("CleoCone6", 'F');
  factory->AddVariable("CleoCone7", 'F');
  factory->AddVariable("CleoCone8", 'F');
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
  if (!gROOT->IsBatch()) TMVAGui( "TMVA.root" );
}

KSFWVariableset          89839
KSFWVariablesmm2         95108
KSFWVariableshso00       92175
KSFWVariableshso04       96568
KSFWVariableshso10       90294
KSFWVariableshso14       96550
KSFWVariableshso20       92136
KSFWVariableshso22       96557
KSFWVariableshso24       96556
KSFWVariableshoo0        92123
KSFWVariableshoo1        96784
KSFWVariableshoo2        96067
KSFWVariableshoo3        96960
KSFWVariableshoo4        97008
CleoCone1                74065
CleoCone2                80543
CleoCone3                78537
CleoCone4                78083
CleoCone5                78762
CleoCone6                79199
CleoCone7                79472
CleoCone8                79311
