#include <iostream>
#include <vector>

#include "command_line_arguments.h"
#include "access_log_parser.h"

std::string parse_required_argument(const std::map<std::string, std::vector<std::string>> &param_map, const std::string param) {

    auto iter = param_map.find(param);

    if(iter == param_map.end() || iter->second.empty()) {
        std::cerr << "Required parameter `" << param << "` is missing." << std::endl;
        exit(1);
    }

    return iter->second[0];
}

std::optional<std::string> parse_optional_argument(const std::map<std::string, std::vector<std::string>> &param_map, const std::string param) {
    auto iter = param_map.find(param);

    return iter == param_map.end() || iter->second.empty()
        ? std::optional<std::string>()
        : iter->second[0];
}

int main(int argc, char *argv[]) {

    //Command line arguments
    std::vector<std::string> arg_vector;

    for(int counter = 1;counter < argc;++counter) {
        arg_vector.push_back(argv[counter]);
    }

    CommandLineArguments command_line_arguments = CommandLineArguments(arg_vector);
    std::map<std::string, std::vector<std::string>> param_map = command_line_arguments.get_parameters();

    std::string file_name_format = parse_required_argument(param_map, "fileNameFormat");
    std::string write_path = parse_required_argument(param_map, "writePath");
    std::optional<std::string> input_file_path = parse_optional_argument(param_map, "inputFilePath");

    AccessLogParser parser = AccessLogParser(input_file_path.value_or(""), write_path, file_name_format);
    parser.read_file();
    return 0;
}
