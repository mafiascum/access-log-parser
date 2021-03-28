//
// Created by MICHAEL MASON on 3/28/21.
//

#ifndef MAFIASCUM_ACCESS_PARSER_COMMAND_LINE_ARGUMENTS_H
#define MAFIASCUM_ACCESS_PARSER_COMMAND_LINE_ARGUMENTS_H

#include <map>
#include <vector>
#include <string>

class CommandLineArguments {

private:
    std::map<std::string, std::vector<std::string>> parameters;
    std::vector<std::string> arguments;

public:
    CommandLineArguments(const std::vector<std::string> &arguments);

    std::map<std::string, std::vector<std::string>> get_parameters();
    std::vector<std::string> get_arguments();
};

#endif //MAFIASCUM_ACCESS_PARSER_COMMAND_LINE_ARGUMENTS_H
