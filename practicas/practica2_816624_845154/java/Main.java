/*
 Archivo: Main.java
 Autores: Alejandro López 845154, Adrián Pérez 816624
 Fecha últ modificación: 27/02/2024
 */
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> pila = new Stack<>();

        Sumador sumador = new Sumador();
        sumador.listar();
        System.out.println("\n");
        sumador.ejecutar(pila);
        System.out.println("\n");

        CuentaAtras cuenta = new CuentaAtras();
        cuenta.listar();
        System.out.println("\n");
        cuenta.ejecutar(pila);
        System.out.println("\n");

        Factorial factorial = new Factorial();
        factorial.listar();
        System.out.println("\n");
        factorial.ejecutar(pila);
    }
}