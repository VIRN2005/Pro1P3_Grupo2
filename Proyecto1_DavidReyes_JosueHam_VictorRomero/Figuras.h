#ifndef FIGURAS_H
#define FIGURAS_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include "Circulo.h"
#include "Cometa.h"
#include "Cuadrado.h"
#include "Paralelogramo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include "Trapecio.h"
#include "Triangulo.h"
using namespace std;

class Figuras {
public:
	static void Main_Figuras(int argc, char* argv[]);

private:
	static void Mensaje_FiguraInvalida();
	static int Eleccion_Figuras(int argc, char* argv[]);
};

#endif
