/*
 * Fichero de cabecera de la clase Almacen y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */

#ifndef ALMACEN_H
#define ALMACEN_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

template <class T>
class Almacen {
    protected:
        double cap;
        list<T*> elems;

    public:
        Almacen(double _cap) :
            cap(_cap)
        {}

        double capacidad() const {
            return cap;
        }

        bool guardar(T* elem) {
            double vol = 0.0;
            for (auto i : elems) {
                vol = vol + i->volumen();
            }

            if (vol + elem->volumen() > cap) {
                return false;
            }

            elems.push_back(elem);
            return true;
        }

        double pesoAlmacen() const {
            double peso = 0.0;
            for (auto i : elems) {
                peso += i->peso();
            }

            return peso;
        }

        string mostrarAlmacen(string tab) const {
            stringstream ss;
            for (auto i : elems) {
                ss << i->toString(tab);
            }

            return ss.str();
        }
};

#endif // ALMACEN_H