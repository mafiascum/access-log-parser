//
// Created by MICHAEL MASON on 3/28/21.
//

#include "access_date.h"

AccessDate::AccessDate(int year, int month, int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int AccessDate::get_day() const {
    return day;
}

int AccessDate::get_month() const {
    return month;
}

int AccessDate::get_year() const {
    return year;
}

int AccessDate::get_key() const {
    return year * 10000 + month * 100 + day;
}

bool AccessDate::operator <(const AccessDate &other_date) const {
    return this->get_key() < other_date.get_key();
}