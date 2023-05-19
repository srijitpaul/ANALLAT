#ifndef ANALLAT_MONTECARLO_CONSTANTS_HPP
#define ANALLAT_MONTECARLO_CONSTANTS_HPP

#include <iostream>
#include <string>
#include <vector>

namespace anallat {

  //======== Monte Carlo constants =========//

extern const std::string  ensemble;// Ensemble name (e.g. "A40.24")
extern const std::string  boundary;// Boundary conditions:{"periodic", "antiperiodic", "twisted", "open"}
extern const std::string  collab;// Collaboration:{"Cyprus", "Mainz", "Edinburgh", "USQCD", "LHPC-Cyprus"}
extern const std::string  action;// Action:{"Wilson-Clover", "Mobius", "Twisted-Mass", "Staggered", "Overlap", "Wilson"}
}
#endif