fn find_multiples(integer: u32, limit: u32) -> Vec<u32> {
    (1..limit/integer + 1).map( |i| { i*integer } ).collect()
}