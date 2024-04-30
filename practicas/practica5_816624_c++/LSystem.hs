-- Modulo independiente LSystem
-- Autores: 816624, 845154
-- Fecha últ mod: 30/04/24
module Lsystem where
lsystem :: (Char -> String) -> String -> Int -> String
lsystem rules str 0 = str -- si el numero de iteraciones es 0, devuelve la cadena
lsystem rules str n = lsystem rules (concatMap rules str)(n-1) -- concatena con concatMap recursivamente