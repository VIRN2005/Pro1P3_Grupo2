#include "Trapecio.h"
#include <fstream>
#include <regex>

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
string Trapecio::centrar(string input, int width) {
	int spaces = (width - input.length()) / 2;
	string mid = string(spaces, ' ') + input;
	return mid + string((width - mid.length()), ' ');
}
void Trapecio::Dibujar() {
	ifstream archivoTrapecio("- Trapecio.txt");
	if (!archivoTrapecio) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoTrapecio, line)) {
		line = regex_replace(line, regex("XXaXX"), centrar(to_string(a), 6));
		line = regex_replace(line, regex("XXbXX"), centrar(to_string(b), 4));
		line = regex_replace(line, regex("XXBXX"), centrar(to_string(B), 4));
		line = regex_replace(line, regex("XXcXX"), centrar(to_string(c), 6));
		line = regex_replace(line, regex("XXhXX"), centrar(to_string(h), 5));

		line = regex_replace(line, regex("XXB\\+bXX"), centrar(to_string(b + B), 5));
		line = regex_replace(line, regex("XXa\\+cXX"), centrar(to_string(a + c), 5));
		line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(B + b + a + c), 17));

		line = regex_replace(line, regex("XXXB\\+b\\*hXXX"), centrar(to_string((B + b * h)), 11));
		line = regex_replace(line, regex("XXareaXX"), centrar(to_string(static_cast<double>(B + b * h) / 2.0), 15));

		cout << line << endl;
	}
}