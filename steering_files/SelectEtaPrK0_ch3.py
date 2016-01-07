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
if len(sys.argv) > 1:
    nFiles=int(sys.argv[1])
if len(sys.argv) > 2:
    firstFile=int(sys.argv[2])
    nFiles=firstFile+nFiles


filelistSIG= 'B0_etapr-eta-gg2pi_KL_gsim-BKGx0.root'
outFile = 'B0_etapr-eta-gg2pi_KL_output_signal.root'

inputMdstList(filelistSIG)
# printPrimaryMCParticles()
# printDataStore()

photons   = ('gamma:all',   '')
electrons = ('e-:all',      '')
muons     = ('mu-:all',     '')
pions     = ('pi-:all',     '')
kaons     = ('K-:all',      '')
protons   = ('anti-p-:all', '')
KL        = ('K_L0:all', '')

#fillParticleListsFromMC([photons, electrons, muons, pions, kaons, protons])
fillParticleLists([photons, electrons, muons, pions, kaons, protons, KL])

# reconstruct eta->gg
cutAndCopyList('gamma:good','gamma:all','0.060 < E < 6.000 and -150 < clusterTiming < 0 and clusterE9E25 > 0.75')
calibratePhotonEnergy('gamma:good', 0.0064)
reconstructDecay('eta:gg -> gamma:good gamma:good', '0.400 < M < .700')
massKFit('eta:gg',0.0)
applyCuts('eta:gg','0.490 < M < 0.600')
matchMCTruth("eta:gg")

# reconstruct eta'->eta pi+ pi-
reconstructDecay("eta' -> eta:gg pi+:all pi+:all", '0.5 < M < 1.3')
massKFit("eta'",0.0)
applyCuts("eta'",'0.945 < M < 0.970')
matchMCTruth("eta'")

# Get KL
fillParticleList('K_L0:mdst',"")
printList('K_L0:mdst', False)
matchMCTruth('K_L0:mdst')

# reconstruct B0->eta' K_L
reconstructDecay("B0 -> eta' K_L0:mdst", 'Mbc > 5.0 and abs(deltaE) < 0.5')
#vertexRave('B0', 0.0, "B0 -> [eta' -> [eta:gg -> gamma:good gamma:good] ^pi+:all ^pi-:all] K_L0:mdst")
matchMCTruth('B0')

# get the rest of the event:
buildRestOfEvent('B0')

# get tag vertex ('breco' is the type of MC association)
TagV('B0', 'breco')

# create and fill flat Ntuple with MCTruth and kinematic information
toolsEta = ['EventMetaData', '^eta:gg']
toolsEta += ['InvMass', '^eta:gg']
toolsEta += ['CMSKinematics', '^eta:gg']

toolsEtaP = ['InvMass', "^eta' -> ^eta:gg ^pi+:all ^pi-:all"]
toolsEtaP += ['Kinematics', "^eta' -> eta:gg ^pi+:all ^pi-:all"]
toolsEtaP += ['CMSKinematics', "^eta' -> eta:gg ^pi+:all ^pi-:all"]
toolsEtaP += ['MCTruth', "^eta' -> ^eta:gg ^pi+:all ^pi-:all"]

toolsK0 = ['InvMass', '^K_L0:mdst']

toolsBsig = ['EventMetaData', '^B0']
toolsBsig += ['InvMass', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['Charge', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['DeltaEMbc', '^B0']
toolsBsig += ['PID', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['Track', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['TrackHits', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['MCHierarchy', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['MCKinematics', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['Vertex', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['MCVertex', "^B0 -> [^eta' -> [^eta:gg -> gamma:good gamma:good] pi+:all pi-:all] ^K_L0:mdst"]
toolsBsig += ['TagVertex', '^B0']
toolsBsig += ['MCTagVertex', '^B0']
toolsBsig += ['DeltaT', '^B0']
toolsBsig += ['MCDeltaT', '^B0']

#toolsRS = ['RecoStats', '^B0']

# save stuff to root file
ntupleFile(outFile)
ntupleTree('Eta', 'eta:gg', toolsEta)
ntupleTree('EtaP', "eta'", toolsEtaP)
ntupleTree('K0', 'K_L0:mdst', toolsK0)
ntupleTree('B0', 'B0', toolsBsig)
#ntupleTree('RecoStats', 'B0', toolsRS)


# Process the events
process(analysis_main)

# print out the summary
print statistics
