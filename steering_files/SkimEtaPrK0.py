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
    what=str(sys.argv[1])
    if (what not in {'signal_ch1','signal_ch2','signal_ch4','signal_ch4','signal_ch5','uubar','ddbar', 'ssbar', 'ccbar','mixed','charged'}):
            sys.exit("input has to be 'signal_chX|uubar,ddbar,ssbar,ccbar,mixed,charged'")
if len(sys.argv) > 2:
    nFiles=int(sys.argv[2])
if len(sys.argv) > 3:
    firstFile=int(sys.argv[3])
    nFiles=firstFile+nFiles


# filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']
# inputMdstList(filelistSIG)

if (what=='local'):
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_uubar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ddbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ssbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ccbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_mixed.root']
    filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_charged.root']
    #filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_skim_signal.root']
    inputMdstList(filelistSIG)

else:
    filelistSIGnames={
        'signal_ch1':'B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.list',
        'signal_ch2':'B0_etapr-eta-gg2pi_KS-pi0pi0_gsim-BKGx0.list',
        'signal_ch4':'B0_etapr-eta-3pi2pi_KS-pi+pi-_gsim-BKGx0.list',
        'signal_ch5':'B0_etapr-eta-3pi2pi_KS-pi0pi0_gsim-BKGx0.list',
        'uubar':'Background_uubar_BGx1.list',
        'ddbar':'Background_ddbar_BGx1.list',
        'ssbar':'Background_ssbar_BGx1.list',
        'ccbar':'Background_ccbar_BGx1.list',
        'mixed':'Background_mixed_BGx1.list',
        'charged':'Background_charged_BGx1.list'
    }

    # load files
    filelistSIGraw = open(filelistSIGnames[what], 'r').readlines()
    filelistSIG= [x.strip() for x in filelistSIGraw]
    inputMdstList(filelistSIG[firstFile:nFiles])

outFile = 'B0_etapr_eta2pi_KS_skim_'+what+'.root'


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

# reconstruct eta->pi+pi-pi0
reconstructDecay('eta:3pi -> pi-:all pi+:all pi0:all', '0.400 < M < .700')

# reconstruct eta'->gg2pi
reconstructDecay("eta':gg -> eta:gg pi+:all pi-:all", '0.5 < M < 1.3')
# reconstruct eta'->3pi2pi
reconstructDecay("eta':3pi -> eta:3pi pi+:all pi-:all", '0.5 < M < 1.3')

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
#reconstructDecay("B0:ch5 -> eta':3pi K_S0:neu", 'Mbc > 5.0 and abs(deltaE) < 0.5')

# add SkimFilter module to set condition variable based on the number of reconstructed B-tag mesons
skim = register_module('SkimFilter')
#skim.param('particleLists', ['B0:ch1','B0:ch2','B0:ch4','B0:ch5'])
skim.param('particleLists', ['B0:ch1','B0:ch2','B0:ch4'])
analysis_main.add_module(skim)

# save event to a new mdst file if it contained at least one B-tag meson
empty_path = create_path()
skim.if_false(empty_path)
add_mdst_output(analysis_main, True, outFile)

# print out some further info
#summaryOfLists(['eta:gg','eta:3pi',"eta':gg","eta':3pi",'B0:ch1','B0:ch2','B0:ch4','B0:ch5'])
summaryOfLists(['eta:gg','eta:3pi',"eta':gg","eta':3pi",'B0:ch1','B0:ch2','B0:ch4'])

# process the events
process(analysis_main)

# print out the summary
print(statistics)
