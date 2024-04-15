/*
 * Autores: Alejandro López (845154) y Adrián Pérez (816624)
 * Archivo: shell.cc
 * Fecha últ modificación: 11/04/2024
*/

#include "shell.h"

using namespace std;

Shell::Shell() : 
raiz("/")
{
    ruta.push_back(make_shared<Directorio>(raiz));
}

string Shell::pwd() {
    string ruta_str;

    int cont = 2;
    for (auto i : ruta) {
        if (cont) {
            ruta_str += i->getNombre();
            cont--;
        }
        else {
            ruta_str += "/" + i->getNombre();
        }
    }

    return ruta_str;
}

string Shell::ls() {
    return ruta.back()->contenido();
}

string Shell::du() {
    return ruta.back()->contenidoTamanyo();
} 

void Shell::vi(string name, int size) {
    if (((int)name.find("/") != -1) || ((int)name.find(".") != -1)) {
        throw nombre_invalido();
    }

    if (size < 0) {
        throw tamanyo_negativo();
    }

    shared_ptr<Nodo> encontrado = ruta.back()->existe(name);
    if (dynamic_pointer_cast<Directorio>(encontrado)) {
        throw editar_directorio();
    }
    else if (dynamic_pointer_cast<Enlace>(encontrado)) {
        throw editar_enlace();
    }
    else {
        if (encontrado) {
            shared_ptr<Fichero> fichero = dynamic_pointer_cast<Fichero>(encontrado);
            fichero->setTamanyo(size);
        }
        else {
            shared_ptr<Fichero> nuevo = make_shared<Fichero>(Fichero(name, size));
            ruta.back()->guardar(nuevo);
        }
    }
}

void Shell::mkdir(string name) {
    if (((int)name.find("/") != -1) || ((int)name.find(".") != -1)) {
        throw nombre_invalido();
    }

    shared_ptr<Directorio> nuevo = make_shared<Directorio>(Directorio(name));
    ruta.back()->guardar(nuevo);
}

void Shell::cd(string path) {
    if (path != ".") {
        if (path == "..") {
            if(ruta.size() > 1) {
                ruta.pop_back();
            }
            else {
                throw ya_raiz();
            }
        }
        else if (path == "/") {
            shared_ptr<Directorio> raiz = ruta.front();
            ruta.clear();
            ruta.push_back(raiz);
        }
        else if ((int)path.find_last_of("/") > -1) {
            if (path[0] == '/') {
                cd("/");
            }

            char *token;
            token = strtok((char*)path.c_str(), "/");
            while (token) {
                cd(token);
                token = strtok(NULL, "/");
            }
        }
        else {
            shared_ptr<Nodo> aux = ruta.back()->existe(path);
            if (!dynamic_pointer_cast<Directorio>(aux)) {
                throw no_directorio();
            }

            if (!aux) {
                throw no_existe();
            }

            ruta.push_back(dynamic_pointer_cast<Directorio>(aux));
        }
    }
}

void Shell::ln(string path, string name) {
    string currentPath = pwd();
    int posicion = path.find_last_of("/");
    if (posicion == 0) {
        cd("/");
    }
    else {
        cd(path.substr(0, posicion));
    }

    shared_ptr<Nodo> enlazado = ruta.back()->existe(path.substr(posicion + 1, path.size()));
    if (!enlazado) {
        throw no_existe();
    }

    string fichero = path.substr(1, path.size());
    cd(currentPath);

    if (ruta.back()->existe(name) != NULL) {
        throw mismo_nombre();
    }

    if (((int)name.find(".") != -1)) {
        throw nombre_invalido();
    }

    shared_ptr<Enlace> nuevo;
    nuevo = make_shared<Enlace>(name, enlazado);
    ruta.back()->guardar(nuevo);
}


int Shell::stat(string path) {
    string currentPath = pwd();
    int posicion = path.find_last_of("/");
    string fichero;

    if (posicion == -1) {
        fichero = path;
    }
    else if (posicion == 0) {
        cd("/");
        fichero = path.substr(1);
    }
    else if (posicion > 0) {
        cd(path.substr(0, posicion));
        fichero = path.substr(posicion + 1);
    }

    shared_ptr<Nodo> aux;
    if (path == "/") {
        aux = ruta.back();
    }
    else {
        aux = ruta.back()->existe(fichero);
    }

    if (!aux) {
        throw no_existe();
    }

    int tamanyo = aux->getTamanyo();
    cd(currentPath);

    return tamanyo;
}

void Shell::rm( string path) {
    string currentPath = pwd();
    if (strstr(currentPath.c_str(), path.c_str()) != nullptr) {
        throw fallo_remove();
    }

    int posicion = path.find_last_of("/");
    if (posicion != 1) {
        shared_ptr<Nodo> aux = ruta.back()->existe(path.substr(posicion + 1, path.size()));
        if (!aux) {
            throw no_existe();
        } 
        else{
            if (dynamic_pointer_cast<Fichero>(aux) != nullptr) {
                ruta.back()->eliminar(aux);
            }
            else if (dynamic_pointer_cast<Enlace>(aux) != nullptr) {
                ruta.back()->eliminar(aux);
            }
            else {
                if (dynamic_pointer_cast<Directorio>(aux)->getTamanyo() == 0) {
                    ruta.back()->eliminar(aux);
                }
                else {
                    cd(currentPath + "/" + path);
                    aux = ruta.back();

                    for(auto i : dynamic_pointer_cast<Directorio>(aux)->contenidoPtr()) {
                        rm(i->getNombre());
                    }

                    cd(currentPath);
                    aux = ruta.back()->existe(path.substr(posicion + 1, path.size()));
                    ruta.back()->eliminar(aux);
                }
            }
        }
    }
    else {
        cd(path.substr(0, posicion - 1));
        shared_ptr<Nodo> aux = ruta.back()->existe(path.substr(posicion + 1, path.size()));
        rm(aux->getNombre());
    }
}