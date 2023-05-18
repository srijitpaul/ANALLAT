#ifndef ANALLAT_MONTECARLO_CONSTANTS_H_
#define ANALLAT_MONTECARLO_CONSTANTS_H_

#include <iostream>
#include <string>
#include <vector>

namespace anallat {

  //======== Monte Carlo constants =========//

extern const std::string  ensemble;// Ensemble name (e.g. "A40.24")
extern const std::string  boundary;// Boundary conditions:{"periodic", "antiperiodic", "twisted", "open"}
extern const std::string  collab;// Collaboration:{"Cyprus", "Mainz", "Edinburgh", "USQCD", "LHPC-Cyprus"}
extern const std::string  action;// Action:{"Wilson-Clover", "Mobius", "Twisted-Mass", "Staggered", "Overlap", "Wilson"}
extern const size_t       nconfigs;// Number of configurations
}
#endif