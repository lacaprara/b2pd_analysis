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


filelistSIG= 'B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root'
outFile = 'B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root'

inputMdstList(filelistSIG)
#printPrimaryMCParticles()

photons   = ('gamma:all',   '')
electrons = ('e-:all',      '')
muons     = ('mu-:all',     '')
pions     = ('pi-:all',     '')
kaons     = ('K-:all',      '')
protons   = ('anti-p-:all', '')

fillParticleListsFromMC([photons, electrons, muons, pions, kaons, protons])

# reconstruct D0 -> K- pi+ decay

reconstructDecay('eta:gg -> gamma:all gamma:all', '0.3 < M < 1.0')

reconstructDecay("eta' -> eta:gg pi+:all pi-:all", '0.5 < M < 1.3')

reconstructDecay('K_S0:pp -> pi+:all pi-:all', '0.3 < M < 1.0')

reconstructDecay("B0 -> eta' K_S0:pp", 'Mbc > 5.2 and abs(deltaE) < 0.2')

# get the rest of the event:
buildRestOfEvent('B0')


# create and fill flat Ntuple with MCTruth and kinematic information
toolsEta = ['EventMetaData', '^eta:gg']
toolsEta += ['InvMass', '^eta:gg']
toolsEta += ['CMSKinematics', '^eta:gg']

toolsEtaP = ['InvMass', "^eta' -> ^eta:gg"]

toolsK0 = ['InvMass', '^K_S0:pp']

toolsBsig = ['EventMetaData', '^B0']
toolsBsig += ['InvMass', "^B0 -> [^eta' -> [^eta:gg -> gamma:all gamma:all] pi+:all pi-:all] ^K_S0"]
toolsBsig += ['Charge', "^B0 -> [^eta' -> eta:gg pi+:all pi-:all] ^K_S0"]
toolsBsig += ['Kinematics', "^B0 -> [^eta' -> eta:gg pi+:all pi-:all] ^K_S0"]
toolsBsig += ['CMSKinematics', "^B0 -> [^eta' -> eta:gg pi+:all pi-:all] ^K_S0"]
toolsBsig += ['DeltaEMbc', '^B0']

# save stuff to root file
ntupleFile(outFile)
ntupleTree('Eta', 'eta:gg', toolsEta)
ntupleTree('EtaP', "eta'", toolsEtaP)
ntupleTree('K0', 'K_S0:pp', toolsK0)
ntupleTree('B0', 'B0', toolsBsig)

# Process the events
process(analysis_main)

# print out the summary
print statistics
