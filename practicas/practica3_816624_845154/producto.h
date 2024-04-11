/*
 * Fichero de cabecera de la clase Producto y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <sstream>
#include "carga.h"
#include "item.h"

using namespace std;

class Producto : public Carga {
    public:
        Producto(const string& _nom, double _vol, double _pes) :
            Carga(_nom, _vol, _pes)
        {}
};

class SerVivo : public Item {
    public:
        SerVivo(const string& _nom, double _vol, double _pes) :
            Item(_nom, _vol, _pes)
        {}

        string tipo() const override {
            return "Seres Vivos";
        }
};

class Toxico : public Item {
    public:
        Toxico(const string& _nom, double _vol, double _pes) :
            Item(_nom, _vol, _pes)
        {}

        string tipo() const override {
            return "Productos Toxicos";
        }
};

#endif // PRODUCTO_H