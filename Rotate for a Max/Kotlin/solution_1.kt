package maxrot

fun maxRot(n: Long): Long {
    var digits = n.toString()
    var maxVal = n
    for (i in digits.indices) {
        val c = digits[i]
        digits = digits.removeRange(i, i + 1) + c
        val rotated = digits.toLong()
        if (rotated > maxVal) {
            maxVal = rotated
        }
    }
    return maxVal
}