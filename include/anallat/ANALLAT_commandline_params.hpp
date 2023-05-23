#ifndef ANALLAT_COMMANDLINE_PARAMS_HPP
#define ANALLAT_COMMANDLINE_PARAMS_HPP

#include <iostream>
#include <string>
#include <array>
#include <utility>
#include "anallat/ANALLAT_global_includes.hpp"

using json = nlohmann::json;
using option = CLI::App;

BEGIN_ANALLAT_NAMESPACE

class ConfigParser {

private:
    json config_;
    std::string GlobalConfigPath = "DefaultConfigPath";
    std::string MonteCarloConfigPath = "DefaultMCConfigPath";
    std::string SpectrumConfigPath = "DefaultSpectrumConfigPath";
    std::string OptionName;
    std::string OptionDescription;
    anallat_options::anallat_param_t anallat_global_param;

    //Templated function to Set Options
    template<OptionsType Opt> void SetOptions();

public:
    ConfigParser();

    //Parse Compulsory Configs
    bool ParseGlobalConfig();
    bool ParseMonteCarloConfig();
    bool ParseSpectrumConfig();
    std::shared_ptr<option> MakeOptions(const std::string &AppDescription="ANALLAT Common Options which is global to sub-projects", const std::string &AppName="ANALLAT Common Options");
    //accessors
    anallat_options::anallat_param_t GetAnallatParam(){return anallat_global_param;}
    std::string getSpectrumConfigPath(){return SpectrumConfigPath;}
};

END_ANALLAT_NAMESPACE
#endif // ANALLAT_COMMANDLINE_PARAMS_HPP