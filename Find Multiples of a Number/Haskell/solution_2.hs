module Multiples (multiples) where

multiples :: Int -> Int -> [Int]
multiples integer limit = [integer, integer+integer .. limit]