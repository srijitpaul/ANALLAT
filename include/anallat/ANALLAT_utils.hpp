#ifndef ANALLAT_UTILS_HPP
#define ANALLAT_UTILS_HPP

#include "ANALLAT_commandline_params.hpp"

BEGIN_ANALLAT_NAMESPACE

bool isValidFile(const std::string& filename);
//----------ANALLAT_utils.cpp---------------//
void InitializeOptions(int argc, char **argv);

//void MonteCarloOptions(int argc, char ** argv);

//void rotatedGEVPOptions(int argc, char **argv);

//void dispersionrelOptions(int argc, char **argv);

//void resamplingOptions(int argc, char **argv);

//void initializeANALLAT();

//void finalizeANALLAT();

END_ANALLAT_NAMESPACE

#endif  // ANALLAT_UTILS_HPP