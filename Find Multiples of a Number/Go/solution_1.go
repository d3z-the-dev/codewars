package kata

func FindMultiples(integer, limit int) []int {
    var result []int
    multiple := integer
    for multiple <= limit {
        result = append(result, multiple)
        multiple += integer
    }
    return result
}