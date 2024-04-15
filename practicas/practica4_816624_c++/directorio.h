/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: directorio.h
 * Fecha últ modificación: 11/04/2024
*/
#ifndef PRACTICA4_816624_C_DIRECTORIO_H
#define PRACTICA4_816624_C_DIRECTORIO_H
#pragma once

#include "nodo.h"
#include <string>
#include <list>
#include <memory>

using namespace std;

class Directorio : public Nodo {
    protected:
        list<shared_ptr<Nodo>> elems;
    public:
        Directorio(const string& _nombre);

        virtual int getTamanyo() const;

        void guardar(shared_ptr<Nodo> elem);

        void eliminar(shared_ptr<Nodo> elem);

        list<shared_ptr<Nodo>> contenidoPtr() const;

        string contenido();

        string contenidoTamanyo();

        shared_ptr<Nodo> existe(const string& nombre);
};

#endif //PRACTICA4_816624_C_DIRECTORIO_H