#ifndef ANALLAT_UTILS_H_
#define ANALLAT_UTILS_H_

#include "utils/ANALLAT_commandline_helpers.hpp"

//using namespace anallat;


//----------ANALLAT_utils.cpp---------------//
void initializeOptions(int argc, char **argv);

void rotatedGEVPOptions(int argc, char **argv);

void dispersionrelOptions(int argc, char **argv);

void resamplingOptions(int argc, char **argv);

void initializeANALLAT();

void finalizeANALLAT();

#endif  // ANALLAT_UTILS_H_