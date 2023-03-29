class RomanNumerals {
    def fromRoman(romanNumeral: String): Int = {
        var D = Array(1000, 500, 100, 50, 10, 5, 1)
        var result = 0
        var last = 0
        for (c <- romanNumeral) {
            val index = "MDCLXVI".indexOf(c)
            val current = D(index)
            result += current
            if (current > last) {
                result -= 2 * last
            }
            last = current
        }
        result
    }
    
    def toRoman(n: Int): String = {
        var roman = ""
        var num = n
        val d = Array("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I")
        val v = Array(1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
        for (i <- 0 until d.length) {
            while (num >= v(i)) {
                roman += d(i)
                num -= v(i)
            }
        }
        roman
    }
}