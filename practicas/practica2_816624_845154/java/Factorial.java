/*
 Clase que implementa el programa Factorial
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */

public class Factorial extends Programa {
    public Factorial() {
        super(14);
        setInstruccion(0, new Push(1));
        setInstruccion(1, new Read());
        setInstruccion(2, new Swap());
        setInstruccion(3, new Over());
        setInstruccion(4, new Mul());
        setInstruccion(5, new Swap());
        setInstruccion(6, new Push(-1));
        setInstruccion(7, new Add());
        setInstruccion(8, new Dup());
        setInstruccion(9, new Push(-2));
        setInstruccion(10, new Add());
        setInstruccion(11, new Jumpif(2));
        setInstruccion(12, new Swap());
        setInstruccion(13, new Write());
    }
}