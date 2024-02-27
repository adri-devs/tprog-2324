/*
 * Fichero de cabecera de la clase Instruccion y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 27/02/2024
 */
#ifndef INSTRUCCION_H
#define INSTRUCCION_H

#include <iostream>
#include <stack>

// Clase base Instruccion
class Instruccion {
    public:
        virtual void ejecutar(std::stack<int>& pila, int& pc) = 0;
        virtual std::string toString() const = 0;
};

// Clases derivadas de Instruccion
class Add : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Read : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Write : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Push : public Instruccion {
    private:
        int c;
    public:
        Push(int val);
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Dup : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Jumpif : public Instruccion {
    private:
        int l;
    public:
        Jumpif(int val);
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Mul : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Swap : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

class Over : public Instruccion {
    public:
        void ejecutar(std::stack<int>& pila, int& pc);
        std::string toString() const;
};

#endif // PROGRAMA_H