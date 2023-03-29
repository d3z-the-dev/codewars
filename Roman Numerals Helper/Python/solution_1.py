class RomanNumerals:
    roman_map = ('M', 1000), ('CM', 900), ('D', 500), ('CD', 400), ('C', 100), ('XC', 90), ('L', 50), ('XL', 40), ('X', 10), ('IX', 9), ('V', 5), ('IV', 4), ('I', 1)

    @staticmethod
    def to_roman(num):
        roman = ''
        while num > 0:
            for r, n in RomanNumerals.roman_map:
                while num >= n:
                    roman += r
                    num -= n
        return roman

    @staticmethod
    def from_roman(roman_num):
        num = 0
        for r, n in RomanNumerals.roman_map:
            while roman_num.startswith(r):
                num += n
                roman_num = roman_num[len(r):]
        return num
