package solution

object StockList {
    fun stockSummary(lstOfArt: Array<String>, lstOfCat: Array<String>): String {
        if (lstOfArt.isEmpty() || lstOfCat.isEmpty())
            return ""
        val quantities = IntArray('Z'.toInt() + 1)
        for (book in lstOfArt) {
            val position = book.indexOf(" ", 2, true)
            quantities[book[0].toInt()] += book.substring(position + 1).toInt()
        }
        var result = ""
        for (category in lstOfCat) {
            result += if (result.isEmpty()) "" else " - "
            result += "(${category[0]} : ${quantities[category[0].toInt()]})"
        }
        return result
    }
}