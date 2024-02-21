#include <iostream>
#include "cuenta.h"
#include <cmath>

// Buscar sobre constructores delegados

Cuenta::Cuenta(TipoCuenta t, double Ci, double i, int p)
    : tipo(t), Capital(Ci), interes(i), plazo(p) {
    std::cout << "Constructor 1" << std::endl;
} // lO QUE SE PONE ANTES DE LOS PARENTESIS TIENE Q SER UN CAMPO DE LA CLASE

Cuenta::Cuenta(double Ci, double i)
    : tipo(CORRIENTE), Capital(Ci), interes(i) { // no es necesario darle valor a todos los campos
    std::cout << "Constructor 2" << std::endl;
}

Cuenta::Cuenta(double Ci, double i, int p)
    : tipo(PLAZO_FIJO), Capital(Ci), interes(i), plazo(p) {
    std::cout << "Constructor 3" << std::endl;
}

double Cuenta::valor(int t) {
    double res;
    switch(t) {
        case CORRIENTE:
            res = Capital;
            break;
        case AHORRO:
            res = Capital * (1 + interes * t);
            break;
        default:
            res = -1;
    }

    return res;
}

double Cuenta::tae(int t) {
    return pow(1 + interes, t) - 1;
}