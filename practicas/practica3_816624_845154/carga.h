/*
 * Fichero de cabecera de la clase Carga y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */

#ifndef CARGA_H
#define CARGA_H

#include <iostream>
#include <string>
#include <sstream>
#include "item.h"

using namespace std;

class Carga : public Item {
    public:
        Carga(const string& _nom, double _vol, double _pes) :
            Item(_nom, _vol, _pes)
        {}
};

#endif // CARGA_H