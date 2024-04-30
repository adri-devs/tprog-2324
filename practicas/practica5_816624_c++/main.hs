import LSystem
import Rules
import Plot
import SVG

turtle60 = (1,60,(0,0),0)
turtle90 = (1,90,(0,0),0)
turtle120 = (1,120,(0,0),0)

lkoch = lsystem koch "F" 3
lkochCuadrado = lsystem kochCuadrado "F" 4
lkochSnowflake = lsystem kochSnowflake "F" 3
lisla = lsystem isla "F" 3
ltrianguloSierpinsky = lsystem trianguloSierpinsky "F" 3
larrowHead = lsystem arrowHead "F" 6
lhilbert = lsystem hilbert "F" 4
lgosper = lsystem gosper "F" 3

main = do
    savesvg "koch" (tplot turtle60 lkoch)
    savesvg "kochCuadrado" (tplot turtle90 lkochCuadrado)
    savesvg "kochSnowflake" (tplot turtle60 lkochSnowflake)
    savesvg "isla" (tplot turtle90 lisla)
    savesvg "trianguloSierpinsky" (tplot turtle120 ltrianguloSierpinsky)
    savesvg "arrowHead" (tplot turtle60 larrowHead)
    savesvg "hilbert" (tplot turtle90 lhilbert)
    savesvg "gosper" (tplot turtle60 lgosper)
