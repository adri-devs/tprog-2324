/*
 * Programa principal que ejecuta las operaciones de la pila.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 27/02/2024
 */
#include <iostream>
#include <stack>

#include "programa.h"

int main() {
    std::stack<int> pila;

    Sumador sumador;
    sumador.listar();
    std::cout << "\n";
    sumador.ejecutar(pila);
    std::cout << "\n";

    CuentaAtras cuenta;
    cuenta.listar();
    std::cout << "\n";
    cuenta.ejecutar(pila);
    std::cout << "\n";

    Factorial factorial;
    factorial.listar();
    std::cout << "\n";
    factorial.ejecutar(pila);

    return 0;
}