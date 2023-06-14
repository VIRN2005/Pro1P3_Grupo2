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
void Paralelogramo::Dibujar() const {
	ifstream archivoParalelogramo("- Paralelogramo.txt");
	if (!archivoParalelogramo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;

	while (getline(archivoParalelogramo, line)) {
		line.replace(line.find("XXaXX"), 5, to_string(a));
		line.replace(line.find("XXbXX"), 5, to_string(b));
		line.replace(line.find("XXhXX"), 5, to_string(h));

		line.replace(line.find("XXXa+bXXX"), 9, to_string(a + b));
		line.replace(line.find("XXperimetroXX"), 13, to_string(2*(a + b)));

		line.replace(line.find("XXareaXX"), 8, to_string(b * h));

		cout << line << endl;
	}

}