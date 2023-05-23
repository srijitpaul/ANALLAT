#ifndef ANALLAT_MONTECARLO_CONSTANTS_HPP
#define ANALLAT_MONTECARLO_CONSTANTS_HPP

#include <iostream>
#include <string>
#include <vector>
#include<variant>

//======== Monte Carlo constants =========//
struct MonteCarloOptions{

    std::string ensemble;// Ensemble name (e.g. "A40.24")
    std::string boundary;// Boundary conditions:{"periodic", "anti-periodic", "twisted", "open"}
    std::string collab;// Collaboration:{"Cyprus", "Mainz", "Edinburgh", "USQCD", "LHPC-Cyprus"}
    std::string action;// Action:{"Wilson-Clover", "Mobius", "Twisted-Mass", "Staggered", "Overlap", "Wilson"}
    std::vector<size_t> Nconf_per_replica;
    std::vector<std::vector<size_t>> special_configs;
    size_t  nstep_configs;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(MonteCarloOptions, ensemble, boundary, collab, action, Nconf_per_replica, special_configs, nstep_configs);

#endif