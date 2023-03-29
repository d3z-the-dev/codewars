class RomanNumerals:
    @staticmethod
    def from_roman(num):
        D = [dict(zip('MDCLXVI', (1e3, 500, 100, 50, 10, 5, 1)))[D] for D in num]
        return int(sum((D, -D) [D < y] for D, y in zip(D, D[1:])) + D[-1])

    @staticmethod
    def to_roman(roman_num):
        D =' I II III IV V VI VII VIII IX'.split(' ')
        r = lambda n: D[n] if n < 10 else ''.join(
            dict(zip('IVXLC', 'XLCDM'))[c] for c in r(n // 10)) + D[n % 10]
        return r(roman_num)