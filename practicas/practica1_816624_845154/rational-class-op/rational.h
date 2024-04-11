/*
    Autores: Adrián Pérez Pallarés (816624) y Alejandro López Torralba (845154)
    Fecha última modificación: 08/02/2024
    Archivo: rational-class-op/rational.h
    Descricpión: Cabecera de la tercera tarea de rational.h. Contiene la definición del TAD Rational.
	Se ha transformado de struct a clase en la tarea 2.
*/

#pragma once

#include <iostream>

// Solucion con atributos privados.

class Rational
{
private:
	// Atributos
	int num;
	int den;

private:
	// Auxiliares
	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int num, int den);

	// Operadores aritmeticos
	Rational operator+(const Rational& r) const;
	Rational operator-(const Rational& r) const;
	friend Rational operator*(const Rational& a, const Rational& b);
	friend Rational operator/(const Rational& a, const Rational& b);

	// Operadores logicos
	bool operator==(const Rational& r) const;
	bool operator<(const Rational& r) const;
	bool operator>(const Rational& r) const;

	// Friends, en su caso
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);
	friend std::istream& operator>>(std::istream& is, Rational& r);

};

// Operadores aritmeticos
Rational operator*(const Rational& a, const Rational& b);
Rational operator/(const Rational& a, const Rational& b);

// Entrada/salida
std::ostream& operator<<(std::ostream& os, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& r);