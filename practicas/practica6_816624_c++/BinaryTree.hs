module BinaryTree where
import Data.List

data BinTree arb = Leaf | Node arb (BinTree arb) (BinTree arb)

empty :: BinTree arb
empty = Leaf

instance (Show arb) => Show(BinTree arb) where
  show Leaf = ""
  show (Node arb Leaf Leaf) = show arb ++ "\n"
  show (Node arb left right) = show left ++ "\t" ++ show arb ++ "\n" ++ show right ++ "\t"

leaf :: arb -> BinTree arb
leaf arb = Node arb (empty) (empty)

tree :: arb -> BinTree arb -> BinTree arb -> BinTree arb
tree arb left right = Node arb left right

size :: BinTree arb -> Integer
size Leaf = 0
size (Node _ left right) = 1 + size left + size right

add :: (Ord arb) => BinTree arb -> arb -> BinTree arb
add Leaf x = leaf x
add (Node arb left right) x = if arb == x then (Node arb left right)
                              else
                                  if arb > x
                                  then Node arb (add left x) (right)
                                  else Node arb (left) (add right x)

buildRec :: (Ord arb) => [arb] -> BinTree arb -> BinTree arb
buildRec [] arb = arb
buildRec (x:xs) arb = buildRec xs (add arb x)

build :: (Ord arb) => [arb] -> BinTree arb
build [] = Leaf
build x = buildRec x empty

buildBalanced :: (Ord arb) => [arb] -> BinTree arb
buildBalanced [] = Leaf
buildBalanced [x] = leaf x
buildBalanced x = Node (mid) (buildBalanced left) (buildBalanced right)
  where
    s = length x
    mid = mediana(s `div` 2) (sort x)
    left = fst (splitAt(s `div` 2) (sort x))
    right' = snd (splitAt(s `div` 2) (sort x))
    right = Data.List.delete mid right'


preorder :: BinTree arb -> [arb]
preorder Leaf = []
preorder (Node arb left right) = arb : (preorder left ++ preorder right)

postorder :: BinTree arb -> [arb]
postorder Leaf = []
postorder (Node arb left right) = postorder left ++ postorder right ++ [arb]

inorder :: BinTree arb -> [arb]
inorder Leaf = []
inorder (Node arb left right) = inorder left ++ [arb] ++ inorder right

balance :: (Ord arb) => BinTree arb -> BinTree arb
balance Leaf = Leaf
balance arb = buildBalanced (preorder arb)

between :: Ord arb => BinTree arb -> arb -> arb -> [arb]
between Leaf mini maxi = []
between (Node arb left right) mini maxi | maxi < arb = between left mini maxi
                                        | mini > arb = between right mini maxi
                                        | (mini <= arb) && (arb <= maxi) = [arb] ++ between left mini maxi ++ between right mini maxi

mediana :: Int -> [arb] -> arb
mediana 0 (x:xs) = x
mediana y (x:xs) = mediana (y - 1) xs

tabular :: Integer -> String
tabular 0 = ""
tabular x = ("    ") ++ (tabular (x - 1))








