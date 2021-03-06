/* maximal set of features usable at the same time */
#define PARTIAL_PERIODIC
#define ELECTROSTATICS
#define COULOMB_DEBYE_HUECKEL
#define DIPOLES
#define ROTATION
#define ROTATIONAL_INERTIA
#define PARTICLE_ANISOTROPY
#define EXTERNAL_FORCES
#define CONSTRAINTS
#define MASS
#define EXCLUSIONS
#define COMFORCE
#define COMFIXED
#define MOLFORCES

#ifdef FFTW
#define MODES
#endif

#define BOND_CONSTRAINT
#define BOND_VIRTUAL
#define COLLISION_DETECTION
#define LANGEVIN_PER_PARTICLE
#define ROTATION_PER_PARTICLE
#define CATALYTIC_REACTIONS
#define REACTION_ENSEMBLE

#define NEMD
#define NPT 
#define GHMC

#define LB
#define LB_BOUNDARIES
#define LB_ELECTROHYDRODYNAMICS

#define ENGINE

#ifdef CUDA
#define LB_GPU
#define LB_BOUNDARIES_GPU
#define ELECTROKINETICS
#define EK_BOUNDARIES
#define EK_ELECTROSTATIC_COUPLING
#define MMM1D_GPU
#define EWALD_GPU
#endif

#define AREA_FORCE_GLOBAL   
#define VOLUME_FORCE   

#define TABULATED
#define LENNARD_JONES
#define LENNARD_JONES_GENERIC
#define LJGEN_SOFTCORE
#define LJCOS
#define LJCOS2
#define GAUSSIAN
#define HAT
#define LJ_ANGLE
#define GAY_BERNE
#define SMOOTH_STEP
#define HERTZIAN
#define BMHTF_NACL
#define MORSE
#define BUCKINGHAM
#define SOFT_SPHERE
#define INTER_RF
#define OVERLAPPED

#define TWIST_STACK
#define HYDROGEN_BOND

#define BOND_ANGLE
#define BOND_ANGLEDIST
#define BOND_ANGLEDIST_HARMONIC
#define BOND_ENDANGLEDIST
#define BOND_ENDANGLEDIST_HARMONIC

#define VIRTUAL_SITES_RELATIVE
#define FLATNOISE

#define ADDITIONAL_CHECKS
