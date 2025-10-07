/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"


namespace csen79 {

	Roster::Roster() {
        idx = 0;
        last = 0;
    }

	void Roster::insert(const T &rec) {
        if (last < CAPACITY) {
            roster[last++] = rec;
        } 
	}

	void Roster::erase(Person::ID_t id) {
        for (std::size_t i = 0; i < last; ++i) { // size_t is safe to use with array indices
            if (roster[i].getID() == id) {
                roster[i] = roster[--last]; // moving the last person into the erased slot is O(1)
                                            // shifting is O(n)
                return;
            }
        }
	}

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

	Roster::T* Roster::next(void) {
        if (++idx > last) {
            throw std::out_of_range("Iterated out of bounds");
        }
        return &roster[idx];
	}
}
