def findMultiples(integer: Int, limit: Int): List[Int] =
    List.range(1, limit / integer + 1).map(_ * integer)