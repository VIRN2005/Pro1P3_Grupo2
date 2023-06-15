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
string Rombo::centrar(string input, int width) {
	int spaces = (width - input.length()) / 2;
	string mid = string(spaces, ' ') + input;
	return mid + string((width - mid.length()), ' ');
}
void Rombo::Dibujar()  {
	ifstream archivoRombo("- Rombo.txt", ios::in);

	if (!archivoRombo) {
		cout << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(archivoRombo, line)) {
		line = regex_replace(line, regex("XXaXX"), centrar(to_string(a), 5));
		line = regex_replace(line, regex("XXdXX"), centrar(to_string(d), 5));
		line = regex_replace(line, regex("XXDXX"), centrar(to_string(D), 5));
		
		line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(static_cast <double>(4 * a)), 13));

		line = regex_replace(line, regex("\\XXD\\*dXX"), centrar(to_string(D * d), 2));
		line = regex_replace(line, regex("XXareaXX"), centrar(to_string(static_cast<double>(D * d) / 2.0), 9));

		cout << line << endl;
	}
}