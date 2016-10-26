#!/usr/bin/env python

######################################################
#
# Get started with B0 -> eta'(eta (gamma gamma) pi+pi-) K0
#
# These are the channels that are going to be 
# investigated:
#   B0->eta'(->eta(->pi+pi-pi0)pi+pi-)K0S(pi+pi-)
#
# Author: Stefano Lacaprara  <lacaprara@pd.infn.it>  INFN Padova
#
#
#####################################################

import sys

from basf2 import *
from modularAnalysis import *
from FlavorTagger import *
from stdLooseFSParticles import stdVeryLoosePi
from stdLooseFSParticles import stdLoosePi
from stdLooseFSParticles import stdLooseK

## Parsing input argument
firstFile=0
nFiles=10
what='local'
action='simple'

if len(sys.argv) > 1:
    what=str(sys.argv[1])
    if (what not in {'signal','uubar','ddbar', 'ssbar', 'ccbar','mixed','charged','local'}):
            sys.exit("input has to be 'signal|uubar,ddbar,ssbar,ccbar,mixed,charged,local'")
if len(sys.argv) > 2:
    nFiles=int(sys.argv[2])
if len(sys.argv) > 3:
    firstFile=int(sys.argv[3])
    nFiles=firstFile+nFiles
if len(sys.argv) > 4:
    action=str(sys.argv[4])
    if (action not in {'simple','training','expert'}):
            sys.exit("action has to be 'simple|training|expert'")


if (what=='local'):
    filelistSIG= []
    filelistSIG +=['/b2data/lacaprar/work/rel-00-06-00/analysis/b2pd_analysis/root_files/Skim/B0_etapr_eta2pi_KS_skim_signal_ch4_0.root']
    # filelistSIG +=['/b2data/lacaprar/work/rel-00-06-00/analysis/b2pd_analysis/root_files/Skim/B0_etapr_eta2pi_KS_skim_signal_ch4_1.root']

    # filelistSIG +=['root://belle-dpm-01.na.infn.it//belle/TMP/belle/user/lacaprar/B0EtaPKs/BGx0/Prod2/BackgroundSkim_output_ccbar_0.root']
    # filelistSIG +=['root://belle-dpm-01.na.infn.it//belle/TMP/belle/user/lacaprar/B0EtaPKs/BGx0/Prod2/BackgroundSkim_output_ddbar_0.root']
    # filelistSIG +=['root://belle-dpm-01.na.infn.it//belle/TMP/belle/user/lacaprar/B0EtaPKs/BGx0/Prod2/BackgroundSkim_output_ssbar_0.root']
    filelistSIG +=['root://belle-dpm-01.na.infn.it//belle/TMP/belle/user/lacaprar/B0EtaPKs/BGx0/Prod2/BackgroundSkim_output_ddbar_0.root']
    inputMdstList(filelistSIG)

else:
    filelistSIGnames={
        'signal':'B0_etapr-eta-3pi2pi_KS-pi+pi-_Skim_gsim-BKGx0.list',
        'uubar':'BackgroundSkim_uubar_BGx0.list',
        'ddbar':'BackgroundSkim_ddbar_BGx0.list',
        'ssbar':'BackgroundSkim_ssbar_BGx0.list',
        'ccbar':'BackgroundSkim_ccbar_BGx0.list',
        'mixed':'BackgroundSkim_mixed_BGx0.list',
        'charged':'BackgroundSkim_charged_BGx0.list'
        # 'uubar':'BackgroundSkim_uubar_BGx1.list',
        # 'ddbar':'BackgroundSkim_ddbar_BGx1.list',
        # 'ssbar':'BackgroundSkim_ssbar_BGx1.list',
        # 'ccbar':'BackgroundSkim_ccbar_BGx1.list',
        # 'mixed':'BackgroundSkim_mixed_BGx1.list',
        # 'charged':'BackgroundSkim_charged_BGx1.list'
    }

    filelistSIGraw = open(filelistSIGnames[what], 'r').readlines()
    filelistSIG= [x.strip() for x in filelistSIGraw]
    inputMdstList(filelistSIG[firstFile:nFiles])

