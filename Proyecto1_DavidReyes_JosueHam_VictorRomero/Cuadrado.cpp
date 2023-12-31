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

string Cuadrado::centrar(string entrada, int anchura) {
    int espacios = (anchura - entrada.length()) / 2;
    string mitad = string(espacios, ' ') + entrada;
    return mitad + string((anchura - mitad.length()), ' ');
}

void Cuadrado::Dibujar() {
    ifstream archivoCuadrado("- Cuadrado.txt", ios::in);

    if (!archivoCuadrado) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoCuadrado, line)) {
        line = regex_replace(line, regex("XXaXX"), centrar(to_string(a),5));
        line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(4 * a),17));
        line = regex_replace(line, regex("XXareaXX"), centrar(to_string(a * a),15));
        
        cout << line << endl;
    }
}

