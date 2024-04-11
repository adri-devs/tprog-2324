/*
 * Fichero de cabecera de la clase Contenedor y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */
 
#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "carga.h"
#include "almacen.h"

using namespace std;

template <class T>
class Contenedor : public Carga, public Almacen<T> {
public:
    Contenedor(double _cap) :
        Carga("Contenedor", _cap, 0.0), Almacen<T>(_cap)
    {}

    double peso() const override {
        return this->pesoAlmacen();
    }

    string toString(string tab) const override {
        stringstream ss;
        ss << tab << nombre() << " [" << volumen() << " m3] " << "[" << peso() << " kg] de " << this->elems.front()->tipo() << endl;
        ss << this->mostrarAlmacen(tab + "  ");

        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Contenedor& contenedor) {
        os << contenedor.toString("");

        return os;
    }
};

#endif // CONTENEDOR_H