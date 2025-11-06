/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <iostream>
#include <ctime>
#include "record.h"

namespace csen79 {
    bool Record::operator==(int month) const {
        return (this->birth.tm_mon + 1) == month;
    }

    // == has to take only one argument
    bool Record::operator==(const std::string& firstlast) const {
        return (first + " " + last) == firstlast;
    }

    bool Record::operator<(const std::string& last) const {
        return this->last < last;
    }

    bool Record::operator<(const Record &other) const {
        return this->last < other.last;
    }

    // helper for functor
    bool BMIless(const Record &lh, const Record &rh) {
        return lh.getBMI() < rh.getBMI();
    }
};
