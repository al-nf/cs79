/*
 * CSEN 79 Lab Sample Code
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"


namespace csen79 {

	// STUDENT WORK
	Roster::Roster() {
        idx = 0;
        last = 0;
    }
	// insert into the roster
	void Roster::insert(const T &rec) {
        if (last < CAPACITY) {
            roster[last++] = rec;
        } 
	}

	// simply mark the slot empty
	void Roster::erase(Person::ID_t id) {
        for (std::size_t i = 0; i < last; ++i) { // size_t is safe to use with array indices
            if (roster[i].getID() == id) {
                roster[i] = roster[--last]; // moving the last person into the erased slot is O(1)
                return;
            }
        }
	}

	// rudimentary iterator
	// in the future, this will return an object of iterator type
	Roster::T* Roster::begin(void) {
        idx = 0;
        return &roster[idx];
	}

	Roster::T* Roster::end(void) {
        if (last > CAPACITY) {
            throw std::out_of_range("Roster capacity reached");
        }
        return &roster[last];
	}

	// The next element for interation
	// if already reached the end, throw exception
	Roster::T* Roster::next(void) {
        if (++idx > last) {
            throw std::out_of_range("Iterated out of bounds");
        }
        return &roster[idx];
	}
}
