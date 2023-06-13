#include <iostream>
#include "Triangulo.h"
using namespace std;


// Prueba de code
int main() {
	Triangulo triangulo;
	triangulo.formula_Area();
	cout << endl;
	triangulo.formula_Perimetro();
	cout << endl;

	int b = 5;
	int h = 7;
	triangulo.Area(b, h);

	int a = 3;
	int c = 4;
	triangulo.Perimetro(a, b, c);

	triangulo.Dibujar(a,b,c,h);
} 