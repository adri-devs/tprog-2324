/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: nodo.cc
 * Fecha últ modificación: 11/04/2024
*/

#include "nodo.h"

Nodo::Nodo(string _nombre) : nombre(_nombre) {}

string Nodo::getNombre() const
{
    return nombre;
}
int Nodo::getTamanyo() const
{
    return 0;
}