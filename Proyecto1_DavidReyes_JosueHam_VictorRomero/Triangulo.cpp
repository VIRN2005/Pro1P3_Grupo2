#include "Triangulo.h"
#include <fstream>
#include <regex>

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
		string espacio = "   ";
		line = regex_replace(line, regex("XXaXX"), to_string(a));
		line = regex_replace(line, regex("XXbXX"), to_string(b));
		line = regex_replace(line, regex("XXcXX"), to_string(c));
		line = regex_replace(line, regex("XXhXX"), to_string(h));


		line = regex_replace(line, regex("\\XXb\\+cXX"), + " " + to_string(b + c));
		line = regex_replace(line, regex("\\XXb\\*hXX"), to_string(b*h));
		
		
		line = regex_replace(line, regex("XXperimetroXX"), to_string(a + b + c));
		line = regex_replace(line, regex("XXareaXX"), to_string(a * a));

		cout << line << endl;

	}

}