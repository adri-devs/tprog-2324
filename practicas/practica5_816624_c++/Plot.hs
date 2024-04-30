module Plot where
import Turtle

-- turtle es una lista con los puntos a recorrer de la tortuga
tplot :: Turtle -> String -> [Position]
tplot turtle [] = []
tplot turtle (tor:tors) = np : (tplot nt tors)
    where
        nt = newTurtle turtle tor
        (_,_,np,_) = nt

newTurtle :: Turtle -> Char -> Turtle
newTurtle turtle '>' =  moveTurtle turtle Forward
newTurtle turtle '+' =  moveTurtle turtle TurnRight
newTurtle turtle '-' =  moveTurtle turtle TurnLeft