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

## Parsing input argument
firstFile=0
nFiles=10
what='local'
action='simple'

if len(sys.argv) > 1:
    what=str(sys.argv[1])
    if (what not in {'signal','uubar','ddbar', 'ssbar', 'ccbar','mixed','charged','local','BGx0','BGx1'}):
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
    #filelistSIG +=['/gpfs/fs02/belle2/users/lacaprar/Work/rel-00-06-00/analysis/b2pd_analysis/production/payload_gen_ch1_0/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx1_0.root']
    #filelistSIG +=['./B0_etapr_eta2pi_KS_skim_local.root']
    #filelistSIG +=['./B0_etapr_eta2pi_KS_skim_BGx1.root']
    filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']

    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_uubar.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ddbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ssbar.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ccbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_mixed.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_charged.root']
    #filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_skim_signal.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']#
    # filelistSIG+= ['outputUdst_Signal.root']
    # filelistSIG+= ['outputUdst_ccbar.root']

    inputMdstList(filelistSIG)

elif (what=='BGx0'):
    filelistSIG= []
    filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']
    inputMdstList(filelistSIG)
elif (what=='BGx1'):
    filelistSIG= []
    filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx1.root']
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

outFile = 'B0_etapr-eta-gg2pi_KS-pi+pi-_outputMC_'+what+'.root'

fillParticleListFromMC("B0",'nDaughters==2 and daughter(0,mcPDG)==331 and daughter(1,mcPDG)==310 and daughter(1,daughter(0,mcPDG))==211 and daughter(1,daughter(1,mcPDG))==-211',True)

#fillParticleListFromMC("K_S0",'nDaughters==2 and daughter(0,mcPDG)==211 and daughter(1,mcPDG)==-211',True)
fillParticleList("pi-:all",'')
fillParticleList("gamma:all",'')

#printMCParticles()
#printList('B0', True)
#printList('K_S0', True)

# create and fill flat Ntuple with MCTruth and kinematic information
toolsBsig = ['EventMetaData', 'B0']
toolsBsig += ['MCTruth', "^B0 -> [^eta' -> [^eta -> ^gamma ^gamma] ^pi+ ^pi-] [^K_S0 -> ^pi+ ^pi-]"]
toolsBsig += ['MCKinematics', "^B0 -> [^eta' -> [^eta -> ^gamma ^gamma] ^pi+ ^pi-] [^K_S0 -> ^pi+ ^pi-]"]
toolsBsig += ['MCHierarchy', "^B0 -> [^eta' -> [^eta -> ^gamma ^gamma] ^pi+ ^pi-] [^K_S0 -> ^pi+ ^pi-]"]
toolsBsig += ['MCVertex', "^B0 -> [^eta' -> [^eta -> ^gamma ^gamma] ^pi+ ^pi-] [^K_S0 -> ^pi+ ^pi-]"]
toolsBsig += ['MCReconstructible', "^B0 -> [^eta' -> [^eta -> ^gamma ^gamma] ^pi+ ^pi-] [^K_S0 -> ^pi+ ^pi-]"]
toolsPi = ['MCKinematics', "pi-"]
toolsGam = ['MCKinematics', "gamma"]
# toolsBsig = ['EventMetaData', 'K_S0']
# toolsBsig += ['MCReconstructible', "^K_S0 -> ^pi+ ^pi-"]


# save stuff to root file
ntupleFile(outFile)
ntupleTree('B0', 'B0', toolsBsig)
ntupleTree('pi', 'pi-:all', toolsPi)
ntupleTree('gam', 'gamma:all', toolsGam)

# print out some further info
summaryOfLists(['B0'])

# Process the events
process(analysis_main)

# print out the summary
print(statistics)
