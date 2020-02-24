import Data.Char 

countDigits :: Int -> Int 
countDigits n 
    | n < 10    = 1
    | otherwise = 1 + countDigits (n `div` 10)

countDigitsIter :: Int -> Int 
countDigitsIter n = helper n 1
    where
        helper i acc 
            | i < 10    = acc 
            | otherwise = helper (i `div` 10) (acc + 1) 

sumDigits :: Int -> Int 
sumDigits n 
    | n < 10    = n
    | otherwise = (n `mod` 10) + (sumDigits (n `div` 10)) 

sumDigitsIter :: Int -> Int 
sumDigitsIter n = helper n 0
    where 
        helper i acc 
            | i < 10    = acc + i
            | otherwise = helper (i `div` 10) (acc + (i `mod` 10))

countOccurences :: Int -> Int -> Int 
countOccurences n digit 
    | digit == (n `mod` 10)   = 1 + countOccurences (n `div` 10) digit 
    | n < 10                  = 0
    | otherwise               = countOccurences (n `div` 10) digit

isAscending :: Int -> Bool
isAscending n 
    | n < 10                                  = True
    | (n `mod` 10) <= ((n `div` 10) `mod` 10) = False
    | otherwise                               = isAscending (n `div` 10)

isPrime :: Int -> Bool 
isPrime n = helper n 2
    where
        helper i div 
            | div == n            = True 
            | (i `mod` div) == 0  = False
            | otherwise           = helper i (div + 1)

isPerfect :: Int -> Bool 
isPerfect n 
    | sumDigits n == n = True
    | otherwise        = False

reverseNumber :: Int -> Int 
reverseNumber n 
    | n < 10    = n
    | otherwise = ((n `mod` 10) * 10 ^ (countDigits (n `div` 10))) + reverseNumber (n `div` 10) 

isPalindrome :: Int -> Bool 
isPalindrome n = (n == reverseNumber n)

main :: IO()
main = do
    print (countDigits 523)
    print (countDigitsIter 523)
    print (sumDigits 523)
    print (sumDigitsIter 523)
    print (countOccurences 2552 0)
    print (isAscending 523)
    print (isPrime 4)
    print (isPerfect 6)
    print (reverseNumber 523) 
    print (isPalindrome 1233215)