#include <string>
#include <utility>

class RomanNumerals {
  public:
    const std::pair<std::string, unsigned int> roman_map[13] = {
        {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
        {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
        {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
    };

    std::string to_roman(unsigned int num) {
        std::string roman = "";
        while (num > 0) {
            for (auto& [r, n] : roman_map) {
                while (num >= n) {
                    roman += r;
                    num -= n;
                }
            }
        }
        return roman;
    }

    int from_roman(std::string roman_num) {
        int num = 0;
        for (auto& [r, n] : roman_map) {
            while (roman_num.find(r) == 0) {
                num += n;
                roman_num = roman_num.substr(r.length());
            }
        }
        return num;
    }
} RomanNumerals;