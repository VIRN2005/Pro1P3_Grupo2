#include "Circulo.h"
#include <fstream>
Circulo::Circulo()
	:r(0) {

}

Circulo::Circulo(int rx)
	: r(rx) {
}

int Circulo::getR() const {
	return r;
}

void Circulo::setR(int r) {
	this->r = r;
}

void Circulo::Dibujar() const {
    ifstream archivoCirculo("- Circulo.txt", ios::in);

    if (!archivoCirculo) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoCirculo, line)) {
        line.replace(line.find("XXrXX"), 5, to_string(r));
        line.replace(line.find("XXX3.14*rXXX"), 12, to_string(static_cast<double>(3.14 * r)));
        line.replace(line.find("XXperimetroXX"), 13, to_string(static_cast<double>(2*3.14*r)));
        line.replace(line.find("XXr*rXX"), 7, to_string(r * r));
        line.replace(line.find("XXareaXX"), 8, to_string(3.14 * (r*r)));

        cout << line << endl;
    }
}