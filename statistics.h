#ifndef STATISTICS_H
#define STATISTICS_H
/** \file statistics.h
    This file contains the code for simply statistics on the data.

    <b>Responsible:</b>
    <a href="mailto:mann@mpip-mainz.mpg.de">BAM</a>

*/

#include <tcl.h>
#include "particle_data.h"
#include "utils.h"

/** \name Data Types */
/************************************************************/
/*@{*/

typedef struct {
  /** Status flag for observable calculation. 0 re-initialize observable
      struct, 1 every thing is fine, calculation can start. */
  int init_status;

  /** Array for observables on each node. */
  DoubleList node;
  /** Array for observables summed over all nodes. */
  DoubleList sum;

  /** number of observables. */
  int n;
  /** number of observables before specific interaction observables. */
  int n_pre;
  /** number of observables for bonded interactions. */
  int n_bonded;
  /** number of observables for non-bonded interactions. */
  int n_non_bonded;
  /** number of observables for coulomb interaction. */
  int n_coulomb;

  /** analyze specified observable. */
  int ana_num;
} Observable_stat;

/*@}*/

/** \name Exported Variables
    Previous particle configurations (needed for offline analysis
    and correlation analysis in \ref #analyze)
*/
/************************************************************/
/*@{*/
extern double **configs;
extern int n_configs;
extern int n_part_conf;
/*@}*/

/** \name Exported Functions */
/************************************************************/
/*@{*/

/** Implements the Tcl command \ref tcl_analyze. This allows for basic system analysis,
    both online and offline.
*/
int analyze(ClientData data, Tcl_Interp *interp, int argc, char **argv);

/** the minimal distance of two particles with types in set1 rsp. set2.
    @param set1 types of particles
    @param set2 types of particles
    @return the minimal distance of two particles */
double mindist(IntList *set1, IntList *set2);

/** returns all particles within a given radius r_catch around a position.
    @param pos position of sphere of point
    @param r_catch the radius around the position
    @param il the list where to store the particles indices */
void nbhood(double pos[3], double r_catch, IntList *il);

/** minimal distance to point.
    @param pos point
    @param pid  if a valid particle id, this particle is omitted from minimization
                (this is a good idea if the posx, posy, posz is the position of a particle).
    @return the minimal distance of a particle to coordinates (<posx>, <posy>, <posz>). */
double distto(double pos[3], int pid);


/** appends particles' positions in 'partCfg' to \ref #configs */
void analyze_append();

/** appends the configuration stored in 'config[3*count]' to \ref #configs
    @param config the configuration which should be added 
    @param count  how many particles in 'config' */
void analyze_configs(double *config, int count);

/** removes configs[0], pushes all entries forward, appends current 'partCfg' to last spot */
void analyze_push();

/** replaces configs[ind] with current 'partCfg'
    @param ind the entry in \ref #configs to be replaced */
void analyze_replace(int ind);

/** removes configs[ind] and shrinks the array accordingly
    @param ind the entry in \ref #configs to be removed */
void analyze_remove(int ind);

/** Calculates the distribution of particles around others. 
    Calculates the distance distribution of particles with types given
    in the p1_types list around particles with types given in the
    p2_types list. The distances range from r_min to r_max, binned
    into r_bins bins which are either aequidistant (log_flag==0)or
    logarithmically aequidistant (log_flag==1). The result is stored
    in the array dist.
    @param p1_types list with types of particles to find the distribution for.
    @param n_p1     length of p1_types.
    @param p2_types list with types of particles the others are distributed around.
    @param n_p2     length of p2_types.
    @param r_min    Minimal distance for the distribution.
    @param r_max    Maximal distance for the distribution.
    @param r_bins   Number of bins.
    @param log_flag Wether the bins are (logarithmically) aequidistant.
    @param low      particles closer than r_min
    @param dist     Array to store the result (size: r_bins).
 */
void calc_part_distribution(int *p1_types, int n_p1, int *p2_types, int n_p2, 
			    double r_min, double r_max, int r_bins, int log_flag,
			    double *low, double *dist);
/** Calculates the radial distribution function.

    Calculates the radial distribution function of particles with
    types given in the p1_types list around particles with types given
    in the p2_types list. The range is given by r_min and r_max and
    the distribution function is binned into r_bin bins, which are
    equidistant. The result is stored in the array rdf.

    @param p1_types list with types of particles to find the distribution for.
    @param n_p1     length of p1_types.
    @param p2_types list with types of particles the others are distributed around.
    @param n_p2     length of p2_types.
    @param r_min    Minimal distance for the distribution.
    @param r_max    Maximal distance for the distribution.
    @param r_bins   Number of bins.
    @param rdf     Array to store the result (size: r_bins).
*/
void calc_rdf(int *p1_types, int n_p1, int *p2_types, int n_p2, 
	      double r_min, double r_max, int r_bins, double *rdf);

/** returns the minimal squared distance between two positions in the perhaps periodic
    simulation box.
 *  \param pos1[3]  Position one.
 *  \param pos2[3]  Position two.
 */
double min_distance2(double pos1[3], double pos2[3]);

/** returns the minimal distance between two positions in the perhaps periodic
    simulation box.
 *  \param pos1[3]  Position one.
 *  \param pos2[3]  Position two.
 */
MDINLINE double min_distance(double pos1[3], double pos2[3]) {
  return sqrt(min_distance2(pos1, pos2));
}

/*@}*/

#endif
