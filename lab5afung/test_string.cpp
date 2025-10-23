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

int main()
{
    // CONSTRUCTORS
    cout << "Testing constructors:\n";
    cout << "------------------------------------------------------------------------\n";
    cout << "Constructor string(const char str[]) test. This also tests the operator overload <<.\nUsing string literal \"abc\":\n";
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
    cout << "Testing addition assignment operator +=:\n";
    cout << "Overload of operator +=(const string& addend) test. Adding s1 = \"" << s1 << "\" and s2 = \"" << s2 << "\":\n";
    s1 += s2;
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "\nOverload of operator +=(const char addend[]) test. Adding s1 = \"" << s1 << "\" and a string literal \"abc\":\n";
    s1 += "abc";
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "\nOverload of operator +=(char addend) test. Adding s1 = \"" << s1 << "\" and a character c = \"" << c << "\":\n";
    s1 += "abc";
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";

    // ASSIGNMENT OPERATOR
    cout << "Testing assignment operator =:\n";
    cout << "Overload of assingment operator =(const string& source) test. Assigning s1 = \"" << s1 << "\" to s3 = \"" << s3 << "\":\n";
    s1 = s3;
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
    
    // INSERT
    cout << "Testing insertion:\n";
    cout << "s1.insert(const string& source, unsigned int position) test.\nThis should insert the source string into the calling string s1 = \"" << s1 << "\" at index <position>.\nInserting s3 = \"" << s3 << "\" into s1 = \"" << s1 << "\":\n";
    cout << "Enter any unsigned integer <position>:\n";
    unsigned int n;
    cin >> n;
    s1.insert(s3, n);
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";

    // DELETE
    cout << "Testing deletion:\n";
    cout << "s1.dlt(unsigned int position, unsigned int num) test.\nThis should delete <num> characters from the calling string s1 = \"" << s1 << "\", starting from index <position>.\nEnter two space-separated unsigned integers <position> and <num>:\n";
    unsigned int position, num;
    cin >> position >> num;
    s1.dlt(position, num);
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";

    // REPLACE
    cout << "Testing replacement:\n";
    cout << "s1.replace(char c, unsigned int position) test.\nThis should replace one character in the calling string s1 = \"" << s1 << "\" at index <position> with a character <c>.\nEnter a char <c> and an unsigned integer <position> separated by spaces:\n";
    cin >> c >> position;
    s1.replace(c, position);
    cout << "Result: s1 = \"" << s1 << "\"\n";

    cout << "s1.replace(const string& source, unsigned int position) test.\nThis should the replace the calling string s1 = \"" << s1 << "\" starting from index <position> with a string <source>.\nEnter a string <source> and an unsigned integer <position> separated by spaces. This also tests the operator overload >>:\n";
    string s;
    cin >> s >> position;
    s1.replace(s, position);
    cout << "Result: s1 = \"" << s1 << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";
    
    // LENGTH
    cout << "Testing length getter:\n";
    cout << "s1.length() const test.\nThis should return the length of the string s1 = \"" << s1 << "\":\n";
    cout << "Result: s1.length() = \"" << s1.length() << "\"\n";
    cout << "\n------------------------------------------------------------------------\n";

}
