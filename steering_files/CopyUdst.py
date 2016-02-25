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
from reconstruction import add_mdst_output

firstFile=0
nFiles=10
what='signal'
action='simple'
if len(sys.argv) > 1:
    what=str(sys.argv[1])
    if (what not in {'signal','uubar','ddbar', 'ssbar', 'ccbar','mixed','charged','local'}):
            sys.exit("input has to be 'signal|uubar,ddbar,ssbar,ccbar,mixed,charged,local'")

filelistSIG=[]
if (what=='local'):
    #filelistSIG= ['payload_skim_*_ddbar/B0_etapr_eta2pi_KS_skim_ddbar_*.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_uubar.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ddbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ssbar.root']
    filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_ccbar.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_mixed.root']
    #filelistSIG= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_skim_charged.root']
    #filelistSIG= ['B0_etapr-eta-gg2pi_KS-pi+pi-_skim_signal.root']
    #filelistSIG+= ['../root_files/ch1/B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.root']
    inputMdstList(filelistSIG)

else:
    filelistSIGnames={
        'signal':'B0_etapr-eta-gg2pi_KS-pi+pi-_gsim-BKGx0.list',
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

add_mdst_output(analysis_main, True, 'outputUdst.root')

# Process the events
process(analysis_main)

# print out the summary
print statistics
