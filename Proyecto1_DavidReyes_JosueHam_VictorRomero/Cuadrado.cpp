#include "Cuadrado.h"

Cuadrado::Cuadrado()
	:a(0) {

}

Cuadrado::Cuadrado(int ax) 
	: a(ax){
}

int Cuadrado::getA() const {
	return a;
}

void Cuadrado::setA(int a) {
	this->a = a;
}

void Cuadrado::Dibujar() const {
    ifstream archivoCuadrado("- Cuadrado.txt", ios::in);

    if (!archivoCuadrado) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoCuadrado, line)) {
        line.replace(line.find("XXaXX"), 5, to_string(a));
        line.replace(line.find("XXperimetroXX"), 13,to_string(4 * a));
        line.replace(line.find("XXareaXX"), 8, to_string(a*a));

        cout << line << endl;
    }
}

