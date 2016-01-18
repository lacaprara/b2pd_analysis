#!/usr/bin/env python
# -*- coding: utf-8 -*-

# load all necessary scripts
import sys

from basf2 import *
from reconstruction import *

from modularAnalysis import *
from stdLooseFSParticles import stdVeryLoosePi
from stdLooseFSParticles import stdLoosePi
from stdLooseFSParticles import stdLooseK

firstFile=0
nFiles=10
what='signal'
if len(sys.argv) > 1:
    nFiles=int(sys.argv[1])
if len(sys.argv) > 2:
    firstFile=int(sys.argv[2])
    nFiles=firstFile+nFiles
if len(sys.argv) > 3:
    what=str(sys.argv[3])
    if (what not in {'signal','uubar','ddbar', 'ssbar', 'ccbar'}):
            sys.exit("input has to be 'signal|uubar,ddbar,ssbar,ccbar'")


# filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']
# inputMdstList(filelistSIG)

filelistSIGnames={
    'signal':'B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.list',
    'uubar':'Background_uubar_BGx1.list',
    'ddbar':'Background_ddbar_BGx1.list',
    'ssbar':'Background_ssbar_BGx1.list',
    'ccbar':'Background_ccbar_BGx1.list'
}

# load files
filelistSIGraw = open(filelistSIGnames[what], 'r').readlines()
filelistSIG= [x.strip() for x in filelistSIGraw]
inputMdstList(filelistSIG[firstFile:nFiles])

outFile = 'B0_etapr-eta-gg2pi_KS-pi+pi-_skim_'+what+'.root'


# create lists of FSPs
photons   = ('gamma:all',   '')
pions     = ('pi-:all',     '')

fillParticleLists([photons, pions])
#fillParticleListsFromMC([pions, photons], True)

cutAndCopyList('gamma:good','gamma:all','0.060 < E < 6.000 and -150 < clusterTiming < 0 and clusterE9E25 > 0.75')
calibratePhotonEnergy('gamma:good', 0.0064)
# pi0->gg
reconstructDecay('pi0:all -> gamma:good gamma:good',' 0.080 < M < 0.200')
# reconstruct eta->gg
reconstructDecay('eta:gg -> gamma:good gamma:good', '0.400 < M < .700')

# reconstruct eta->gg
reconstructDecay("eta':gg -> eta:gg pi+:all pi-:all", '0.5 < M < 1.3')

# reconstruct eta->pi+pi-pi0
reconstructDecay('eta:3pi -> pi-:all pi+:all pi0:all', '0.400 < M < .700')

# Ks ->pi+pi-
fillParticleList('K_S0:mdst','0.3 < M < 0.7')

# Ks ->pi0pi0
reconstructDecay('K_S0:neu -> pi0:all pi0:all', '0.35 < M < 0.6')

# channel 1
reconstructDecay("B0:ch1 -> eta':gg K_S0:mdst", 'Mbc > 5.2 and abs(deltaE) < 0.2')
# channel 2
reconstructDecay("B0:ch2 -> eta':gg K_S0:neu", 'Mbc > 5.0 and abs(deltaE) < 0.5')
# channel 4
reconstructDecay("B0:ch4 -> eta':3pi K_S0:mdst", 'Mbc > 5.0 and abs(deltaE) < 0.5')
# channel 5
reconstructDecay("B0:ch5 -> eta':gg K_S0:neu", 'Mbc > 5.0 and abs(deltaE) < 0.5')

# add SkimFilter module to set condition variable based on the number of reconstructed B-tag mesons
skim = register_module('SkimFilter')
skim.param('particleLists', ['B0:ch1','B0:ch2','B0:ch4','B0:ch5'])
analysis_main.add_module(skim)

# save event to a new mdst file if it contained at least one B-tag meson
empty_path = create_path()
skim.if_false(empty_path)
add_mdst_output(analysis_main, True, outFile)

# print out some further info
summaryOfLists(['eta:gg','eta:3pi',"eta':gg","eta':3pi",'B0:ch1','B0:ch2','B0:ch4','B0:ch5'])

# process the events
process(analysis_main)

# print out the summary
print statistics
