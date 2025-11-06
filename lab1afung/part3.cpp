/*
 * File: part3.cpp
 *
 * Copyright: Alan Fung, 2025
 *
 * Description: Converts to uppercase and displays all words from an input file with length of at least 10 non-punctuation characters, removing all punctuation marks.
 */

#include <fstream>
#include <iostream>
#include <cctype>
#include <assert.h>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream text (argv[1]);
    assert(text.is_open());

    string word;
    while (text >> word) {
        string temp;
        for (char c : word) {
            char ch = toupper(c);
            if (!ispunct(ch)) {temp.push_back(ch);};
        }
        if (temp.length() >= 10) {cout << temp << "\n";};
    }
    text.close();
}
