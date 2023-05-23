#ifndef ANALLAT_GLOBAL_INCLUDES_HPP
#define ANALLAT_GLOBAL_INCLUDES_HPP

//======== External libraries =========//
#include <typeinfo>
#include <typeindex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

#ifdef __GNUG__ // gnu C++ compiler
#include <cxxabi.h>
#endif

#include <new> // for availability of std::bad_alloc exception
#include <string>
#include <sstream>
#include <iostream>
#include <cassert>
#include <fstream>
#include <map>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <complex>

//======= External Libraries ===========//
#include "externals/nlohmann/json.hpp"
#include "externals/CLI/CLI11.hpp"


//======== Preprocessor macros =========//
#include "global/ANALLAT_macros.hpp"

//======== User Input Options ==========//
BEGIN_OPTIONS_NAMESPACE

#include "global/ANALLAT_global_options.hpp"
#include "global/ANALLAT_montecarlo_options.hpp"
#include "global/ANALLAT_spectrum_options.hpp"

const size_t ALIGNMENT_SIZE = 128;

using anallat_param_t = struct {
    struct GlobalOptions GlobalOpt;
    struct MonteCarloOptions MCOpt;
    struct SpectrumOptions SpectrumOpt;
} __attribute__((aligned(ALIGNMENT_SIZE)));

extern anallat_param_t anallat_global_param ;//NOLINT
END_OPTIONS_NAMESPACE

BEGIN_ANALLAT_NAMESPACE
//======== Containers ===============//
//#include <global/ANALLAT_xtensor.h>

//======== Utilities ================//
//#include "global/ANALLAT_utilities.hpp"

//======== Compile-Time constants =========//
#include "global/ANALLAT_compiletime_constants.hpp"

//======== ANALLAT_printf, ANALLAT_error, ANALLAT_warning =========//
#include "global/ANALLAT_prints.hpp"

//======== Enumerations =========//
#include "global/ANALLAT_enums.hpp"

END_ANALLAT_NAMESPACE

using namespace anallat; // TODO: This one shouldn't be here.. But helps avoiding missing namespace.

#endif