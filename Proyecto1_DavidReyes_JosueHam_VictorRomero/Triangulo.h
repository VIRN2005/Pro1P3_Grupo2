#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <iostream>
#include <iomanip>
#include "Figura.h"
using namespace std;

class Triangulo : public Figura {
private:
	int a;
	int b;
	int c;
	int h;

public:
	void formula_Area() override;
	void formula_Perimetro() override;
	void Area(int, int);
	void Perimetro(int, int, int);
	void Dibujar(int, int, int, int);
};

# endif
