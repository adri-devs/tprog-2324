/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: nodo.h
 * Fecha últ modificación: 11/04/2024
*/

#ifndef PRACTICA4_816624_C_NODO_H
#define PRACTICA4_816624_C_NODO_H
#pragma once

#include <string>

using namespace std;

class Nodo {
    protected:
        string nombre;
    public:
        Nodo(string _nombre);

        string getNombre() const;

        virtual int getTamanyo() const = 0;
};

#endif //PRACTICA4_816624_C_NODO_H