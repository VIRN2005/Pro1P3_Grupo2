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
string Triangulo::centrar(string entrada, int anchura) {
	int espacios = (anchura - entrada.length()) / 2;
	string mitad = string(espacios, ' ') + entrada;
	return mitad + string((anchura - mitad.length()), ' ');
}

void Triangulo::Dibujar() {
	ifstream archivoTriangulo("- Triangulo.txt");
	if (!archivoTriangulo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}


	string line;
	while (getline(archivoTriangulo, line)) {
		string espacio = "   ";
		line = regex_replace(line, regex("XXaXX"), centrar(to_string(a),5));
		line = regex_replace(line, regex("XXbXX"), centrar(to_string(b),5));
		line = regex_replace(line, regex("XXcXX"), centrar(to_string(c),5));
		line = regex_replace(line, regex("XXhXX"), centrar(to_string(h),5));


		line = regex_replace(line, regex("\\XXb\\+cXX"), centrar(to_string(b + c), 7));
		line = regex_replace(line, regex("\\XXb\\*hXX"), centrar(to_string(b*h),7));
		
		
		line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(a + b + c), 17));
		line = regex_replace(line, regex("XXareaXX"), centrar(to_string(static_cast<double>(b * h)/ 2.0), 15));

		cout << line << endl;

	}

}