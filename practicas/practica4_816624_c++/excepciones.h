#pragma once
class arbol_ficheros_error {
    public:
        virtual const char* what() const throw() { 
            return "";
        }
};

class nombre_invalido : public arbol_ficheros_error {
    const char* what() const throw() {
        return "El nombre contiene \"/\" o \".\"";
    }
};

class tamanyo_negativo : public arbol_ficheros_error {
    const char* what() const throw() {
        return "El tamanyo no puede ser un numero negativo";
    }
};

class editar_directorio : public arbol_ficheros_error {
    const char* what() const throw() {
        return "No se puede editar un directorio";
    }
};

class editar_enlace : public arbol_ficheros_error {
    const char* what() const throw() {
        return "No se puede editar un enlace";
    }
};

class ya_raiz : public arbol_ficheros_error {
    const char* what() const throw() {
        return "Ya estas en raiz";
    }
};

class no_existe : public arbol_ficheros_error {
    const char* what() const throw() { 
        return "El fichero o directorio no existe";
    }
};

class fallo_remove : public arbol_ficheros_error {
    const char* what() const throw() {
        return "No se pude borrar este directorio, te encuentras en el o una de sus subcarpetas.";
    }
};

class no_directorio : public arbol_ficheros_error {
    const char* what() const throw() {
        return "No es un directorio";
    }
};

class mismo_nombre : public arbol_ficheros_error {
    const char* what() const throw() {
        return "Nombre ya en uso";
    }
};