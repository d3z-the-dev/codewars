function findMultiples(integer, limit) {
    var multiples = []
    for (var factor = 1; factor <= Math.floor(limit / integer); factor++) {
        multiples.push(integer * factor)
    }
    return multiples
}