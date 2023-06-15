#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Rectangulo : public Figuras {
private: 
	int a, b;
public:
	Rectangulo();
	Rectangulo(int, int);

	int getA() const;
	int getB() const;

	void setA(int);
	void setB(int);

	void Dibujar() ;
	string centrar(string input, int width);
};