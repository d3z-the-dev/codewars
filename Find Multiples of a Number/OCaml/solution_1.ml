let rec find_multiples integer limit =
    if limit < integer then []
    else if limit mod integer = 0 then find_multiples integer (limit - integer) @ [limit]
    else find_multiples integer (limit - 1)