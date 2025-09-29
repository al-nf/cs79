/*
 * File: part1.cpp
 *
 * Copyright: Alan Fung, 2025
 *
 * Description: Counts the number of alphanumeric and non-alphanumeric characters from the standard input, not counting spaces.
 */

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string input;
    int anchs = 0; // alphanumeric characters
    int nanchs = 0; // non-alphanumeric characters
    printf("Please type something:\n");
    getline(cin, input);

    for (char c : input) {
        if (c != ' ') {
            isalnum(c) == 0 ? nanchs++ : anchs++;
        }
    }
    printf("\"%s\" has %d alphanumeric characters and %d non-alphanumeric characters.\n", input.c_str(), anchs, nanchs);
}
