#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;
class Circulo {
private:
	int r;
public:
	//Constructores
	Circulo();
	Circulo(int);

	//Getters de Cada Variable Solicitada
	int getR() const;

	//Setters de Cada Variable Solicitada
	void setR(int);

	//Método Dibujar Descrito en las Instruccioness
	void Dibujar() const;

};