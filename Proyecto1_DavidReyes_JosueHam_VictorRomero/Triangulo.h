#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Triangulo : public Figuras {
private:
	int a;
	int b;
	int c;
	int h;

public:
	//Constructores
	Triangulo(); //Vacio
	Triangulo(int, int, int, int); //Sobrecargado

	//Getters de Cada Variable Solicitada
	int getA() const;
	int getB() const;
	int getC() const;
	int getH() const;

	//Setters de Cada Variable Solicitada
	void setA(int);
	void setB(int);
	void setC(int);
	void setH(int);

	//Método Dibujar Descrito en las Instrucciones
	void Dibujar() const;
};
