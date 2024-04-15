/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: fichero.h
 * Fecha últ modificación: 11/04/2024
*/

#ifndef PRACTICA4_816624_C_FICHERO_H
#define PRACTICA4_816624_C_FICHERO_H
#pragma once

#include "nodo.h"
#include <string>

using namespace std;

class Fichero : public Nodo {
    protected:
        int tamanyo;
    public:
        Fichero(const string& _nombre, int _tamanyo = 0);

        virtual int getTamanyo() const;

        virtual void setTamanyo(int tam);
};

#endif //PRACTICA4_816624_C_FICHERO_H