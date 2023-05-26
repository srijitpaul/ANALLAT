#ifndef ANALLAT_MONTECARLO_CONSTANTS_HPP
#define ANALLAT_MONTECARLO_CONSTANTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include<variant>

//======== Monte Carlo constants =========//
struct MonteCarloOptions{

    std::string                         Ensemble;// Ensemble name (e.g. "A40.24")
    std::string                         Boundary;// Boundary conditions:{"periodic", "anti-periodic", "twisted", "open"}
    std::string                         Collab;// Collaboration:{"Cyprus", "Mainz", "Edinburgh", "USQCD", "LHPC-Cyprus"}
    std::string                         Action;// Action:{"Wilson-Clover", "Mobius", "Twisted-Mass", "Staggered", "Overlap", "Wilson"}
    std::vector<size_t>                 NconfPerReplica;
    std::vector<std::vector<size_t>>    SpecialConfigs;
    size_t                              NskipConfigs;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MonteCarloOptions, Ensemble, Boundary, Collab, Action, NconfPerReplica, SpecialConfigs, NskipConfigs);

#endif