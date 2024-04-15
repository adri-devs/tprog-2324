/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: shell.h
 * Fecha últ modificación: 11/04/2024
*/

#ifndef PRACTICA4_816624_C_SHELL_H
#define PRACTICA4_816624_C_SHELL_H
#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <list>
#include <memory>
#include <cstring>
#include "nodo.h"
#include "fichero.h"
#include "directorio.h"
#include "enlace.h"
#include "excepciones.h"

using namespace std;

class Shell {
    protected:
        Directorio raiz;
        list<shared_ptr<Directorio>> ruta;

    public:
        Shell();

        string pwd();

        string ls();

        string du();

        void vi(string name, int size);

        void mkdir(string name);

        void cd(string path);

        void ln(string path, string name);

        int stat(string path);

        void rm(string path);
};

#endif //PRACTICA4_816624_C_SHELL_H