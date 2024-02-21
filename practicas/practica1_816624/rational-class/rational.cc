/*
    Autores: Adrián Pérez Pallarés (816624) y Alejandro López Torralba (845154)
    Fecha última modificación: 08/02/2024
    Archivo: rational-class/rational.h
    Descricpión: Cabecera de la librería rational.cc. Contiene la definición del TAD Rational.
	Se ha transformado de struct a clase.
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

// Entrada/salida

void Rational::write(std::ostream& os) const
{
	os << num << "/" << den;
}

void Rational::read(std::istream& is)
{
	char barra;
    is >> num >> barra >> den;
    reduce();
}

// Operaciones aritmeticas

Rational Rational::add(const Rational& r) const
{
	Rational z;
	z.num = num * r.den + r.num * den;
	z.den = den * r.den;
	z.reduce();
	return z;
}

Rational Rational::sub(const Rational& r) const
{
	Rational z;
	z.num = num * r.den - r.num * den;
	z.den = den * r.den;
	z.reduce();
	return z;
}

Rational Rational::mul(const Rational& r) const
{
	Rational z;
	z.num = num * r.num;
	z.den = den * r.den;
	z.reduce();
	return z;
}

Rational Rational::div(const Rational& r) const
{
	Rational z;
	z.num = num * r.den;
	z.den = den * r.num;
	z.reduce();
	return z;
}

// Operaciones logicas

bool Rational::equal(const Rational& r) const
{
	return num == r.num && den == r.den;
}

bool Rational::lesser_than(const Rational& r) const
{
	return num * r.den < r.num * den;
}

bool Rational::greater_than(const Rational& r) const
{
	return num * r.den > r.num * den;
}
