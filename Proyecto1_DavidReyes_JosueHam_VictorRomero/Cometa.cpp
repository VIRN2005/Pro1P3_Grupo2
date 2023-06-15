#include "Cometa.h"
#include <fstream>
#include <regex>

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
string Cometa::centrar(string entrada, int anchura) {
	int espacios = (anchura - entrada.length()) / 2;
	string mitad = string(espacios, ' ') + entrada;
	return mitad + string((anchura - mitad.length()), ' ');
}

void Cometa::Dibujar() {
	ifstream archivoCometa("- Cometa.txt");
	if (!archivoCometa) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoCometa, line)) {
		line = regex_replace(line, regex("XXaXX"), centrar(to_string(a), 5));
		line = regex_replace(line, regex("XXbXX"), centrar(to_string(b), 5));
		line = regex_replace(line, regex("XXDXX"), centrar(to_string(D), 5));
		line = regex_replace(line, regex("XXdXX"), centrar(to_string(d), 5));

		line = regex_replace(line, regex("XXXb\\+aXXX"), centrar(to_string(b + a), 9));
		line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(2 * (a + b)), 17));

		line = regex_replace(line, regex("XXD\\*dXX"), centrar(to_string(D * d), 7));
		line = regex_replace(line, regex("XXareaXX"), centrar(to_string(static_cast<double>(D * d) / 2.0), 15));

		cout << line << endl;
	}
};