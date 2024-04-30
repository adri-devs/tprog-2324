import Lsystem
-- import Rules
import Plot
import SVG

pos = (1, 90, (0, 0), 90)
args = ">+>+>+>+>"
fig = tplot pos args

main = do
    savesvg "square" fig
