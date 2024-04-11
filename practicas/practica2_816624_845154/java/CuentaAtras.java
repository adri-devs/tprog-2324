/*
 Clase que implementa el programa CuentaAtras
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */

public class CuentaAtras extends Programa {
    public CuentaAtras() {
        super(7);
        setInstruccion(0, new Read());
        setInstruccion(1, new Dup());
        setInstruccion(2, new Write());
        setInstruccion(3, new Push(-1));
        setInstruccion(4, new Add());
        setInstruccion(5, new Dup());
        setInstruccion(6, new Jumpif(1));
    }
}