#include "Triangulo.h"
#include <fstream>

// Constructores
Triangulo::Triangulo()
	: a(0), b(0), c(0), h(0) {
}

Triangulo::Triangulo(int a, int b, int c, int h)
	: a(a), b(b), c(c), h(h) {
}

//Getters
int Triangulo::getA() const {
	return a;
}

int Triangulo::getB() const {
	return b;
}

int Triangulo::getC() const {
	return c;
}

int Triangulo::getH() const {
	return h;
}

//Setters
void Triangulo::setA(int a) {
	this->a = a;
}

void Triangulo::setB(int b) {
	this->b = b;
}

void Triangulo::setC(int c) {
	this->c = c;
}

void Triangulo::setH(int h) {
	this->h = h;
}

//Métodos
void Triangulo::Dibujar() const {
	ifstream archivoTriangulo("- Triangulo.txt");
	if (!archivoTriangulo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoTriangulo, line)) {
		line.replace(line.find("XXaXX"), 5, to_string(a));
		line.replace(line.find("XXbXX"), 5, to_string(b));
		line.replace(line.find("XXcXX"), 5, to_string(c));
		line.replace(line.find("XXhXX"), 5, to_string(h));

		line.replace(line.find("XXb+cXX"), 7, to_string(b + c));
		line.replace(line.find("XXperimetroXX"), 13, to_string(a + b + c));

		line.replace(line.find("XXb*hXX"), 7, to_string(b * h));
		line.replace(line.find("XXareaXX"), 8, to_string(static_cast<double>(b * h) / 2.0));

		cout << line << endl;
	}

}

