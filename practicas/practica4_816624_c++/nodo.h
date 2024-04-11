/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: nodo.h
 * Fecha últ modificación: 11/04/2024
*/

#ifndef PRACTICA4_816624_C_NODO_H
#define PRACTICA4_816624_C_NODO_H

#include <string>
using namespace std;

class Nodo {
    protected:
        string nombre;
    public:
        // Constructor
        Nodo(const string &nombre) : nombre(nombre) {}
        virtual int obtenerTamano() const;
        string obtenerNombre() const;
};

#endif //PRACTICA4_816624_C_NODO_H