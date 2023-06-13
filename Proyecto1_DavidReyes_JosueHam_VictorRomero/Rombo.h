#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Rombo : public Figuras {
private:
	int a, d, D;
public:

	//Constructores
	Rombo();
	Rombo(int, int, int);

	//Getters
	int getA() const;
	int getd() const;
	int getD() const;

	//Setters
	void setA(int);
	void setd(int);
	void setD(int);

	//Metodos
	void Dibujar() const;
};