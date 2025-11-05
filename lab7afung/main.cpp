/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "record.h"

namespace csen79 {
    struct BMIlessFunctor{
        bool operator()(const Record& lh, const Record& rh) const {
            return BMIless(lh, rh);
        }
    };
}

using namespace std;
using namespace csen79;

int main() {
    string line;
    vector<Record> records;
    while (getline(cin, line)) {
        std::stringstream sio(line);
        Record r;
        if (sio >> r)
            records.push_back(r);
    }

    int i = 0;
    auto it = std::find(records.begin(), records.end(), 3);
    while (it != records.end()) {
        cout << "Found " << ++i << " born in March: " << *it << endl;
        ++it;
        it = std::find(it, records.end(), 3);
    }

    it = std::find(records.begin(), records.end(), "LilyLiu");
    cout << "\nFound Lily Liu:" << *it << endl;

    i = 0;
    sort(records.begin(), records.end());
	cout << "\nSorted by height:\n";
	for (auto r : records) {
		cout << i++ << ": " <<  r << endl;
    }
    i = 0;
    sort(records.begin(), records.end(), BMIlessFunctor());
	cout << "\nSorted by BMI:\n";
	for (auto r : records) {
		cout << i++ << ": " <<  r << endl;
    }
    return EXIT_SUCCESS;
}