package kata

func FindMultiples(n, limit int) (result[]int) {
    for  i:=n; i<=limit; i += n { result = append(result, i) }
    return 
}