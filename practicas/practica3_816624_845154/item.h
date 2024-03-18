/*
 * Fichero de cabecera de la clase Item y sus clases derivadas.
 * Autores: Alejandro López 845154, Adrián Pérez 816624
 * Fecha últ. modificación: 16/03/2024
 */

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Item {
    protected:
        string nom;
        double vol;
        double pes;

    public:
        Item(const string& _nom, double _vol, double _pes) :
            nom(_nom), vol(_vol), pes(_pes)
        {}

        string nombre() const {
            return nom;
        }

        double volumen() const {
            return vol;
        }

        virtual double peso() const {
            return pes;
        }

        virtual string toString(string tab) const {
            stringstream ss;
            ss << tab << nom << " [" << vol << " m3] " << "[" << pes << " kg]" << endl;
            return ss.str();
        }

        virtual string tipo() const {
            return "Carga Estandar";
        }
};

#endif // ITEM_H