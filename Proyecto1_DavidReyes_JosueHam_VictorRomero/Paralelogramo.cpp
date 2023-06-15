#include "Paralelogramo.h"
#include <fstream>
// Constructores
Paralelogramo::Paralelogramo()
	: a(0), b(0), h(0) {
}

Paralelogramo::Paralelogramo(int a, int b, int h)
	: a(a), b(b), h(h) {
}

//Getters
int Paralelogramo::getA() const {
	return a;
}

int Paralelogramo::getB() const {
	return b;
}

int Paralelogramo::getH() const {
	return h;
}

//Setters
void Paralelogramo::setA(int a) {
	this->a = a;
}

void Paralelogramo::setB(int b) {
	this->b = b;
}

void Paralelogramo::setH(int h) {
	this->h = h;
}

//metodos
string Paralelogramo::centrar(string entrada, int anchura) {
	int espacios = (anchura - entrada.length()) / 2;
	string mitad = string(espacios, ' ') + entrada;
	return mitad + string((anchura - mitad.length()), ' ');
}

void Paralelogramo::Dibujar() {
	ifstream archivoParalelogramo("- Paralelogramo.txt");
	if (!archivoParalelogramo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoParalelogramo, line)) {
		line = regex_replace(line, regex("XXaXX"), centrar(to_string(a),5));
		line = regex_replace(line, regex("XXbXX"), centrar(to_string(b), 5));
		line = regex_replace(line, regex("XXhXX"), centrar(to_string(h), 5));
		
		line = regex_replace(line, regex("XXXa\\+bXXX"), centrar(to_string(a + b),9));
		line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(2 * (a + b)),17));
		
		line = regex_replace(line, regex("XXareaXX"), centrar(to_string(b * h),15));
		
		cout << line << endl;
	}

}