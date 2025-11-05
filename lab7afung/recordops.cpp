/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <iostream>
#include <ctime>
#include "record.h"

namespace csen79 {
    bool Record::operator==(const std::tm& birth) const {
        return this->birth.tm_year == birth.tm_year &&
            this->birth.tm_mon  == birth.tm_mon &&
            this->birth.tm_mday == birth.tm_mday;
    }

    bool Record::operator==(int month) const {
        return (this->birth.tm_mon + 1) == month;
    }

    bool Record::operator==(const std::string& firstlast) const {
        return (first + " " + last) == firstlast;
    }

    bool Record::operator<(const std::string& last) const {
        return this->last < last;
    }

    bool Record::operator<(const Record &other) const {
        return this->last < other.last;
    }

    bool BMIless(const Record &lh, const Record &rh) {
        return lh.getBMI() < rh.getBMI();
    }
};