outFile = 'B0_etapr-eta-3pi2pi_KS-pi+pi-_output_'+what+'.root'

# printPrimaryMCParticles()
# printDataStore()

photons   = ('gamma:all',   '')
muons     = ('mu-:all',     '')
pions     = ('pi-:all',     '')
kaons     = ('K-:all',      '')

#fillParticleListsFromMC([photons, electrons, muons, pions, kaons, protons])
fillParticleLists([photons,  muons, pions, kaons])

# Gamma
cutAndCopyList('gamma:good','gamma:all','0.060 < E < 6.000 and -150 < clusterTiming < 0 and clusterE9E25 > 0.75')
calibratePhotonEnergy('gamma:good', 0.0064)

# reconstruct pi0->gg
reconstructDecay('pi0:all -> gamma:good gamma:good',' 0.080 < M < 0.200')
massKFit('pi0:all',0.0)
matchMCTruth('pi0:all')

# reconstruct eta->pi+pi-pi0
reconstructDecay('eta:3pi -> pi-:all pi+:all pi0:all', '0.400 < M < .700')
massKFit('eta:3pi',0.0)
applyCuts('eta:3pi','0.490 < M < 0.600')
matchMCTruth("eta:3pi")

# reconstruct eta'->eta pi+ pi-
reconstructDecay("eta' -> eta:3pi pi+:all pi-:all", '0.5 < M < 1.3')
massKFit("eta'",0.0)
applyCuts("eta'",'0.945 < M < 0.970')
matchMCTruth("eta'")

# Fill K_0S
fillParticleList('K_S0:mdst','0.3 < M < 0.7')
vertexRave('K_S0:mdst', 0.0)
#vertexKFit('K_S0:mdst', 0.0)
applyCuts('K_S0:mdst','0.48 < M < 0.520')
#reconstructDecay('K_S0:pp -> pi+:all pi-:all', '0.3 < M < 1.0')
matchMCTruth('K_S0:mdst')

# reconstruct B0->eta' K_S
reconstructDecay("B0 -> eta' K_S0:mdst", 'Mbc > 5.0 and abs(deltaE) < 0.5')
# No constraint
# vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst")
# as above but using also Ks constraint
# vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:mdst")
# same as above, but with the iptube beamspot constraint:
# vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst","iptube")
# now adding also the Ks constraint:
vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:mdst","iptube")

matchMCTruth('B0')
#printDataStore()
rankByHighest('B0',"chiProb")

# get the rest of the event:
buildRestOfEvent('B0')

# get tag vertex ('breco' is the type of MC association)
TagV('B0', 'breco')

# get continuum suppression (needed for flavor tagging)
buildContinuumSuppression('B0')

if action == 'training':

    # Define the input variables.
    variables = [
        'R2',
        'cosTBTO',
        'KSFWVariables(hso02)',
        'KSFWVariables(hso12)',
        'cosTBz',
        'CleoCone(9)',
        'thrustBm',
        'thrustOm',
        'KSFWVariables(et)',
        'KSFWVariables(mm2)',
        'KSFWVariables(hso00)',
        'KSFWVariables(hso04)',
        'KSFWVariables(hso10)',
        'KSFWVariables(hso14)',
        'KSFWVariables(hso20)',
        'KSFWVariables(hso22)',
        'KSFWVariables(hso24)',
        'KSFWVariables(hoo0)',
        'KSFWVariables(hoo1)',
        'KSFWVariables(hoo2)',
        'KSFWVariables(hoo3)',
        'KSFWVariables(hoo4)',
        'CleoCone(1)',
        'CleoCone(2)',
        'CleoCone(3)',
        'CleoCone(4)',
        'CleoCone(5)',
        'CleoCone(6)',
        'CleoCone(7)',
        'CleoCone(8)',
        ]


    # Define the methods.
    methods = [('FastBDT', 'Plugin', 'H:V:CreateMVAPdfs:NbinsMVAPdf=100:NTrees=100:Shrinkage=0.10:RandRatio=0.5:NCutLevel=8:NTreeLayers=3')]

     #[('LPCA', 'Likelihood', 'H:V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA'),
               #('NeuroBayes', 'Plugin', 'H:V:CreateMVAPdfs:NtrainingIter=20:Preprocessing=612:ShapeTreat=DIAG:TrainingMethod=BFGS')


    # TMVA training/testing
    teacher = register_module('TMVAOnTheFlyTeacher')
    teacher.param('prefix', 'B0_EtaPrK0_ch4_TMVA')
    teacher.param('methods', methods)
    teacher.param('variables', variables)
    teacher.param('target', 'isContinuumEvent')
    #teacher.param('target', 'isSignal')
    teacher.param('listNames', ['B0'])
    teacher.param('workingDirectory', 'training_ch4')
    analysis_main.add_module(teacher)

