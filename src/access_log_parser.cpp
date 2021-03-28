//
// Created by MICHAEL MASON on 3/28/21.
//

#include <vector>
#include <map>
#include <optional>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "access_log_parser.h"

std::string AccessLogParser::get_file_name(const AccessDate &access_date) {
    std::string file_name = this->file_name_format;
    auto percent_index = file_name.find("%s");

    if(percent_index != std::string::npos) {
        file_name.replace(percent_index, 2, this->format_date_for_filename(access_date));
    }
    else {
        file_name = "access.log." + this->format_date_for_filename(access_date);
    }

    return file_name;
}

std::optional<AccessDate> AccessLogParser::parse_date(const std::string &line) {
    auto open_bracket_index = line.find('[');
    if(open_bracket_index == std::string::npos) {
        return std::optional<AccessDate>();
    }

    auto space_index = line.find(' ', open_bracket_index);

    if(space_index == std::string::npos) {
        return std::optional<AccessDate>();
    }

    auto timestamp_size = space_index - open_bracket_index - 1;

    if(timestamp_size != 10) {
        return std::optional<AccessDate>();
    }

    int year = atoi(line.substr(open_bracket_index + 1, 4).c_str());
    int month = atoi(line.substr(open_bracket_index + 6, 7).c_str());
    int day = atoi(line.substr(open_bracket_index + 9, 10).c_str());

    return AccessDate(year, month, day);
}

std::string AccessLogParser::format_date_for_filename(const AccessDate &date) {
    std::stringstream file_name_stream;

    file_name_stream
            << std::setfill('0') << std::setw(4) << date.get_year()
            << std::setfill('0') << std::setw(2) << date.get_month()
            << std::setfill('0') << std::setw(2) << date.get_day();

    return file_name_stream.str();
}

AccessLogParser::AccessLogParser(const std::string &input_file_path, const std::string &write_path, const std::string &file_name_format) {
    this->input_file_path  = input_file_path;
    this->write_path = write_path;
    this->file_name_format = file_name_format;
}

AccessLogParser::~AccessLogParser() {
}

void AccessLogParser::read_file() {
    std::istream *input_stream = &std::cin;
    std::ifstream *input_file = nullptr;

    if(!this->input_file_path.empty()) {
        input_file = new std::ifstream(this->input_file_path);
        input_stream = input_file;
    }

    std::map<AccessDate, std::ofstream *> date_to_output_file_map;
    std::string line;

    while(std::getline(*input_stream, line)) {

        auto line_date = this->parse_date(line);
        if(!line_date.has_value()) {
            continue;
        }

        auto output_file_iter = date_to_output_file_map.find(*line_date);
        std::ofstream *output_file = nullptr;

        if(output_file_iter == date_to_output_file_map.end()) {

            std::string output_file_path = write_path + this->get_file_name(*line_date);

            std::cout << "Opened File: " + output_file_path << std::endl;
            output_file = new std::ofstream(output_file_path.c_str());
            date_to_output_file_map[*line_date] = output_file;
        }
        else {
            output_file = output_file_iter->second;
        }

        (*output_file) << line << std::endl;
    }

    //Close input file
    if(input_file != nullptr) {
        input_file->close();
        delete input_file;
    }

    //Close output files
    for(auto iter : date_to_output_file_map) {
        iter.second->close();
        delete iter.second;
    }
}