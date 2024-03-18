/*
 * Fichero de cabecera de la clase Camion y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */

#ifndef CAMION_H
#define CAMION_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "carga.h"
#include "almacen.h"

using namespace std;

class Camion : public Item, public Almacen<Carga> {
public:
    Camion(double _cap) :
        Item("Camion", _cap, 0.0), Almacen(_cap)
    {}

    double peso() const override {
        return this->pesoAlmacen();
    }

    string toString(string tab) const override {
        stringstream ss;
        ss << tab << nom << " [" << vol << " m3] " << "[" << peso() << " kg]" << endl;
        ss << this->mostrarAlmacen(tab + "  ");

        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Camion& camion) {
        os << camion.toString("");

        return os;
    }
};

#endif // CAMION_H