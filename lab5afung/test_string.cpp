// FILE: str_demo.cpp
// This is a small demonstration program showing how the string class is used.
//
//  COEN 79
//  --- Behnam Dezfouli, COEN, SCU ---
//
//

#include "mystring.h" // Or use the Standard Library <string>
#include <stdlib.h> // Provides EXIT_SUCCESS
#include <iostream> // Provides cout and cin

using std::cin;
using std::cout;
using std::endl;
using namespace coen79_lab5;

void test_addition_assignment(string& s1, string& s2, string& s3);
void test_assignment(string& s1, string& s3);
void test_insert(string& s1, string& s3);
void test_delete(string& s1);
void test_replace(string& s1);
void test_length(string& s1);
void test_index(string& s1);
void test_search(string& s1);
void test_count(string& s1);
void test_add(string& s1);

int main()
{
    // CONSTRUCTORS
    cout << "\nCommencing string class test.\n";
    cout << "\n------------------------------------------------------------------------\n";
    cout << "\nTesting constructors:\n";
    cout << "Constructor string(const char str[]) test. This also tests the operator overload <<.\nUsing cstring \"abc\":\n";
    string s1("abc");
    cout << "Constructed string s1 = \"" << s1 << "\"\n";

    cout << "\nConstructor string(char c) test.\nEnter any character c:\n";
    char c;
    cin >> c;
    string s2(c);
    cout << "Constructed string s2 = \"" << s2 << "\"\n";

    cout << "\nConstructor string(const string& source) test.\nUsing the first string " << s1 << ":\n";
    string s3(s1);
    cout << "Constructed string s3 = \"" << s3 << "\"\n";

    cout << "\nConstructor test complete.";
    cout << "\n------------------------------------------------------------------------\n";


    // ADDITION ASSIGNMENT +=
    test_addition_assignment(s1, s2, s3);

    // ASSIGNMENT OPERATOR
    test_assignment(s1, s3);
    
    // INSERT
    test_insert(s1, s3);

    // DELETE
    test_delete(s1);

    // REPLACE
    test_replace(s1);
    
    // LENGTH
    test_length(s1);

    // INDEXING
    test_index(s1);

    // SEARCH
    test_search(s1);

    // COUNT
    test_count(s1);

    // ADDITION
    test_add(s1);

    cout << "Test concluded.\n";
}

void test_addition_assignment(string& s1, string& s2, string& s3) {
    char c;
    cout << "\nTesting addition assignment operator +=:\n";
    cout << "\nOverload of operator +=(const string& addend) test. This should add a string s3 = \"" << s3 << "\" to s1 = \"" << s1 << "\":\n";
    s1 += s3;
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "\nOverload of operator +=(const char addend[]) test. This should add a c string <addend> to s1 = \" " << s1 << "\".\nTrying addend = \"abc\"\n";
    s1 += "abc";
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "\nOverload of operator +=(char addend) test. This should add a character <addend> to s1 = \"" << s1 << "\".\nEnter any char <addend>:\n";
    cin >> c;
    s1 += c;
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_assignment(string& s1, string& s3) {
    cout << "\nTesting assignment operator =:\n";
    cout << "Overload of assingment operator =(const string& source) test. This should assign s1 = \"" << s1 << "\" to s3 = \"" << s3 << "\":\n";
    s1 = s3;
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}


void test_insert(string& s1, string& s3) {
    unsigned int position;
    cout << "\nTesting insertion:\n";
    cout << "s1.insert(const string& source, unsigned int position) test.\nthis should insert the source string into the calling string s1 = \"" << s1 << "\" at index <position>.\ninserting s3 = \"" << s3 << "\" into s1 = \"" << s1 << "\".\nEnter any unsigned integer <position> (precondition: position is not greater than length):\n";
    cin >> position;
    s1.insert(s3, position);
    cout << "result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_delete(string& s1) {
    unsigned int position, num;
    cout << "\nTesting deletion:\n";
    cout << "s1.dlt(unsigned int position, unsigned int num) test.\nThis should delete <num> characters from the calling string s1 = \"" << s1 << "\", starting from index <position>.\nEnter two space-separated unsigned integers <position> and <num> (precondition: the sum of <position> and <num> is not greater than length):\n";
    cin >> position >> num;
    s1.dlt(position, num);
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_replace(string& s1) {
    char c;
    string s;
    unsigned int position;
    cout << "\nTesting replacement:\n";
    cout << "s1.replace(char c, unsigned int position) test.\nThis should replace one character in the calling string s1 = \"" << s1 << "\" at index <position> with a character <c>.\nEnter a char <c> and an unsigned integer <position> separated by spaces (precondition: <position> is less than length):\n";
    cin >> c >> position;
    s1.replace(c, position);
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "\ns1.replace(const string& source, unsigned int position) test.\nThis should the replace the calling string s1 = \"" << s1 << "\" starting from index <position> with a string <source>.\nEnter a string <source> and an unsigned integer <position> separated by spaces. This also tests the operator overload >> (precondition: the sum of the two lengths is not greater than length:\n";
    cin >> s >> position;
    s1.replace(s, position);
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_length(string& s1) {
    cout << "\nTesting length getter:\n";
    cout << "s1.length() const test.\nThis should return the length of the string s1 = \"" << s1 << "\":\n";
    cout << "Result: s1.length() = " << s1.length() << "\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_index(string& s1) {
    unsigned int position;
    cout << "\nTesting indexing:\n";
    cout << "s1[size_t position] const test.\nThis should return the character at index <position> in s1 = \"" << s1 << "\".\nEnter any unsigned integer <position> (precondition: <position> is less than length):\n";
    cin >> position;
    cout << "Result: s1[" << position << "] = " << s1[position] << "\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_search(string& s1) {
    char c;
    string s;
    cout << "\nTesting search:\n";
    cout << "s1.search(char c) const test.\nThis should return the index of the first occurence of the character <c> in the calling string s1 = \"" << s1 << "\".\nEnter any char <c>:\n";
    cin >> c;
    cout << "Result: s1.search(" << c << ") = " << s1.search(c) << "\n";

    cout << "\ns1.search(const string& substring) const test.\nThis should return the index of the start of the first occurence of the string <substring> in the calling string s1 = \"" << s1 << "\".\nEnter any string <substring>:\n";
    cin >> s;
    cout << "Result: s1.search(" << s << ") = " << s1.search(s) << "\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_count(string& s1) {
    char c;
    cout << "\nTesting count:\n";
    cout << "s1.count(char c) const test.\nThis should return the number of times the character <c> occurs in the calling string s1 = \"" << s1 << "\".\nEnter any char <c>:\n";
    cin >> c;
    cout << "Result: s1.count(" << c << ") = " << s1.count(c) << "\n";
    cout << "\n------------------------------------------------------------------------\n";
}

void test_add(string& s1) {
    cout << "\nTesting addition:\n";
    cout << "Overload of friend operator +(const string& s1, const string& s2) test. Adding s1 = \"" << s1 << "\" and s1 = \"" << s1 << "\":\n";
    cout << "Result: s1 + s1 = \"" << s1+s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
}
