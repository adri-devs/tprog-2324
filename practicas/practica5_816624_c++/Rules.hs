module Rules where
koch :: Char -> String
koch 'F' = "F+F--F+F"
koch x = [x]

kochCuadrado :: Char -> String
kochCuadrado 'F' = "F+F-F-F+F"
kochCuadrado x = [x]

kochSnowflake :: Char -> String
kochSnowflake 'F' = "F-F++F-F"
kochSnowflake x = [x]

kochAntiSwnowflake :: Char -> String
kochAntiSwnowflake 'F' = "F+F--F+F"
kochAntiSwnowflake x = [x]

isla :: Char -> String
isla 'F' = "F+F-F-FF+F+F-F"
isla x = [x]

trianguloSierpinsky :: Char -> String
trianguloSierpinsky 'F' = "F-G+F+G-F"
trianguloSierpinsky 'G' = "GG"
trianguloSierpinsky x = [x]

arrowHead :: Char -> String
arrowHead 'F' = "G-F-G"
arrowHead 'G' = "F+G+F"
arrowHead x = [x]

hilbert :: Char -> String
hilbert 'f' = "-g>+f>f+>g-"
hilbert 'g' = "+f>-g>g->f+"
hilbert x = [x]

gosper :: Char -> String
gosper 'F' = "F-G--G+F++FF+G-"
gosper 'G' = "+F-GG--G-F++F+G"
gosper x = [x]