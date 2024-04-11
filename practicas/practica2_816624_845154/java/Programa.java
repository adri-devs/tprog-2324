/*
 Clase Programa, es abstracta y tiene como atributos el número de instrucciones,
 contador de programa y un array de instrucciones
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public abstract class Programa {
    protected int nInstrucciones;
    protected int pc;
    protected Instruccion[] prog;

    public Programa(int nInstrucciones) {
        this.nInstrucciones = nInstrucciones;
        prog = new Instruccion[nInstrucciones];
        pc = 0;
    }

    public void setInstruccion(int i, Instruccion instruccion) {
        prog[i] = instruccion;
    }

    public Instruccion getInstruccion(int i) {
        return prog[i];
    }

    public int getNInstrucciones() {
        return nInstrucciones;
    }

    public void listar() {
        System.out.println("Programa:");
        for (int i = 0; i < nInstrucciones; i++) {
            System.out.println(String.format("%2d ", i) + prog[i].toString());
        }
    }

    public void ejecutar(Stack<Integer> pila) {
        System.out.println("Ejecucion:");
        while (pc < nInstrucciones) {
            prog[pc].ejecutar(pila, pc);
        }
    }
}