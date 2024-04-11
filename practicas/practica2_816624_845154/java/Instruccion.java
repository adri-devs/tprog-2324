/*
 Interfaz Instruccion utilizada para definir las instrucciones
 que se pueden ejecutar en el programa.
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public interface Instruccion {
    void ejecutar(Stack<Integer> pila, int pc);
    String toString();
}