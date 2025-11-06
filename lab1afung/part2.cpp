/*
 * File: part2.cpp
 *
 * Copyright: Alan Fung, 2025
 *
 * Description: Displays a pattern.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    for (int i = 0; i < 5; i++) {
        cout << setw(5 + (2*i)) << ""
             << "0123456789"
             << setw(10 + (2*i)) << ""
             << "9876543210"
             << "\n";
    }
}
