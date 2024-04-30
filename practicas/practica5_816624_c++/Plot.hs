module Plot where
import Turtle (Turtle, Position)

-- Devuelve una lista con los puntos que recorrera la tortuga
tplot :: Turtle -> String -> [Position]
tplot turtle [] = []
tplot turtle (tor:tors) = nPos : (tplot nt tors)
    where
        nt = newTurtle turtle tor
        (_,_,nPos,_) = nt

newTurtle :: Turtle -> Char -> Turtle
newTurtle turtle '>' =  moveTurtle t Forward
newTurtle turtle '+' =  moveTurtle t TurnRight
newTurtle turtle '=' =  moveTurtle t TurnLeft