#!/usr/bin/env python

######################################################
#
# Get started with B0 -> eta'(eta (gamma gamma) pi+pi-) K0
#
# These are the channels that are going to be 
# investigated:
#   B0->eta'(->eta(->pi+pi-pi0)pi+pi-)K0S(pi0pi0)
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


filelistSIG= '../root_files/B0_etapr-eta-3pi2pi_KS-pi0pi0_gsim-BKGx0.root'
outFile = 'B0_etapr-eta-3pi2pi_KS-pi0pi0_output_signal.root'

inputMdstList(filelistSIG)
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

# reconstruct K_S->pi0 pi0
reconstructDecay('K_S0:neu -> pi0:all pi0:all', '0.4 < M < 0.6')
massKFit('K_S0:neu',0.0)
matchMCTruth('K_S0:neu')

# reconstruct B0->eta' K_S
reconstructDecay("B0 -> eta' K_S0:neu", 'Mbc > 5.0 and abs(deltaE) < 0.5')
vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:neu")
matchMCTruth('B0')
#printDataStore()
rankByHighest('B0',"chiProb")

# get the rest of the event:
buildRestOfEvent('B0')

# get tag vertex ('breco' is the type of MC association)
TagV('B0', 'breco')

# get continuum suppression (needed for flavor tagging)
buildContinuumSuppression('B0')

# create and fill flat Ntuple with MCTruth and kinematic information
toolsEta = ['EventMetaData', '^eta:2pi']
toolsEta += ['InvMass', '^eta:2pi']
toolsEta += ['CMSKinematics', '^eta:3pi']

toolsEtaP = ['InvMass', "^eta' -> ^eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['Kinematics', "^eta' -> eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['CMSKinematics', "^eta' -> eta:3pi ^pi+:all ^pi-:all"]
toolsEtaP += ['MCTruth', "^eta' -> ^eta:3pi ^pi+:all ^pi-:all"]

toolsK0 = ['InvMass', '^K_S0:neu']

toolsBsig = ['EventMetaData', '^B0']
# toolsBsig += ['InvMass', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['InvMass[BeforeFit]', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all ^pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['Charge', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:neu"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['DeltaEMbc', '^B0']
toolsBsig += ['PID', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:neu"]
toolsBsig += ['Track', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:neu"]
toolsBsig += ['TrackHits', "B0 -> [eta' -> [eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] K_S0:neu"]
toolsBsig += ['MCHierarchy', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['MCKinematics', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all pi0:all] pi+:all pi-:all] ^K_S0:neu"]
toolsBsig += ['Vertex', "^B0 -> [^eta' -> [^eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:neu"]
toolsBsig += ['MCVertex', "^B0 -> [^eta' -> [^eta:3pi -> ^pi-:all ^pi+:all pi0:all] ^pi+:all ^pi-:all] ^K_S0:neu"]
toolsBsig += ['TagVertex', '^B0']
toolsBsig += ['MCTagVertex', '^B0']
toolsBsig += ['DeltaT', '^B0']
toolsBsig += ['MCDeltaT', '^B0']
toolsBsig += ['ContinuumSuppression', '^B0'] 
#toolsBsig += ['CustomFloats[isSignal]', '^B0']
toolsBsig += ['CustomFloats[isSignal]', "^B0 -> [^eta' -> [^eta:3pi -> pi-:all pi+:all ^pi0:all] pi+:all pi-:all] ^K_S0:neu"]

#toolsRS = ['RecoStats', '^B0']

# save stuff to root file
ntupleFile(outFile)
# ntupleTree('Eta', 'eta:gg', toolsEta)
# ntupleTree('EtaP', "eta'", toolsEtaP)
# ntupleTree('K0', 'K_S0:neu', toolsK0)
ntupleTree('B0', 'B0', toolsBsig)
#ntupleTree('RecoStats', 'B0', toolsRS)


# Process the events
process(analysis_main)

# print out the summary
print statistics
