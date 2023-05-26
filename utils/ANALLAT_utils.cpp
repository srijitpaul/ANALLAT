//
// Created by spaul on 19/05/2023.
//
#include "anallat/ANALLAT_utils.hpp"

BEGIN_ANALLAT_NAMESPACE


//void InitializeOptions(int argc, char **argv){
//
//    ConfigParser OptionsParser;
//    auto opt = OptionsParser.MakeOptions();
//    try {
//        opt->parse(argc, argv);
//    }
//    catch (const CLI::ParseError &e) {
//        opt->exit(e);
//    }
//    std::cout<<opt->config_to_str(true, true);
//    OptionsParser.ParseGlobalConfig();
//    //const GlobalOptions GlobalOpt = anallat::ConfigParser::_GlobalOpt;
//    //std::cout<<"Test :"<<GlobalOpt.dimensions<<std::endl;
//    OptionsParser.ParseMonteCarloConfig();
//    if(isValidFile(OptionsParser.getSpectrumConfigPath())) {
//        OptionsParser.ParseSpectrumConfig();
//    }
//
//}

END_ANALLAT_NAMESPACE