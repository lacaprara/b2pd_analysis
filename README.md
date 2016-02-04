# Analysis for Belle2

A repository to store my stuff for Belle2 analysis.
Stefano Lacaprara

## Current analysis is about time-dependent CP-violation using the `B0->eta'K` decay
Some literature:
  * BelleII http://dx.doi.org/10.1007/JHEP10(2014)165
  * BaBar http://journals.aps.org/prd/abstract/10.1103/PhysRevD.79.052003

## The channels considered so far are:

1. `eta'->eta(->gg) pi+ pi Ks->pi+ pi-`
2. `eta'->eta(->gg) pi+ pi Ks->pi0 pi0`
3. `eta'->eta(->gg) pi+ pi KL` (not yet)
4. `eta'->eta(->pi+ pi- pi-) pi+ pi Ks->pi+ pi-`
5. `eta'->eta(->pi+ pi- pi-) pi+ pi Ks->pi0 pi0`
6. `eta'->eta(->pi+ pi- pi-) pi+ pi KL` (not yet)

## Workflow:

1. Starting with the you own generated files
  1. create the signal root-file
    1. `cd steering_files`
    2. edit `GenSimAndReco-withoutBeamBkg.py` and select the correct `dec` file and the output file, as well as the wanted number of events
    3. run `basf2 GenSimAndReco-withoutBeamBkg.py`: time depends on # of events generated
    4. check the output file with `basf2 LoadMCParticles.py`
    5. I keep the produced root files in `root_files`

  2. run on the officially produced MC files
    1. dataset list (MC5) is available at https://www.google.com/url?q=https://belle2.cc.kek.jp/~twiki/bin/view/Computing/MCCampaign5th2015&usd=2&usg=AFQjCNGGgaDiJddUu3VzKtKd6si_JETjGw
    2. First step is to skim the large dataset, then you perform selection on the skim.
    3. Skim selection is SkimEtaPrK0.py and skim for all the four analysis channels. 
    4. there are a number of list of files (ls \*list), where all the files produced in the MC5 campaign are listed. These lists are used as input for the actual skimming
    5. run with `basf2 SkimEtaPrK0.py <Nfiles> <FirstFile> <Channel> (eg 1 0 ccbar)
    6. A script submit_lsf_skim.sh to process the list of files from the above list in lsf. *WARNING*: check carefully the file, expecially the loops, before executing it, since at full throttle it will submit a ton of jobs.
    7. an other script 'skimSummary.sh' loops through the log produced by lsf and count the input/output events

2. Run the selection, which reconstruct the wanted decay and produce a flat ntuple with the reconstructed informations:
  1. run `basf2 SelectEtaPrK0_ch1.py` (with ch1,2,3,4,5,6 depending on the channel)
  2. it produces an output file with name `B0_etapr-eta-gg2pi_KS-pi+pi-_output_signal.root` or similar for the other channels.
  3. As before, I keep the output files in `root_files`
  4. If you run on skim, there is a script which submit the needed jobs to lsf submit_lsf.sh: *WARNING*: as before, the loops inside can create a ton of jobs, use with care.
    7. an other script 'selectSummary.sh' loops through the log produced by lsf and count the input/output events

3.  Run the analysis, namely the selection of the best candidates among the many in each events, and produce some histogram for it.
  1. go to  `cd ../macro`
  2. run `root loop_ch1.C` (with ch1,2,3,4,5,6 depending on the channel)
  3. it creates a output file with the histograms `Histo_chX.root`
  4. it creates a number of canvas with some reference histograms, properly drawn, which are also save as `pdf` and `png` for use in slides or documents
  5. the macro `plot_ch.C` can be used to plot the histograms: a function `plot(int channel)` does the work. `plotAll()` plots all the histo for all the channels (suggest to run with root in batch mode: `root -b`)

4. Fit and signal extraction
  1. All is in directory fit
  2. Still setting up the machinery...
 
## TODO

* run the code on officially produced signal files from MC5
  * done for ch 1,2,4, and partially for 5 (jobs too long) DONE
* run also on background
  * continuum: which one? https://belle2.cc.kek.jp/~twiki/bin/viewauth/Computing/MC5Release4PhysicsGenericContinuum
    * first test on uu/dd/ss/cc DONE
    * need to perform some sort of base skimming in order to reduce the number of input events (see Alessandro's mail) DONE
    * understand how many events/files/subs correspond to how many fb-1 DONE
  * peaking (if any: which one?) TODO
* understand how to use continuum suppression variable TODO/Doing (but must understand the issue with CosTBTO first)
* understand how to run the actual flavour tagging algorithm TODO
* perform a multi dimensional likelihood fit of signal+backgound to extract the CPV parameters TODO/Doing
* document everything
