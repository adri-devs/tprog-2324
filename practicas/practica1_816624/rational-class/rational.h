/*
    Autores: Adrián Pérez Pallarés (816624) y Alejandro López Torralba (845154)
    Fecha última modificación: 08/02/2024
    Archivo: rational-class/rational.h
    Descricpión: Cabecera de la librería rational.cc. Contiene la definición del TAD Rational.
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

	// Entrada/salida

	void write(std::ostream& os) const;
	void read(std::istream& is);

	// Operaciones aritmeticas

	Rational add(const Rational& r) const;
	Rational sub(const Rational& r) const;
	Rational mul(const Rational& r) const;
	Rational div(const Rational& r) const;

	// Operaciones logicas

	bool equal(const Rational& r) const;
	bool lesser_than(const Rational& r) const;
	bool greater_than(const Rational& r) const;
};
