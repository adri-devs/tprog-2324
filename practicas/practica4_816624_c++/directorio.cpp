/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: directorio.cpp
 * Fecha últ modificación: 11/04/2024
*/

#include "directorio.h"

Directorio::Directorio() {
    this->nombre = "";
    this->padre = nullptr;
    this->hijos = new std::vector<Directorio*>();
}

int Directorio::getTamano() const {
    int tamano = 0;
    for (Directorio* hijo : *hijos) {
        tamano += hijo->getTamano();
    }
    return tamano;
}