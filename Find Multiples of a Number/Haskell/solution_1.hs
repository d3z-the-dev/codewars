module Multiples (multiples) where

multiples :: Int -> Int -> [Int]
multiples integer limit = [i | i <- [integer, integer * 2 .. limit]]