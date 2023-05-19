set(sources
    	src/tmp.cpp
		utils/ANALLAT_commandline_params.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
		include/anallat/tmp.hpp
    	include/anallat/ANALLAT.hpp
    	include/anallat/ANALLAT_global_includes.hpp
    	include/anallat/ANALLAT_utils.hpp
		include/anallat/ANALLAT_commandline_params.hpp
		include/anallat/global/ANALLAT_enums.hpp
		include/anallat/global/ANALLAT_macros.hpp
		include/anallat/global/ANALLAT_prints.hpp
		include/anallat/externals/CLI/CLI11.hpp
		include/anallat/externals/nlohmann/json.hpp
)

set(test_sources
  src/tmp_test.cpp
)
