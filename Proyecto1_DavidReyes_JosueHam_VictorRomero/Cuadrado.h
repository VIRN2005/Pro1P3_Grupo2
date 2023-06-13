#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Cuadrado {
private:
	int a;
public:
	//Constructores
	Cuadrado();
	Cuadrado(int);

	//Getters de Cada Variable Solicitada
	int getA() const;

	//Setters de Cada Variable Solicitada
	void setA(int);

	//Método Dibujar Descrito en las Instruccioness
	void Dibujar() const;
};

