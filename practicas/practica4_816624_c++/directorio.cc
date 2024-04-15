/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: directorio.cc
 * Fecha últ modificación: 11/04/2024
*/

#include "directorio.h"
#include <iostream>

Directorio::Directorio(const string& _nombre) : 
    Nodo(_nombre) 
{}

int Directorio::getTamanyo() const {
    int tam = 0;
    for (auto i : elems){
        tam += i->getTamanyo();
    }

    return tam;
}

void Directorio::guardar(shared_ptr<Nodo> elem) {
    elems.push_back(elem);
}

void Directorio::eliminar(shared_ptr<Nodo> elem) {
    elems.remove(elem);
}

list<shared_ptr<Nodo>> Directorio::contenidoPtr() const {
    return elems;
}

string Directorio::contenido() {
    string contenido;

    bool primero = true;
    for (auto i : elems) {
        if (primero) {
            contenido = i->getNombre();
            primero = false;
        }
        else {
            contenido += "\n" + i->getNombre();
        }
    }

    if (elems.size() != 0) {
        contenido += "\n";
    }

    return contenido;
}

string Directorio::contenidoTamanyo() {
    string contenido;

    bool primero = true;
    for (auto i : elems) {
        string tam = to_string(i->getTamanyo());
        if (primero) {
            contenido = i->getNombre() + " " + tam;
            primero = false;
        }
        else {
            contenido += "\n" + i->getNombre() + " " + tam;
        }
    }

    if (elems.size() != 0) {
        contenido += "\n";
    }

    return contenido;
}

shared_ptr<Nodo> Directorio::existe(const string& nombre) {
    for (auto i : elems) {
        if (i->getNombre() == nombre) {
            return i;
        }
    }

    return nullptr;
}