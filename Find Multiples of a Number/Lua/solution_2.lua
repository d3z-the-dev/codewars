local solution = {}

function solution.find_multiples(integer, limit)
  local multiples = {}
  for i = 1, limit / integer do multiples[i] = i * integer end
  return multiples
end
return solution