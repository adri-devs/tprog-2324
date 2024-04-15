/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: enlace.h
 * Fecha últ modificación: 11/04/2024
*/

#ifndef PRACTICA4_816624_C_ENLACE_H
#define PRACTICA4_816624_C_ENLACE_H
#pragma once

#include "nodo.h"
#include <string>
#include <list>
#include <memory>

using namespace std;

class Enlace : public Nodo {
    protected:
        shared_ptr<Nodo> enlace;
    public:
        Enlace(const string& _nombre, shared_ptr<Nodo> _enlace);

        virtual int getTamanyo() const;

        virtual shared_ptr<Nodo> getEnlace() const;
};

#endif //PRACTICA4_816624_C_ENLACE_H