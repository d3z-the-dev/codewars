module Multiples (multiples) where

multiples :: Int -> Int -> [Int]
multiples = enumFromThenTo <*> (*) 2