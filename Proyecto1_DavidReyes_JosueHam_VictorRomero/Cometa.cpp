#include "Cometa.h"
#include <fstream>

// Constructores
Cometa::Cometa()
	: a(0), b(0), d(0), D(0) {
}

Cometa::Cometa(int a, int b, int d, int D)
	: a(a), b(b), d(d), D(D) {
}

//Getters
int Cometa::getA() const {
	return a;
}

int Cometa::getB() const {
	return b;
}

int Cometa::getd() const {
	return d;
}

int Cometa::getD() const {
	return D;
}

//Setters
void Cometa::setA(int a) {
	this->a = a;
}

void Cometa::setB(int b) {
	this->b = b;
}

void Cometa::setd(int d) {
	this->d = d;
}

void Cometa::setD(int D) {
	this->D = D;
}

//Métodos
void Cometa::Dibujar() const {
	ifstream archivoCometa("- Cometa.txt");
	if (!archivoCometa) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoCometa, line)) {
		line = regex_replace(line, regex("XXaXX"), to_string(a));
		line = regex_replace(line, regex("XXbXX"), to_string(b));
		line = regex_replace(line, regex("XXdXX"), to_string(d));
		line = regex_replace(line, regex("XXDXX"), to_string(D));

		line = regex_replace(line, regex("XXXb\\+aXXX"), to_string(b + a));
		line = regex_replace(line, regex("XXperimetroXX"), to_string(2 * (a + b)));

		line = regex_replace(line, regex("XXD\\*dXX"), to_string(D * d));
		line = regex_replace(line, regex("XXareaXX"), to_string(static_cast<double>(D * d) / 2.0));

		cout << line << endl;
	}

}