/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: directorio.h
 * Fecha últ modificación: 11/04/2024
*/
#ifndef PRACTICA4_816624_C_DIRECTORIO_H
#define PRACTICA4_816624_C_DIRECTORIO_H
#pragma once

#include "nodo.h"
#include <memory>
#include <list>

// Clase Directorio, hereda de Nodo
class Directorio : public Nodo {
private:
    // Atributo que almacena la lista de nodos que contiene el directorio
    // Sería list<Nodo*> nodos, pero tenemos que usar magic pointers.
    list<shared_ptr<Nodo>> nodos;
public:
    // Constructor de un directorio
    Directorio(const string &nombre) : Nodo(nombre) {}

    // Obtiene el tamaño de un directorio (sobreescribe la función heredada de Nodo)
    int getTamano() const override;

    void addNodo(shared_ptr<Nodo> nodo);

    void deleteNodo(shared_ptr<Nodo> nodo); // Quizá sea: void deleteNodo(string &nombre);

    // Mostrar contenido del directorio
    list<shared_ptr<Nodo>> getDirEls() const;
    string showDir() const;
    string calcDirSize() const;
    bool exists(string &nombre) const;
}

#endif //PRACTICA4_816624_C_DIRECTORIO_H
