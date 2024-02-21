/*
    Autores: Adrián Pérez Pallarés (816624) y Alejandro López Torralba (845154)
    Fecha última modificación: 08/02/2024
    Archivo: rational-class/rational.h
    Descricpión: Cabecera de la librería rational.cc.
	Se ha transformado de struct a clase en la tarea 2.
*/

#include "rational.h"

// Auxiliares

int Rational::mcd(int a, int b)
{
	return ( b == 0 ? a : mcd(b,a%b));
}

void Rational::reduce()
{
	int divisorComun = mcd(num, den);
	num /= divisorComun;
	den /= divisorComun;
}

// Constructores

Rational::Rational()
{
	num = 0;
	den = 1;
}

Rational::Rational(int num, int den)
{
	// No pide que revisemos si se divide entre cero
	this->num = num;
	this->den = den;
	reduce();
}

// Operadores aritmeticos

Rational Rational::operator+(const Rational& r) const
{
	Rational z;
	z.num = num * r.den + r.num * den;
	z.den = den * r.den;
	z.reduce();
	return z;
}

Rational Rational::operator-(const Rational& r) const
{
	Rational z;
	z.num = num * r.den - r.num * den;
	z.den = den * r.den;
	z.reduce();
	return z;
}

Rational operator*(const Rational& a, const Rational& b)
{
	Rational z;
	z.num = a.num * b.num;
	z.den = a.den * b.den;
	z.reduce();
	return z;
}

Rational operator/(const Rational& a, const Rational& b)
{
	Rational z;
	z.num = a.num * b.den;
	z.den = a.den * b.num;
	z.reduce();
	return z;
}

// Operadores logicos

bool Rational::operator==(const Rational& r) const
{
	return (num == r.num && den == r.den);
}

bool Rational::operator<(const Rational& r) const
{
	return (num * r.den < r.num * den);
}

bool Rational::operator>(const Rational& r) const
{
	return (num * r.den > r.num * den);
}


// Entrada/salida

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	os << r.num << "/" << r.den;
	return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
	char barra;
	is >> r.num >> barra >> r.den;
	r.reduce();
	return is;
}



