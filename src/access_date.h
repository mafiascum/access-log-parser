//
// Created by MICHAEL MASON on 3/28/21.
//

#ifndef MAFIASCUM_ACCESS_PARSER_ACCESS_DATE_H
#define MAFIASCUM_ACCESS_PARSER_ACCESS_DATE_H

class AccessDate {
private:
    int day;
    int month;
    int year;

public:
    AccessDate(int year, int month, int day);
    int get_day() const;
    int get_month() const;
    int get_year() const;
    int get_key() const;
    bool operator <(const AccessDate &other_date) const;
};

#endif //MAFIASCUM_ACCESS_PARSER_ACCESS_DATE_H
