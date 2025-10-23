/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#include "mystring.h"
#include <assert.h>
#include <string.h>

namespace coen79_lab5 {
    string::string(const char str[])
    {
        assert(str[strlen(str)] == '\0');
        current_length = strlen(str);
        allocated = strlen(str) + 1;
        characters = new char[allocated];
        strncpy(characters, str, allocated);
        assert(characters[length()] == '\0' && length() < allocated);
    }
    string::string(char c)
    {
        allocated = 2;
        current_length = allocated - 1;

        characters = new char[allocated];
        characters[0] = c;
        characters[1] = '\0';
        assert(characters[length()] == '\0' && length() < allocated);
    }
    string::string(const string& source)
    {
        allocated = source.length() + 1;
        current_length = source.length();

        characters = new char[allocated];
        strncpy(characters, source.characters, allocated);
        assert(characters[length()] == '\0' && length() < allocated);
    }
    string::~string() { delete[] characters; }

    void string::operator+=(const string& addend)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        if (length() + addend.length() >= allocated) {
            allocated = length() + addend.length() + 1;
            char* temp = new char[allocated];
            strncpy(temp, characters, length());
            delete[] characters;
            characters = temp;
        }
        strncat(characters, addend.characters, addend.length());
        current_length = length() + addend.length();
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::operator+=(const char addend[])
    {
        assert(addend[strlen(addend)] == '\0');
        assert(characters[length()] == '\0' && length() < allocated);
        if (length() + strlen(addend) >= allocated) {
            allocated = length() + strlen(addend) + 1;
            char* temp = new char[allocated];
            strncpy(temp, characters, length());
            delete[] characters;
            characters = temp;
        }
        strncat(characters, addend, strlen(addend));
        current_length = length() + strlen(addend);
        characters[length()] = '\0';
        assert(length() < allocated);
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::operator+=(char addend)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        if (length() + 1 >= allocated) {
            allocated = length() + 2;
            char* temp = new char[allocated];
            strncpy(temp, characters, length());
            delete[] characters;
            characters = temp;
        }
        characters[length()] = addend;
        characters[++current_length] = '\0';
        assert(characters[length()] == '\0' && length() < allocated);
    }

    string& string::operator=(const string& source)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        delete[] characters;
        allocated = source.length() + 1;
        current_length = allocated - 1;
        characters = new char[allocated];
        strncpy(characters, source.characters, allocated);
        assert(characters[length()] == '\0' && length() < allocated);
        return *this;
    }

    void string::reserve(size_t n)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        if (allocated >= n) {
            return;
        }
        allocated = n;
        char* temp = new char[allocated];
        strncpy(temp, characters, length());
        delete[] characters;
        characters = temp;
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::insert(const string& source, unsigned int position)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        assert(position <= length());
        allocated = length() + source.length() + 1;
        current_length = allocated - 1;
        char* temp = new char[allocated];
        strncpy(temp, characters, position);
        strncat(temp, source.characters, source.length());
        strncat(temp, characters + position, length() - position);
        delete[] characters;
        characters = temp;
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::dlt(unsigned int position, unsigned int num)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        assert((position + num) <= length());
        strncpy(characters + position, characters + position + num,
            length() - (position + num));
        current_length -= num;
        characters[length()] = '\0';
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::replace(char c, unsigned int position)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        assert(position < length());
        characters[position] = c;
        assert(characters[length()] == '\0' && length() < allocated);
    }

    void string::replace(const string& source, unsigned int position)
    {
        assert(characters[length()] == '\0' && length() < allocated);
        assert(position + source.length() <= length());
        strncpy(characters + position, source.characters, source.length());
        current_length = (position + source.length() > length()) ? (position + source.length()) : length();
        characters[length()] = '\0';
        assert(characters[length()] == '\0' && length() < allocated);
    }
    char string::operator[](size_t position) const
    {
        assert(position < length());
        return characters[position];
    }

    int string::search(char c) const
    {
        for (size_t i = 0; i < length(); ++i) {
            if (characters[i] == c) {
                return i;
            }
        }
        return -1;
    }

    int string::search(const string& substring) const
    {
        for (size_t i = 0; i < length(); ++i) {
            if (strncmp(&characters[i], substring.characters, substring.length()) == 0) {
                return i;
            }
        }
        return -1;
    }

    unsigned int string::count(char c) const
    {
        unsigned int n = 0;
        for (size_t i = 0; i < length(); ++i) {
            if (characters[i] == c)
                n++;
        }
        return n;
    }

    string operator+(const string& s1, const string& s2)
    {
        string s;
        s += s1;
        s += s2;
        return s;
    }

    string operator+(const string& s1, const char addend[])
    {
        string s;
        s += s1;
        s += addend;
        return s;
    }

    std::istream& operator>>(std::istream& ins, string& target)
    {
        char buffer[4096];
        ins >> buffer;
        target.dlt(0, target.length());
        target += buffer;

        return ins;
    }

    std::ostream& operator<<(std::ostream& outs, const string& source)
    {
        outs << source.characters;
        return outs;
    }

    bool operator==(const string& s1, const string& s2)
    {
        if (s1.length() != s2.length()) {
            return false;
        }
        for (size_t i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const string& s1, const string& s2)
    {
        return !(s1 == s2);
    }

    bool operator>(const string& s1, const string& s2)
    {
        size_t min_length = (s1.length() < s2.length()) ? s1.length() : s2.length();
        for (size_t i = 0; i < min_length; ++i) {
            if (s1[i] > s2[i]) {
                return true;
            } else if (s1[i] < s2[i]) {
                return false;
            }
        }
        return false;
    }

    bool operator<(const string& s1, const string& s2)
    {
        return !(s1 > s2) && (s1 != s2);
    }

    bool operator>=(const string& s1, const string& s2)
    {
        return (s1 > s2) || (s1 == s2);
    }

    bool operator<=(const string& s1, const string& s2)
    {
        return (s1 < s2) || (s1 == s2);
    }
}
