#include <string.h>

struct RomanMap {
    char* r;
    unsigned int n;
};

const struct RomanMap roman_map[13] = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
    {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
    {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
};

void to_roman(unsigned int num, char* roman) {
    *roman = '\0';
    while (num > 0) {
        for (int i = 0; i < 13; i++) {
            while (num >= roman_map[i].n) {
                strcat(roman, roman_map[i].r);
                num -= roman_map[i].n;
            }
        }
    }
}

unsigned int from_roman(const char* roman_num) {
    unsigned int num = 0;
    while (*roman_num != '\0') {
        for (int i = 0; i < 13; i++) {
            int r_len = strlen(roman_map[i].r);
            while (strncmp(roman_num, roman_map[i].r, r_len) == 0) {
                num += roman_map[i].n;
                roman_num += r_len;
            }
        }
    }
    return num;
}