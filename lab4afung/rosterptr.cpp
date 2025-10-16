/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <exception>
#include "person.h"
#include "roster.h"
#include "rosterptr.h"
using namespace std;

namespace csen79 {
	RosterPtr::RosterPtr() {
        capacity = Roster::CAPACITY;
        roster = new T[capacity];
        idx = 0;
        last = 0;

    }
	RosterPtr::~RosterPtr() {
        delete[] roster;
    }
	bool RosterPtr::insert(const T &rec) {
        if (last >= capacity) {
            if (capacity*2 < capacity) {
                throw overflow_error("Capacity overflow!");
            }
            T* temp_roster = new T[capacity*2];
            copy(roster, roster + capacity, temp_roster);
            delete[] roster;
            roster = temp_roster;
            capacity *= 2;
            return true; // capacity has been expanded
        }
        roster[last++] = rec;
        return false; // capacity unchanged
    }
	void RosterPtr::erase(Person::ID_t id) {
        for (size_t i = 0; i < last; ++i) {
            if (roster[i].getID() == id) {
                roster[i] = roster[--last];
                return;
            }
        }
    }
	Roster::T* RosterPtr::begin(void) {
        idx = 0;
        return &roster[idx];
    }
	Roster::T* RosterPtr::end(void) {
        if (last > capacity) {
            throw out_of_range("Roster capacity reached");
        }
        return &roster[last];
    }
	Roster::T* RosterPtr::next(void) {
        if (++idx > last) {
            throw out_of_range("Iterated out of bounds");
        }
        return &roster[idx];
    }
}	// namespace
