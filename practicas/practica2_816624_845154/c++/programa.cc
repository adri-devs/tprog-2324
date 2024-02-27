/*
 * Fichero de implementación de la clase Programa y sus derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 27/02/2024
 */
#include "programa.h"

Programa::Programa(int nInstrucciones) : nInstrucciones(nInstrucciones) {
    prog = new Instruccion*[nInstrucciones]; // Array de punteros->instrucciones
    pc = 0;
}

Programa::~Programa() {
    for (int i = 0; i < getNInstrucciones(); i++) {
        delete getInstruccion(i); // Liberar memoria de cada instrucción
    }

    delete[] prog;
}

void Programa::setInstruccion(int i, Instruccion* instruccion) {
    prog[i] = instruccion; // i actúa como acceso a @pc
}

Instruccion* Programa::getInstruccion(int i) const {
    return prog[i];
}

int Programa::getNInstrucciones() const {
    return nInstrucciones;
}

void Programa::listar() const {
    std::cout << "Programa:" << std::endl;
    for (int i = 0; i < nInstrucciones; i++) {
        std::cout << std::setw(2) << std::to_string(i) << "  "
        << prog[i]->toString() + "\n";
    }
}

void Programa::ejecutar(std::stack<int>& pila) {
    std::cout << "Ejecucion:" << std::endl;
    while (pc < nInstrucciones) {
        prog[pc]->ejecutar(pila, pc);
        // pc se modifica en las instrucciones que lo requieran
        // por tanto el programa no ha de tener errores de acceso.
    }
}

Sumador::Sumador() : Programa(4) {
    // Leemos los dos valores
    setInstruccion(0, new Read());
    setInstruccion(1, new Read());
    // Los sumamos
    setInstruccion(2, new Add());
    // Y mostramos el resultado
    setInstruccion(3, new Write());
}

CuentaAtras::CuentaAtras() : Programa(7) {
    // Leemos un valor
    setInstruccion(0, new Read());
    // Lo duplicamos
    setInstruccion(1, new Dup());
    // Le restamos -1,
    setInstruccion(2, new Write());
    setInstruccion(3, new Push(-1));
    setInstruccion(4, new Add());
    // Duplicamos porque jumpif consume un valor de la pila
    setInstruccion(5, new Dup());
    // Si es mayor que 0, repetimos
    setInstruccion(6, new Jumpif(1));
}

Factorial::Factorial() : Programa(14) {
    // Calculamos el factorial de un número
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