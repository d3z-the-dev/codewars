local solution = {}

function solution.find_multiples(integer, limit)
    local multiples = {}
    for i = integer, limit, integer do
        table.insert(multiples, i)
    end
    return multiples
end
return solution