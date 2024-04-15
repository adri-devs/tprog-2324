/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: fichero.cc
 * Fecha últ modificación: 11/04/2024
*/

#include "fichero.h"

Fichero::Fichero(const string& _nombre, int _tamanyo) : 
    Nodo(_nombre), tamanyo(_tamanyo)
{}

int Fichero::getTamanyo() const {
    return tamanyo;
}

void Fichero::setTamanyo(int tam) {
    tamanyo = tam;
}