#include "Triangulo.h"

void Triangulo::formula_Area() {
	cout << setw(6) << "b * h \n"
		<< setw(6) << "----- \n"
		<< setw(6) << "  2   ";
}

void Triangulo::formula_Perimetro() {
	cout << setw(7) << "a + b + c";
}

void Triangulo::Area(int b, int h) {
	cout << b << " * " << h << endl
		<< setw(6) << "-----\n"
		<< setw(6) << "  2  \n\n";

	int numerador = b * h;
	cout << setw(4) << numerador << endl
		<< setw(6) << "------\n"
		<< setw(7) << "  2  \n\n";

	int respuesta = numerador / 2;
	cout << setw(4) << respuesta << endl;
}

void Triangulo::Perimetro(int a, int b, int c) {
	cout << a << " + " << b << " + " << c << endl << endl;

	int suma = a + b + c;
	cout << setw(6) << suma;
}

void Triangulo::Dibujar(int a, int b, int c, int h) {
	char triangle[10][70] = {
		"                     /-\\",
		"                        /-- | -\\",
		"                     /--    |   -\\",
		"                  /--       |     -\\",
		"              /---          |      -\\",
		"           /--              |        -\\",
		"        /--                 |         -\\",
		"     /--                    |--+        -\\",
		"  /--                       |  |          -\\",
		"---------------------------------------------"
	};

	for (int i = 0; i < 10; i++) {
		cout << triangle[i] << endl;
	}
	cout << "\t\t\tb = " << b << endl;
}

/*void Triangulo::Dibujar() {
	cout << "		   /-\\               " << endl;
	cout << "		  /-- |--\\            " << endl;
	cout << "		 /--   |  -\\          " << endl;
	cout << "		/--     |    -\\        " << endl;
	cout << "		a = " << setw(2) << a << " /--       |       \\c = " << setw(2) << c << endl;
	cout << "    /---           |        -\\     " << endl;
	cout << "   /--              |   h = " << setw(2) << h << "    -\\   " << endl;
	cout << "  /--               |           \\  " << endl;
	cout << " /--                |--+          -\\ " << endl;
	cout << "/---------------------------------------------" << endl;
	cout << "               b = " << setw(2) << b << endl;
}*/