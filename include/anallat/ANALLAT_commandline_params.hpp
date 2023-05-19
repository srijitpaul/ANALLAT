#ifndef ANALLAT_COMMANDLINE_PARAMS_HPP
#define ANALLAT_COMMANDLINE_PARAMS_HPP

#include <iostream>
#include <string>
#include <array>
#include <utility>
#include "externals/nlohmann/json.hpp"
#include "externals/CLI/CLI11.hpp"
#include "ANALLAT_global_includes.hpp"

using json = nlohmann::json;
using option = CLI::App;

BEGIN_ANALLAT_NAMESPACE

class ConfigParser {

private:
    json config_;
    std::string CommonConfigPath = "DefaultCommonPath";

public:
    bool ParseConfig();
    std::shared_ptr<option> MakeOptions(const std::string& AppDescription="ANALLAT Common Options which is global to sub-projects", const std::string& AppName="ANALLAT Common Options");
};

END_ANALLAT_NAMESPACE
#endif // ANALLAT_COMMANDLINE_PARAMS_HPP