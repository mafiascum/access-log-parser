//
// Created by MICHAEL MASON on 3/28/21.
//

#ifndef MAFIASCUM_ACCESS_PARSER_ACCESS_LOG_PARSER_H
#define MAFIASCUM_ACCESS_PARSER_ACCESS_LOG_PARSER_H

#include <string>
#include <optional>
#include "access_date.h"

class AccessLogParser {
private:

    std::string input_file_path;
    std::string write_path;
    std::string file_name_format;

    std::string get_file_name(const AccessDate &access_date);
    std::optional<AccessDate> parse_date(const std::string &line);
    std::string format_date_for_filename(const AccessDate &date);

public:
    AccessLogParser(const std::string &input_file_path, const std::string &write_path, const std::string &file_name_format);
    ~AccessLogParser();
    void read_file();
};

#endif //MAFIASCUM_ACCESS_PARSER_ACCESS_LOG_PARSER_H
