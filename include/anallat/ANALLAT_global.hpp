#pragma once
//======== External libraries =========//
#include <typeinfo>
#include <typeindex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>

//#ifdef __GNUG__ // gnu C++ compiler
//#include <cxxabi.h>
//#include <stdlib.h>
//#endif

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
//======== Preprocessor macros =========//
#include "global/ANALLAT_macros.hpp"

//======== Containers ===============//
//#include <global/ANALLAT_xtensor.h>

//======== Utilities ================//
#include "global/ANALLAT_utilities.hpp"

namespace anallat {
//======== ANALLAT_printf, ANALLAT_error, ANALLAT_warning =========//
#include "global/ANALLAT_prints.hpp"

//======== Enumerations =========//
#include "global/ANALLAT_enums.hpp"

//======== Global constants =========//
//#include <ANALLAT_global_constants.h>


}

using namespace anallat; // TODO: This one shouldn't be here.. But helps avoiding missing namespace.
