#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Cometa : public Figuras {
private:
	int a;
	int b;
	int d;
	int D;

public:
	//Constructores
	Cometa();
	Cometa(int, int, int, int);

	//Getters de Cada Variable Solicitada
	int getA() const;
	int getB() const;
	int getd() const;
	int getD() const;

	//Setters de Cada Variable Solicitada
	void setA(int);
	void setB(int);
	void setd(int);
	void setD(int);

	//Método Dibujar Descrito en las Instrucciones
	void Dibujar() const;
};

