#include <iostream>
#include <iomanip>
#include <map>
#include <set>

class Date
{
private:
    int day;
    int month;
    int year;
public:
    bool operator<(const Date &rhs) const {
        return std::tie(year, month, day) < std::tie(rhs.year, rhs.month, rhs.day);
    }
    friend std::ostream& operator<<(std::ostream &stream, const Date &date);
    friend std::istream& operator>>(std::istream &stream, Date &date);
};

std::ostream& operator<<(std::ostream &stream, const Date &date) {
    stream << date.year << '/';
    if (date.month < 10) {
        stream << '0';
    }
    stream << date.month << '/';
    if (date.day < 10) {
        stream << '0';
    }
    stream << date.day;
    return stream;
}

std::istream& operator>>(std::istream &stream, Date &date) {
    stream >> date.year;
    stream.ignore(1);
    stream >> date.month;
    stream.ignore(1);
    stream >> date.day;
    return stream;
}

int main() {
    std::map<std::string, std::map<Date, int>> data;
    std::set<Date> dates;
    std::string name;
    Date date;
    int mark;
    while (std::cin >> name >> date >> mark) {
        data[name][date] = mark;
        dates.insert(date);
    }
    std::cout << '.';
    for (const auto &date : dates) {
        std::cout << " " << date;
    }
    std::cout << std::endl;
    for (auto &person : data) {
        std::cout << person.first;
        for (const auto &date : dates) {
            if (person.second.find(date) == person.second.end()) {
                std::cout << " .";
            } else {
                std::cout << " " << person.second[date];
            }
        }
        std::cout << std::endl;
    }
}