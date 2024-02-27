/*
 Clase que implementa la instrucción over (duplicar el segundo valor en la cima
  de la pila)
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public class Over implements Instruccion {
    public void ejecutar(Stack<Integer> pila, int pc) {
        int a = pila.pop();
        int b = pila.pop();
        pila.push(b);
        pila.push(a);
        pila.push(b);
        pc++;
    }

    public String toString() {
        return "over";
    }
}