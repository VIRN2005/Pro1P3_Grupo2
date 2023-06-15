#pragma once
#include <iostream>
#include <iomanip>
#include "Figuras.h"
using namespace std;

class Paralelogramo : public Figuras {
private:
	int h;
	int a;
	int b;

public:
	//Constructores
	Paralelogramo();//vacio
	Paralelogramo(int, int, int);//sobrecargado
	
	//getter
	int getA() const;
	int getB() const;
	int getH() const;
	
	//setter
	void setA(int);
	void setB(int);
	void setH(int);

	//Dibujar
	void Dibujar();
	string centrar(string, int);
};

