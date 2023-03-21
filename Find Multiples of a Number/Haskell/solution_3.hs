module Multiples (multiples) where

multiples :: Int -> Int -> [Int]
multiples = flip (takeWhile . (>=)) . (iterate =<< (+))