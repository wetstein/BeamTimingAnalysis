# Beam Simulations


## From Laura Fields on the LBNF beam simulations:

Hi,

The location of neutrino ntuples for the latest beam design is here:

http://home.fnal.gov/~ljf26/2017DUNEFluxes/

These are in the dk2nu file format (dk2nu documentation, such as it is, is here: https://cdcvs.fnal.gov/redmine/projects/dk2nu/wiki) and are just lists of neutrinos decay kinematic information for 100,000 protons on target.  They don't include any timing information.  That is generally simulated in the next stage of simulation, which takes as input these flux files, information about the spill structure and detector geometry and spreads the neutrinos across a detector and in time.  The near detector group will have files that include timing information, although I am not sure they include the full flux record that you want.

If you want to proceed with the flux files, details on the spill structure can be found e.g. in the CDR:

https://docs.dunescience.org/cgi-bin/private/RetrieveFile?docid=4559&filename=CDR_Optimized_Beam_Oct02.pdf&version=12

Basically, the beam will come in spills of 7.5e13 protons/spill. The spills will be 10 microseconds long, divided into six batches (a la NuMI).  The spills will be 1.2 microseconds apart.  Assuming a 57% uptime, this corresponds to 1.1e21 protons/year.  

-Laura


## From Zarko Pavlovic on the LBNF Files:

Hi Matt,

I'll try to stop by ROC W after 4. In case you just need a general example how to run over dk2nu I attached an example. You would need to setup root, boost, and dk2nudata (assuming you are running on gpvms and can just do setup dk2nudata). 
To compile:
g++ -o beamHist beamHist.cc -L$DK2NUDATA_LIB -ldk2nuTree -I$DK2NUDATA_INC -I$BOOST_INC `root-config --glibs` -I$ROOT_INC -L$BOOST_LIB -lboost_program_options

To run:
./beamHist -i input_dk2nu.root -o output_hist_file.root -x 0 0 100000

This would loop over input file (could be multiple files with * and they'll get chained), and output flux histograms calculated at the location (x,y,z)=(0,0,100000)cm. It fills total flux, flux broken by immediate parent, flux broken by particle produced in initial proton interaction. (I used this for BNB, so histogram titles say pBe, but of course it is whatever you use in beam MC.)

Zarko


## From Zarko on the BNB files: 

Hi Matt,

I think I have similar files that were produced for SBND somewhere with more stats. These are intermediate files, so I'll have to look around a bit, but I believe they are somewhere on disk. However,  the ones that I made for SBND don't have multisim weight (which you might want for systematics).  I can make more files like the ones you are looking at. I just made few for Marcus to start looking at them and once we agree that they make sense the plan was for me to generate more. Since you are now looking at them and they seem reasonable, I can go ahead and generate more.

NuMI and LBNF use different format. The newest one that is used is called dk2nu (https://cdcvs.fnal.gov/redmine/projects/dk2nu/wiki/Wiki). Bit more complicated, but still not too bad :). It should contain pretty much same info, just the names of the variables will be different.

For NuMI you can likely get newer flux files from Minerva or NOvA. Leo Aliaga did a lot of flux work on Minerva. For more official request I'd ask spokespeople. Btw, Laura is also one of the conveners of beam group on DUNE so she can help with DUNE as well. I am a co-convener, but still in training :). Don't know yet where the most recent flux files are. I'll have to ask Laura and she is away this week...

Zarko


Hey Matt,

I started adding files to /annie/data/flux/redecay_bnb . Let me know if you have any problems with new files. Probably it is going to take few days to get all the files, but already now there are ~150 new files.

Zarko


## Instructions on How to Parse the LBNF Simulations

The dk2nu files have a more complicated structure. There are several branches:
* decay
* nuray
* ancestor
* traj
...in addition to a few other variables

ancestor_ gives the number of particles in the decay chain

nuray gives the momenta of the neutrinos
ancestor gives detailed information about the particles in the decay chain, wherhe ancestor_-1 is the nuetrino, -2 is the direct parent, etc
decay gives information on the decay that produced the particles (need to check on the details of that)

decay_nimpwt is the overall beam weight

but in the dk2nu files, there is a second weighting factor the reweights the existing decays for different angular acceptances corresponding to different baselines.

nuray_wgt[i] corresponds to this reweighting for different baselines. I forget what i=0 corresponds to but i=1 is near detector and i=2 is far detector


## Instructions on How to Parse the BNB Simulations

ini_pos[i][j] and ini_mom[i][j] are the initial position and momentum of the relavant particles. The second index (j) is the coordinate, where 0=x, 1=y, 2=z. The first index is step in the decay chain, counting backwards. So i=0 is the neutrino, whereas i=1,2,etc corresponds to successively earlier generations of parent particle.

ini_t[i] is the initial time, indexed by step in the decay chain.
ini_eng[i] is likewise the initial energy

npart is the number of particles in the decay chain

ntp is the neutrino type

id[i] is the particle id, counting backwards down the decay chain. So, i=1, is the direct parent of the neutrino

beamwgt is the beam weighting

