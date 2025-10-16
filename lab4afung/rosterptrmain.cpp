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
#include "rosterptr.h"

using namespace std;
using namespace csen79;


int main() {
    /*
     * To robustly test the RosterPtr class, we would have to thoroughly test each member function and variable. For insert(), we might want to expand the dynamic array to test the limits until we reach a bad alloc exception. For erase, we might want to erase an ID that doesn't exist in the roster, as well as erasing from an empty roster. To test begin(), end(), and next(), we might want to test iteration over an empty roster. For further testing, we might want to break the capacity to overflow - we want to see if a reduced capacity would cause a memory leak. In this case, the member variable last would also overflow, causing incomplete iterations through the roster.
     */
	RosterPtr r;
    r.testRoster();
    return EXIT_SUCCESS;
}
