#include "Rectangulo.h"
#include <fstream>
Rectangulo::Rectangulo()
	: a(0), b(0){
}

Rectangulo::Rectangulo(int ax, int bx)
	: a(ax), b(bx) {
}

int Rectangulo::getA() const {
	return a;
}

int Rectangulo::getB() const {
	return b;
}

void Rectangulo::setA(int a) {
	this->a = a;
}

void Rectangulo::setB(int b) {
	this->b = b;
}

void Rectangulo::Dibujar() const {
    ifstream archivoRectangulo("- Rectangulo.txt", ios::in);

    if (!archivoRectangulo) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoRectangulo, line)) {
        line = regex_replace(line, regex("XXaXX"), to_string(a));
        line = regex_replace(line, regex("XXbXX"), to_string(b));

        line = regex_replace(line, regex("XXareaXX"), to_string(static_cast<double>(b * a)));
        line = regex_replace(line, regex("\\XXXb\\+aXXX"), to_string(a + b));
        line = regex_replace(line, regex("XXperimetroXX"), to_string(static_cast<double>(2 * (a + b))));
        
        cout << line << endl;
    }
}