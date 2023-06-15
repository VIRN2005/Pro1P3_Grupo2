#include "Rombo.h"
#include <fstream>
//Cuerpos de los constructores
Rombo::Rombo()
	: a(0), d(0), D(0) {
}

Rombo::Rombo(int ax, int dx, int DX)
	: a(ax), d(dx), D(DX) {
}

//Cuerpos de los getters
int Rombo::getA() const {
	return a;
}
int Rombo::getd() const {
	return d;
}
int Rombo::getD() const {
	return D;
}

//Cuerpos de los setters
void Rombo::setA(int a) {
	this->a = a;
}
void Rombo::setd(int d) {
	this->d = d;
}
void Rombo::setD(int D) {
	this->D = D;
}

void Rombo::Dibujar() const {
	ifstream archivoRombo("- Rombo.txt", ios::in);

	if (!archivoRombo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(archivoRombo, line)) {
		line = regex_replace(line, regex("XXaXX"), to_string(a));
		line = regex_replace(line, regex("XXdXX"), to_string(d));
		line = regex_replace(line, regex("XXDXX"), to_string(D));


		line = regex_replace(line, regex("XXperimetroXX"), to_string(static_cast <double>(4 * a)));

		line = regex_replace(line, regex("\\XXD\\*dXX"), to_string(D * d));
		line = regex_replace(line, regex("XXareaXX"), to_string(static_cast<double>(D * d) / 2.0));

		cout << line << endl;
	}
}