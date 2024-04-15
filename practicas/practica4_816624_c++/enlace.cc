/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: enlace.cc
 * Fecha últ modificación: 11/04/2024
*/

#include "enlace.h"

Enlace::Enlace(const string& _nombre, shared_ptr<Nodo> _enlace) :
    Nodo(_nombre), enlace(_enlace)
{}

int Enlace::getTamanyo() const {
    return enlace->getTamanyo();
}

shared_ptr<Nodo> Enlace::getEnlace() const {
    return enlace;
}