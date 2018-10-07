# Beam Simulations


*From Laura Fields on the LBNF beam simulations:*

Hi,

The location of neutrino ntuples for the latest beam design is here:

http://home.fnal.gov/~ljf26/2017DUNEFluxes/

These are in the dk2nu file format (dk2nu documentation, such as it is, is here: https://cdcvs.fnal.gov/redmine/projects/dk2nu/wiki) and are just lists of neutrinos decay kinematic information for 100,000 protons on target.  They don't include any timing information.  That is generally simulated in the next stage of simulation, which takes as input these flux files, information about the spill structure and detector geometry and spreads the neutrinos across a detector and in time.  The near detector group will have files that include timing information, although I am not sure they include the full flux record that you want.

If you want to proceed with the flux files, details on the spill structure can be found e.g. in the CDR:

https://docs.dunescience.org/cgi-bin/private/RetrieveFile?docid=4559&filename=CDR_Optimized_Beam_Oct02.pdf&version=12

Basically, the beam will come in spills of 7.5e13 protons/spill. The spills will be 10 microseconds long, divided into six batches (a la NuMI).  The spills will be 1.2 microseconds apart.  Assuming a 57% uptime, this corresponds to 1.1e21 protons/year.  

-Laura
