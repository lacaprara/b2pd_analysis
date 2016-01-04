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


#filelistSIG= ['../root_files/B0_etapr-eta-3pi2pi_KS-pi+pi-_gsim-BKGx0.root']
firstFile=0
nFiles=10
filelistSIGname='B0_etapr-eta-3pi2pi_KS-pi+pi-_gsim-BKGx0.list'
filelistSIGraw = open(filelistSIGname, 'r').readlines()
filelistSIG= [x.strip() for x in filelistSIGraw]

outFile = 'B0_etapr-eta-3pi2pi_KS-pi+pi-_output_signal.root'

inputMdstList(filelistSIG[firstFile:nFiles])
# printPrimaryMCParticles()
# printDataStore()

photons   = ('gamma:all',   '')
electrons = ('e-:all',      '')
muons     = ('mu-:all',     '')
pions     = ('pi-:all',     '')
kaons     = ('K-:all',      '')
protons   = ('anti-p-:all', '')

#fillParticleListsFromMC([photons, electrons, muons, pions, kaons, protons])
fillParticleLists([photons, electrons, muons, pions, kaons, protons])

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
vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst")
matchMCTruth('B0')
#printDataStore()
rankByHighest('B0',"chiProb")

# get the rest of the event:
buildRestOfEvent('B0')

# get tag vertex ('breco' is the type of MC association)
TagV('B0', 'breco')

# get continuum suppression (needed for flavor tagging)
buildContinuumSuppression('B0')


# FlavorTagger(mode='Expert',
#              weightFiles='B2JpsiKs_mu')
# #             workingDirectory=os.environ['BELLE2_LOCAL_DIR'] + '/analysis/data',

# create and fill flat Ntuple with MCTruth and kinematic information
toolsEta = ['EventMetaData', '^eta:3pi']
toolsEta += ['InvMass', '^eta:3pi']
toolsEta += ['CMSKinematics', '^eta:3pi']
toolsEta += ['CustomFloats[isSignal]', '^eta:3pi']

toolsEtaP = ['InvMass', "^eta' -> ^eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['Kinematics', "^eta' -> eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['CMSKinematics', "^eta' -> eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['MCTruth', "^eta' -> ^eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['CustomFloats[isSignal]', "^eta' -> ^eta:3pi ^pi+:all ^pi-:all"]

toolsK0 = ['InvMass', '^K_S0:mdst']

toolsBsig = ['EventMetaData', '^B0']
toolsBsig += ['InvMass', "B0 -> [eta' -> [eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['InvMass[BeforeFit]', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all ^pi0:all] pi+:all pi-:all] K_S0:mdst"]
toolsBsig += ['Charge', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:mdst"]
toolsBsig += ['DeltaEMbc', '^B0']
toolsBsig += ['PID', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:mdst"]
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

#toolsRS = ['RecoStats', '^B0']

# save stuff to root file
ntupleFile(outFile)
# ntupleTree('Eta', 'eta:3pi', toolsEta)
# ntupleTree('EtaP', "eta'", toolsEtaP)
# ntupleTree('K0', 'K_S0:mdst', toolsK0)
ntupleTree('B0', 'B0', toolsBsig)
#ntupleTree('RecoStats', 'B0', toolsRS)

# Process the events
process(analysis_main)

# print out the summary
print statistics
