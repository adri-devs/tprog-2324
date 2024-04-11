/*
 * Fichero de cabecera para la clase Programa y sus clases derivadas
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 27/02/2024
 */
#ifndef PROGRAMA_H
#define PROGRAMA_H

#include <iostream>
#include <iomanip>
#include <stack>
#include "instruccion.h"

// Clase Programa
class Programa {
    protected:
        int nInstrucciones;
        int pc;
        Instruccion** prog;
    public:
        Programa(int nInstrucciones);
        ~Programa();
        void setInstruccion(int i, Instruccion* instruccion);
        Instruccion* getInstruccion(int i) const;
        int getNInstrucciones() const;
        void listar() const;
        void ejecutar(std::stack<int>& pila);
};

// Clases derivadas
class Sumador : public Programa {
    public:
        Sumador();
};

class CuentaAtras : public Programa {
    public:
        CuentaAtras();
};

class Factorial : public Programa {
    public:
        Factorial();
};

#endif // PROGRAMA_H