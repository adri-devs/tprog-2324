/*
 Clase que implementa la instrucción jumpif (salto condicional)
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public class Jumpif implements Instruccion {
    private int l;

    public Jumpif(int val) {
        this.l = val;
    }

    public void ejecutar(Stack<Integer> pila, int pc) {
        int val = pila.pop();
        if (val >= 0) {
            pc = l;
        } else {
            pc++;
        }
    }

    public String toString() {
        return "jumpif " + l;
    }
}