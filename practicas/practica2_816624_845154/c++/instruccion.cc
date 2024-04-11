/*
 * Fichero de implementación de las clases de instrucción
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 27/02/2024
 */
#include "instruccion.h"

// Implementación de las clases de instrucción
// add: suma los dos elementos superiores de la pila y apila el resultado
void Add::ejecutar(std::stack<int>& pila, int& pc) {
    int a = pila.top();
    pila.pop();
    int b = pila.top();
    pila.pop();
    pila.push(a + b);
    pc++;
}

std::string Add::toString() const {
    return "add";
}

// read: lee un entero de la entrada y lo apila
void Read::ejecutar(std::stack<int>& pila, int& pc) {
    int a;
    std::cin >> a;
    pila.push(a);
    pc++;
}

std::string Read::toString() const {
    return "read";
}

// write: desapila un entero y lo imprime en la salida
void Write::ejecutar(std::stack<int>& pila, int& pc) {
    std::cout << pila.top() << std::endl;
    pila.pop();
    pc++;
}

std::string Write::toString() const {
    return "write";
}

Push::Push(int val) : c(val) {}

// push: apila un entero
void Push::ejecutar(std::stack<int>& pila, int& pc) {
    pila.push(c);
    pc++;
}

std::string Push::toString() const {
    return "push " + std::to_string(c);
}

// dup: duplica el elemento superior de la pila
void Dup::ejecutar(std::stack<int>& pila, int& pc) {
    int val = pila.top();
    pila.pop();
    pila.push(val);
    pila.push(val);
    pc++;
}

std::string Dup::toString() const {
    return "dup";
}

Jumpif::Jumpif(int val) : l(val) {}

// jumpif: desapila un entero y, si es mayor o igual que cero,
// salta a la instrucción l
void Jumpif::ejecutar(std::stack<int>& pila, int& pc) {
    int val = pila.top();
    pila.pop();
    if (val >= 0) {
        pc = l;
    }
    else {
        pc++;
    }
}

std::string Jumpif::toString() const {
    return "jumpif " + std::to_string(l);
}

// mul: multiplica los dos elementos superiores de la pila y apila el resultado
void Mul::ejecutar(std::stack<int>& pila, int& pc) {
    int a = pila.top();
    pila.pop();
    int b = pila.top();
    pila.pop();
    pila.push(a * b);
    pc++;
}

std::string Mul::toString() const {
    return "mul";
}

// swap: intercambia los dos elementos superiores de la pila
void Swap::ejecutar(std::stack<int>& pila, int& pc) {
    int a = pila.top();
    pila.pop();
    int b = pila.top();
    pila.pop();
    pila.push(a);
    pila.push(b);
    pc++;
}

std::string Swap::toString() const {
    return "swap";
}

// over: duplica el segundo elemento superior de la pila
void Over::ejecutar(std::stack<int>& pila, int& pc) {
    int a = pila.top();
    pila.pop();
    int b = pila.top();
    pila.pop();
    pila.push(b);
    pila.push(a);
    pila.push(b);
    pc++;
}

std::string Over::toString() const {
    return "over";
}