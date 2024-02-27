/*
 Clase que implementa la instrucción dup (duplicar el valor en la cima de la
 pila)
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public class Dup implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        int val = pila.peek();
        pila.push(val);
        pc++;
    }

    public String toString() {
        return "dup";
    }
}