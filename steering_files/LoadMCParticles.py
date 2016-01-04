#!/usr/bin/env python
# -*- coding: utf-8 -*-

#######################################################                                                                                     #
# This tutorial demonstrates how to load generated final
# state particles (MCParticle objects) as Particles and
# create ParticleLists for each final state particle
# type: gamma/e/mu/pi/K/proton/K_L.
#
# All analysis modules and tools (e.g. making combinations, ...)
# have interfaces for ParticleLists so this step is
# neccessary if analysis tools are to be used.
#
# Contributors: A. Zupanc (June 2014)
#
######################################################

from basf2 import *
from modularAnalysis import inputMdst
from modularAnalysis import printDataStore
from modularAnalysis import printList
from modularAnalysis import fillParticleListsFromMC
from modularAnalysis import printPrimaryMCParticles
from modularAnalysis import printVariableValues
from modularAnalysis import analysis_main


# load input ROOT file
# inputMdst('B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root')
inputMdst('../root_files/B0_etapr-eta-gg2pi_KS-pi0pi0_gsim-BKGx0.root')
# inputMdst('B0_etapr-eta-gg2pi_KL-_gsim-BKGx0.root')
# inputMdst('B0_etapr-eta-3pi2pi_KS-pi+pi-_gsim-BKGx0.root')

printPrimaryMCParticles()
# print contents of the DataStore before loading MCParticles
printDataStore()

# create and fill gamma/e/mu/pi/K/p ParticleLists
# second argument are the selection criteria: '' means no cut, take all
photons = ('gamma:gen', '')
electrons = ('e-:gen', '')
muons = ('mu-:gen', '')
pions = ('pi-:gen', '')
kaons = ('K-:gen', '')
kaonsneu = ('K_S0:gen', '')
protons = ('anti-p-:gen', '')

fillParticleListsFromMC([photons, electrons, muons, pions, kaons, kaonsneu, protons])

# print contents of the DataStore after loading MCParticles
# the difference is that DataStore now contains StoreArray<Particle>
# filled with Particles created from generated final state particles
printDataStore()

# print out the contents of each ParticleList
printList('gamma:gen', False)
printList('e-:gen', False)
printList('mu-:gen', False)
printList('pi-:gen', False)
printList('K-:gen', False)
printList('K_S0:gen', False)
printList('anti-p-:gen', False)

printVariableValues('K_S0:gen', ['charge', 'E', 'p'])
printVariableValues('pi-:gen', ['charge', 'px', 'py', 'pz'])

# Process the events
process(analysis_main)

# print out the summary
print statistics
