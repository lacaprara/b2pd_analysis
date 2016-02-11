#!/usr/bin/env python

######################################################
#
# Get started with B0 -> eta'(eta (gamma gamma) pi+pi-) K0
#
# These are the channels that are going to be 
# investigated:
#
# Author: Stefano Lacaprara  <lacaprara@pd.infn.it>  INFN Padova
#
#
#####################################################

import sys

from basf2 import *
from modularAnalysis import *
from stdLooseFSParticles import stdVeryLoosePi
from stdLooseFSParticles import stdLoosePi
from stdLooseFSParticles import stdLooseK

firstFile=0
nFiles=10
what='signal'
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
    #filelistSIG= ['payload_skim_*_ddbar/B0_etapr_eta2pi_KS_skim_ddbar_*.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_uubar.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ddbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ssbar.root']
    filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ccbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_mixed.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_charged.root']
    #filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_skim_signal.root']
    filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']#
    # filelistSIG+= ['outputUdst_Signal.root']
    # filelistSIG+= ['outputUdst_ccbar.root']

    inputMdstList(filelistSIG)

else:
    filelistSIGnames={
        'signal':'B0_etapr-eta-gg2pi_KS-pi+pi-_Skim_gsim-BKGx0.list',
        'uubar':'BackgroundSkim_uubar_BGx1.list',
        'ddbar':'BackgroundSkim_ddbar_BGx1.list',
        'ssbar':'BackgroundSkim_ssbar_BGx1.list',
        'ccbar':'BackgroundSkim_ccbar_BGx1.list',
        'mixed':'BackgroundSkim_mixed_BGx1.list',
        'charged':'BackgroundSkim_charged_BGx1.list'
    }

    filelistSIGraw = open(filelistSIGnames[what], 'r').readlines()
    filelistSIG= [x.strip() for x in filelistSIGraw]
    inputMdstList(filelistSIG[firstFile:nFiles])

outFile = 'B0_etapr-eta-gg2pi_KS-pi+pi-_output_'+what+'.root'

#printPrimaryMCParticles()

photons   = ('gamma:all',   '')
pions     = ('pi-:all',     '')

#fillParticleListsFromMC([photons, electrons, muons, pions, kaons, protons])
#fillParticleLists([photons, electrons, muons, pions, kaons, protons])
fillParticleLists([photons, pions])

# reconstruct D0 -> K- pi+ decay

cutAndCopyList('gamma:good','gamma:all','0.060 < E < 6.000 and -150 < clusterTiming < 0 and clusterE9E25 > 0.75')
calibratePhotonEnergy('gamma:good', 0.0064)
reconstructDecay('eta:gg -> gamma:good gamma:good', '0.400 < M < .700')
massKFit('eta:gg',0.0)
applyCuts('eta:gg','0.490 < M < 0.600')
matchMCTruth("eta:gg")

reconstructDecay("eta' -> eta:gg pi+:all pi-:all", '0.5 < M < 1.3')
massKFit("eta'",0.0)
applyCuts("eta'",'0.945 < M < 0.970')
matchMCTruth("eta'")

fillParticleList('K_S0:mdst','0.3 < M < 0.7')
vertexRave('K_S0:mdst', 0.0)
#vertexKFit('K_S0:mdst', 0.0)
applyCuts('K_S0:mdst','0.48 < M < 0.520')
#reconstructDecay('K_S0:pp -> pi+:all pi-:all', '0.3 < M < 1.0')
matchMCTruth('K_S0:mdst')

reconstructDecay("B0 -> eta' K_S0:mdst", 'Mbc > 5.2 and abs(deltaE) < 0.2')
vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst")
matchMCTruth('B0')

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
    methods = [('LPCA', 'Likelihood', 'H:V:!TransformOutput:PDFInterpol=Spline2:NSmoothSig[0]=20:NSmoothBkg[0]=20:NSmooth=5:NAvEvtPerBin=50:VarTransform=PCA'),
               ('FastBDT', 'Plugin', 'H:V:CreateMVAPdfs:NTrees=100:Shrinkage=0.10:RandRatio=0.5:NCutLevel=8:NTreeLayers=3')
              ]      
               #('NeuroBayes', 'Plugin', 'H:V:CreateMVAPdfs:NtrainingIter=20:Preprocessing=612:ShapeTreat=DIAG:TrainingMethod=BFGS')


    # TMVA training/testing
    teacher = register_module('TMVATeacher')
    teacher.param('prefix', 'B0_EtaPrK0_ch1_TMVA')
    teacher.param('methods', methods)
    teacher.param('variables', variables)
    teacher.param('target', 'isContinuumEvent')
    teacher.param('listNames', ['B0'])
    teacher.param('workingDirectory', 'training_ch1')
    analysis_main.add_module(teacher)

if action == 'expert':
    # run the expert mode
    methods = ['LPCA','FastBDT'] #, 'NeuroBayes']

    for method in methods:
        expert = register_module('TMVAExpert')
        expert.param('prefix', 'B0_EtaPrK0_ch1_TMVA')
        expert.param('method', method)
        expert.param('listNames', ['B0'])
        expert.param('expertOutputName', method + '_Probability')
        expert.param('workingDirectory', 'training_ch1')
        analysis_main.add_module(expert)

    # Network output
    networkOutput = ['extraInfo({method}_Probability)'.format(method=method) for method in methods]
    transformedNetworkOutputLPCA = ['transformedNetworkOutput(LPCA_Probability,0.,1.0)']
    #transformedNetworkOutputNB = ['transformedNetworkOutput(NeuroBayes_Probability,-0.9,1.0)']
    transformedNetworkOutputFBDT = ['transformedNetworkOutput(FastBDT_Probability,0.0,1.0)']

# create and fill flat Ntuple with MCTruth and kinematic information
toolsBsig = ['EventMetaData', '^B0']
toolsBsig += ['InvMass', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['InvMass[BeforeFit]', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] K_S0:mdst"]
toolsBsig += ['Charge', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['DeltaEMbc', '^B0']
toolsBsig += ['PID', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['DeltaLogL', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['Track', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['TrackHits', "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['MCHierarchy', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCKinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['Vertex', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCVertex', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] ^K_S0:mdst"]
toolsBsig += ['TagVertex', '^B0']
toolsBsig += ['MCTagVertex', '^B0']
toolsBsig += ['DeltaT', '^B0']
toolsBsig += ['MCDeltaT', '^B0']
toolsBsig += ['ContinuumSuppression', '^B0'] 
toolsBsig += ['CustomFloats[isSignal]', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_S0:mdst"]

if action == 'expert':
    toolsBsig += ['ContinuumSuppression', '^B0']
    toolsBsig += ['ContinuumSuppression[FS1]', '^B0']
    toolsBsig += ['CustomFloats[' + ':'.join(networkOutput) + ']', '^B0']
    toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputFBDT) + ']', '^B0']
    # toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputNB) + ']', '^B0']
    toolsBsig += ['CustomFloats[' + ':'.join(transformedNetworkOutputLPCA) + ']', '^B0']

# save stuff to root file
ntupleFile(outFile)
ntupleTree('B0', 'B0', toolsBsig)

toolsAll = ['EventMetaData']
ntupleTree('All', '', toolsAll)

# print out some further info
summaryOfLists(['eta:gg',"eta'",'B0'])

# Process the events
process(analysis_main)

# print out the summary
print statistics
