#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Trapecio : public Figuras {
private:
	int a;
	int b;
	int B;
	int c;
	int h;

public:
	//Constructores
	Trapecio();
	Trapecio(int, int, int, int, int);

	//Getters de Cada Variable Solicitada
	int getA() const;
	int getb() const;
	int getB() const;
	int getC() const;
	int getH() const;

	//Setters de Cada Variable Solicitada
	void setA(int);
	void setb(int);
	void setB(int);
	void setC(int);
	void setH(int);

	//Método Dibujar Descrito en las Instrucciones
	void Dibujar() const;
};

