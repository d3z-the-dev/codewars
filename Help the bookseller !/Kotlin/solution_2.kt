package solution

object StockList {
    fun stockSummary(lstOfArt: Array<String>, lstOfCat: Array<String>): String {
        if (lstOfArt.isEmpty()) return ""
        val counts = lstOfArt.groupingBy { it.take(1) }.fold(0) { 
        	category, quantities -> category + quantities.split(" ")[1].toInt() 
        }
        return lstOfCat.joinToString(" - ") { "($it : ${counts.getOrDefault(it, 0)})" }
    }
}