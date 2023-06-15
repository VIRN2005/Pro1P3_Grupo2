#include "Trapecio.h"
#include <fstream>
// Constructores
Trapecio::Trapecio()
	: a(0), b(0), B(0), c(0), h(0) {
}

Trapecio::Trapecio(int a, int b, int B, int c, int h)
	: a(a), b(b), B(B), c(c), h(h) {
}

//Getters
int Trapecio::getA() const {
	return a;
}

int Trapecio::getb() const {
	return b;
}

int Trapecio::getB() const {
	return B;
}

int Trapecio::getC() const {
	return c;
}

int Trapecio::getH() const {
	return h;
}

//Setters
void Trapecio::setA(int a) {
	this->a = a;
}

void Trapecio::setb(int b) {
	this->b = b;
}

void Trapecio::setB(int B) {
	this->B = B;
}

void Trapecio::setC(int c) {
	this->c = c;
}

void Trapecio::setH(int h) {
	this->h = h;
}

//Métodos
void Trapecio::Dibujar() const {
	ifstream archivoTrapecio("- Trapecio.txt");
	if (!archivoTrapecio) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoTrapecio, line)) {
		line = regex_replace(line, regex("XXaXX"), to_string(a));
		line = regex_replace(line, regex("XXbXX"), to_string(b));
		line = regex_replace(line, regex("XXBXX"), to_string(B));
		line = regex_replace(line, regex("XXcXX"), to_string(c));
		line = regex_replace(line, regex("XXhXX"), to_string(h));

		line = regex_replace(line, regex("XXB+bXX"), to_string(b + B));
		line = regex_replace(line, regex("XXa+cXX"), to_string(a + c));
		line = regex_replace(line, regex("XXperimetroXX"), to_string(B+b+a+c));

		line = regex_replace(line, regex("XXXB+b*hXXX"), to_string((B+b* h)));
		line = regex_replace(line, regex("XXareaXX"), to_string(static_cast<double>(B +b*h) / 2.0));

		cout << line << endl;
	}
}