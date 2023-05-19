//
// Created by spaul on 19/05/2023.
//
#include "anallat/ANALLAT_utils.hpp"

BEGIN_ANALLAT_NAMESPACE

void initializeCommonOptions(int argc, char **argv){

    ConfigParser CommonOptionsParser;
    auto opt = CommonOptionsParser.MakeOptions();
    try {
        opt->parse(argc, argv);
    }
    catch (const CLI::ParseError &e) {
        opt->exit(e);
    }
    std::cout<<opt->config_to_str(true, true);
    CommonOptionsParser.ParseConfig();
}

END_ANALLAT_NAMESPACE