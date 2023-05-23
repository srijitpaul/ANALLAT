//
// Created by spaul on 19/05/2023.
//
#include "anallat/ANALLAT_commandline_params.hpp"

BEGIN_ANALLAT_NAMESPACE

ConfigParser::ConfigParser() {
    std::cout<<"Constructor for the ConfigParser with default"<<std::endl;
}

template<>
void ConfigParser::SetOptions<OptionsType::CommonOptions>() {
    anallat_global_param.GlobalOpt =   config_.get<anallat_options::GlobalOptions>();
}

template<>
void ConfigParser::SetOptions<OptionsType::MonteCarloOptions>() {
    anallat_global_param.MCOpt  =   config_.get<anallat_options::MonteCarloOptions>();
}

template<>
void ConfigParser::SetOptions<OptionsType::SpectrumOptions>() {
    anallat_global_param.SpectrumOpt  =   config_.get<anallat_options::SpectrumOptions>();
}

bool ConfigParser::ParseGlobalConfig() {
    std::ifstream file(GlobalConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << GlobalConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "Global Json config read as: "<< config_ <<std::endl;
    SetOptions<OptionsType::CommonOptions>();
    return true;
}
bool ConfigParser::ParseMonteCarloConfig() {
    std::ifstream file(MonteCarloConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << MonteCarloConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "MonteCarlo Json config read as: "<< config_ <<std::endl;
    SetOptions<OptionsType::MonteCarloOptions>();
    return true;
}
bool ConfigParser::ParseSpectrumConfig() {
    std::ifstream file(SpectrumConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << SpectrumConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< "Spectrum Json config read as: "<< config_ <<std::endl;
    SetOptions<OptionsType::SpectrumOptions>();
    return true;
}

//Default Shared Pointer
std::shared_ptr<option> ConfigParser::MakeOptions(const std::string &AppDescription, const std::string &AppName) {

    auto anallat_opt = std::make_shared<option>(AppDescription, AppName);
    anallat_opt->option_defaults()->always_capture_default();

    anallat_opt->add_option("--global-config", GlobalConfigPath, "Global configuration");
    anallat_opt->add_option("--montecarlo-config", MonteCarloConfigPath, "Monte Carlo configuration");
    anallat_opt->add_option("--spectrum-config", SpectrumConfigPath, "Spectrum configuration");

    return anallat_opt;
}

END_ANALLAT_NAMESPACE

