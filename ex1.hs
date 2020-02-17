inside :: Int -> Int -> Int -> Bool
inside a b x = a <= x && x <= b

sumSquares :: Double -> Double -> Double
sumSquares a b = (square a) + (square b)
    where
        square :: Double -> Double
        square x = x * x

average :: Double -> Double -> Double 
average a b = (a + b) / 2

squaresAverage :: Double -> Double -> Double
squaresAverage a b = average (square a) (square b)
    where
        square :: Double -> Double
        square x = x * x

myMin :: Double -> Double -> Double
myMin a b = if a < b then a else b

myMin' :: Double -> Double -> Double
myMin' a b 
    | a == b    = b 
    | a < b     = a
    | otherwise = b

myFact :: Int -> Int
myFact n = if n == 1 then 1 else n*(myFact (n-1)) 

myFact' :: Int -> Int 
myFact' 0 = 1
myFact' n = n * myFact' (n - 1)

myFactIter :: Int -> Int 
myFactIter n = helper n 1
    where 
        helper 1 acc = acc                       -- acc = accumulated
        helper n acc = helper (n - 1) (acc * n)

myFib :: Integer -> Integer 
myFib 0 = 1
myFib 1 = 1
myFib n = (myFib (n - 1)) + (myFib (n - 2))

myFibIter :: Integer -> Integer 
myFibIter n = helper n 1
    where 
        helper 0 acc = acc 
        helper 1 acc = acc 
        helper n acc = (helper (n - 1) (acc)) + (helper (n - 2) (acc))

myGcd :: Int -> Int -> Int 
myGcd 1 b = 1
myGcd a 1 = 1
myGcd a b
    | a `mod` b == 0  = a
    | b `mod` a == 0  = b

main :: IO()
main = do
    print (inside 2 5 3)
    print (sumSquares 2 5)
    print (average 2 5)
    print (squaresAverage 2 5)
    print (myMin 2 5)
    print (myMin' 2 5)
    print (myFact 5)
    print (myFact' 5)
    print (myFactIter 5)
    print (myFib 5)
    print (myFibIter 5)