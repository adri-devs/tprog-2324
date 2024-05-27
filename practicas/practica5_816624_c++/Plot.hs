module Plot where
import Turtle

-- turtle es una lista con los puntos a recorrer de la tortuga
tplot :: Turtle -> String -> [Position]
tplot turtle [] = []
tplot turtle (x:xs) = np : (tplot nt xs)
    where
        nt = newTurtle turtle x
        (_,_,np,_) = nt

newTurtle :: Turtle -> Char -> Turtle
newTurtle turtle '>' =  moveTurtle turtle Forward
newTurtle turtle '+' =  moveTurtle turtle TurnRight
newTurtle turtle '-' =  moveTurtle turtle TurnLeft
newTurtle turtle 'F' =  moveTurtle turtle Forward
newTurtle turtle 'G' =  moveTurtle turtle Forward
newTurtle turtle 'f' =  moveTurtle turtle Forward
newTurtle turtle 'g' =  moveTurtle turtle Forward