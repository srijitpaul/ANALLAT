//
// Created by spaul on 19/05/2023.
//
#include "anallat/ANALLAT_commandline_params.hpp"
#include "anallat/global/ANALLAT_montecarlo_options.hpp"
BEGIN_ANALLAT_NAMESPACE


bool ConfigParser::ParseConfig() {
    std::ifstream file(CommonConfigPath, std::ifstream::in);
    if(!file.is_open()) {
        std::cerr << "Failed to open config file: " << CommonConfigPath << std::endl;
        return false;
    }
    try {
        file >> config_;
    } catch (const json::parse_error& e){
        std::cerr << "Failed to parse config file: " << e.what() << std::endl;
        return false;
    }
    std::cout<< config_ <<std::endl;
    return true;
}
std::shared_ptr<option>
ConfigParser::MakeOptions(const std::string &AppDescription, const std::string &AppName) {
    auto anallat_opt = std::make_shared<option>(AppDescription, AppName);
    anallat_opt->option_defaults()->always_capture_default();

    anallat_opt->add_option("--common-config", CommonConfigPath, "Common Configuration File");
    return anallat_opt;

}

END_ANALLAT_NAMESPACE
