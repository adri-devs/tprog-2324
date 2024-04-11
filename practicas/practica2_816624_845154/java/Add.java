/*
 Clase que implementa la instrucción add
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public class Add implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        int a = pila.pop();
        int b = pila.pop();
        pila.push(a + b);
        pc++;
    }

    public String toString() {
        return "add";
    }
}