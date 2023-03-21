fn find_multiples(integer: u32, limit: u32) -> Vec<u32> {
    let mut multiples = Vec::new();
    let mut multiple = integer;
    while multiple <= limit {
        multiples.push(multiple);
        multiple += integer;
    }
    multiples
}