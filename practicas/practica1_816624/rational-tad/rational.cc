/*
    Autores: Adrián Pérez Pallarés (816624) y Alejandro López Torralba (845154)
    Fecha última modificación: 08/02/2024
    Archivo: rational-tad/rational.cc
    Descricpión: Implementación de las funciones de la librería rational.h
*/

#include "rational.h"

// Auxiliares, privadas

int mcd(int a, int b)
{
	return ( b==0 ? a : mcd(b,a%b) );
}

void reduce(Rational& r)
{
	int divisorComun = mcd(r.num, r.den);
    r.num /= divisorComun;
    r.den /= divisorComun;
}

// Inicializadores

void init(Rational& r)
{
	r.num = 0;
    r.den = 1;
}

void init(Rational& r,int num, int den)
{
    // No pide que revisemos si se divide entre cero
	r.num = num;
    r.den = den;
    reduce(r);
}

// Entrada/salida

void write(std::ostream& os, const Rational& r)
{
	os << r.num << "/" << r.den;
}

void read(std::istream& is, Rational& r)
{
	char barra;
    is >> r.num >> barra >> r.den;
    reduce(r); 
}

// Operaciones aritmeticas

Rational add(const Rational& r1, const Rational& r2)
{
    Rational z;
    z.num = r1.num * r2.den + r2.num * r1.den;
    z.den = r1.den * r2.den;
    reduce(z);
    return z;
}

Rational sub(const Rational& r1, const Rational& r2)
{
    Rational z;
    z.num = r1.num * r2.den - r2.num * r1.den;
    z.den = r1.den * r2.den;
    reduce(z);
    return z;
}

Rational mul(const Rational& r1, const Rational& r2)
{
    Rational z;
    z.num = r1.num * r2.num;
    z.den = r1.den * r2.den;
    reduce(z);
    return z;
}

Rational div(const Rational& r1, const Rational& r2)
{
    Rational z;
    z.num = r1.num * r2.den;
    z.den = r1.den * r2.num;
    reduce(z);
    return z;
}

// Operaciones logicas

bool equal(const Rational& r1, const Rational& r2)
{
    return (r1.num == r2.num) && (r1.den == r2.den);
}

bool lesser_than(const Rational& r1, const Rational& r2)
{
    return r1.num * r2.den < r2.num * r1.den;
}

bool greater_than(const Rational& r1, const Rational& r2)
{
    return r1.num * r2.den > r2.num * r1.den;
}
