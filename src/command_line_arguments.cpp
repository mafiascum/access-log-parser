//
// Created by MICHAEL MASON on 3/28/21.
//

#include <optional>

#include "command_line_arguments.h"

CommandLineArguments::CommandLineArguments(const std::vector<std::string> &arguments) {
    this->arguments = arguments;
    std::optional<std::string> last_parameter_name;

    for(std::string arg : arguments) {
        if(arg.empty()) {
            continue;
        }

        if(last_parameter_name.has_value()) {
            this->parameters[last_parameter_name.value()].push_back(arg);
            last_parameter_name = std::optional<std::string>();
        }
        else if(arg.starts_with("-")) {
            last_parameter_name = std::optional<std::string>(arg.substr(1));

            if(this->parameters.find(last_parameter_name.value()) != this->parameters.end()) {
                this->parameters[last_parameter_name.value()] = std::vector<std::string>();
            }
        }
        else {
            this->arguments.push_back(arg);
        }
    }
}

std::map<std::string, std::vector<std::string>> CommandLineArguments::get_parameters() {
    return this->parameters;
}

std::vector<std::string> CommandLineArguments::get_arguments() {
    return this->arguments;
}