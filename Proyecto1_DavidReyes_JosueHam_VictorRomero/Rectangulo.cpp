#include "Rectangulo.h"
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
    ifstream archivoRectangulo("Rectangulo.txt", ios::in);

    if (!archivoRectangulo) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoRectangulo, line)) {
        line.replace(line.find("XXaXX"), 5, to_string(a));
        line.replace(line.find("XXbXX"), 5, to_string(b));

        cout << line << endl;
    }
}