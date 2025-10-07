/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "person.h"
#include "roster.h"

using namespace std;
using namespace csen79;

int main() {
	Roster r;
	Person st;
	Person::ID_t id;
	string cmd, first, last;

	while (cin >> cmd) {
		switch (cmd[0]) {

        // adds a person with id, firstname, lastname to roster
		case Command::Add:
            cin >> id >> first >> last;
            r.insert(Person(id, first, last));
			break;

        // removes a person with id from roster
		case Command::Erase:
            cin >> id;
            r.erase(id);
			break;

        // lists the roster
		case Command::Print:
			cout << "---- Current Roster ----"  << endl;
			int i = 1;
			for (auto st = r.begin(); st != r.end(); st = r.next(), i++)
				cout << i << ": " << *st << endl;
			break;
		} 
	}
	
	return EXIT_SUCCESS;
}

