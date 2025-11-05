/*
 * Name: Alan Fung
 * Email: afung@scu.edu
 */
#ifndef RECORD_H
#define RECORD_H
#include <ctime>
#include <string>
namespace csen79 {
    class Record {
    public:
        static constexpr int EpochYear = 1900;
        const float getBMI() const { return weight / height / height * 703;}

        bool operator==(const std::tm& birth) const;
        bool operator==(const std::string& firstlast) const;
        bool operator==(int month) const;
        bool operator<(const std::string& last) const;
        bool operator<(const Record &other) const;

    private:
        std::string first;
        std::string last;
        std::tm birth;
        float weight;
        int height;
        
    friend std::istream &operator>>(std::istream &, Record &);
    friend std::ostream &operator<<(std::ostream &, const Record &);
    friend bool BMIless(const Record &lh, const Record &rh);
    };
}
#endif // RECORD_H