if action == 'expert':
    # run the expert mode
    #methods = ['LPCA','FastBDT'] #, 'NeuroBayes']
    methods = ['FastBDT'] #, 'NeuroBayes']

    for method in methods:
        expert = register_module('TMVAExpert')
        expert.param('prefix', 'B0_EtaPrK0_ch4_TMVA')
        expert.param('method', method)
        expert.param('listNames', ['B0'])
        expert.param('expertOutputName', method + '_Probability')
        expert.param('workingDirectory', 'training_ch4')
        analysis_main.add_module(expert)

    # Network output
    networkOutput = ['extraInfo({method}_Probability)'.format(method=method) for method in methods]
    #transformedNetworkOutputLPCA = ['transformedNetworkOutput(LPCA_Probability,0.,1.0)']
    #transformedNetworkOutputNB = ['transformedNetworkOutput(NeuroBayes_Probability,-0.9,1.0)']
    transformedNetworkOutputFBDT = ['transformedNetworkOutput(FastBDT_Probability,0.0,1.0)']

# FlavorTagger(mode='Expert',
#              weightFiles='B2JpsiKs_mu')
# #             workingDirectory=os.environ['BELLE2_LOCAL_DIR'] + '/analysis/data',

# create and fill flat Ntuple with MCTruth and kinematic information

toolsBsig = ['EventMetaData', '^B0']
toolsBsig += ['InvMass', "B0 -> [eta' -> [eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['InvMass[BeforeFit]', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all ^pi0:all] pi+:all pi-:all] K_S0:mdst"]
toolsBsig += ['Charge', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['DeltaEMbc', '^B0']
toolsBsig += ['PID', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['DeltaLogL', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['Track', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['TrackHits', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['MCHierarchy', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCKinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['Vertex', "^B0 -> [^eta' -> [^eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCVertex', "^B0 -> [^eta' -> [^eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:mdst"]
toolsBsig += ['TagVertex', '^B0']
toolsBsig += ['MCTagVertex', '^B0']
toolsBsig += ['DeltaT', '^B0']
toolsBsig += ['MCDeltaT', '^B0']
toolsBsig += ['ContinuumSuppression', '^B0'] 
toolsBsig += ['CustomFloats[isSignal]', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all ^pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['CustomFloats[isContinuumEvent]', "^B0"]

if action == 'expert':
    toolsBsig += ['ContinuumSuppression', '^B0']
    toolsBsig += ['ContinuumSuppression[FS1]', '^B0']
    toolsBsig += ['CustomFloats[' + ':'.join(networkOutput) + ']', '^B0']
    toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputFBDT) + ']', '^B0']
    # toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputNB) + ']', '^B0']
    # toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputLPCA) + ']', '^B0']

# save stuff to root file
ntupleFile(outFile)
ntupleTree('B0', 'B0', toolsBsig)

toolsAll = ['EventMetaData']
ntupleTree('All', '', toolsAll)

# print out some further info
summaryOfLists(['eta:3pi',"eta'",'B0'])

# Process the events
process(analysis_main)

# print out the summary
print(statistics)
