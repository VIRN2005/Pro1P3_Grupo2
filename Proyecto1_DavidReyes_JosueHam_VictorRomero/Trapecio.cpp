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
		line.replace(line.find("XXaXX"), 5, to_string(a));
		line.replace(line.find("XXbXX"), 5, to_string(b));
		line.replace(line.find("XXBXX"), 5, to_string(B));
		line.replace(line.find("XXcXX"), 5, to_string(c));
		line.replace(line.find("XXhXX"), 5, to_string(h));

		line.replace(line.find("XXB+bXX"), 7, to_string(B + b));
		line.replace(line.find("XXa+cXX"), 7, to_string(a + c));
		line.replace(line.find("XXperimetroXX"), 13, to_string(B + b + a + c));

		line.replace(line.find("XXXB+bXXX"), 9, to_string(B + b));
		line.replace(line.find("XXXB+b*hXXX"), 11, to_string((B + b) * h));
		line.replace(line.find("XXareaXX"), 8, to_string(static_cast<double>((B + b) * h) / 2.0));

		cout << line << endl;
	}
}