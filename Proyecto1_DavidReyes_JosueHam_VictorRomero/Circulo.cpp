#include "Circulo.h"
#include <fstream>
#include <regex>

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
        line = regex_replace(line, regex("XXrXX"), to_string(r));
        
        line = regex_replace(line, regex("XXX3.14\\*rXXX"), to_string(static_cast<double>(3.14 * r)));
        line = regex_replace(line, regex("XXperimetroXX"), to_string(static_cast<double>(2 * 3.14 * r)));
        
        line = regex_replace(line, regex("XXr\\*rXX"), to_string(r * r));
        line = regex_replace(line, regex("XXareaXX"), to_string(3.14 * (r * r)));

        cout << line << endl;
    }
}