#include "Cuadrado.h"
#include <fstream>
#include <regex>

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
        line = regex_replace(line, regex("XXaXX"), to_string(a));
        line = regex_replace(line, regex("XXperimetroXX"), to_string(4 * a));
        line = regex_replace(line, regex("XXareaXX"), to_string(a * a));
        
        cout << line << endl;
    }
}

