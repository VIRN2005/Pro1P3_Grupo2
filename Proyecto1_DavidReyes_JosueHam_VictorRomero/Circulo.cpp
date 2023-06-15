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

string Circulo::centrar(string input, int width) {
    int spaces = (width - input.length()) / 2;
    string mid = string(spaces, ' ') + input;
    return mid + string((width - mid.length()), ' ');
}

void Circulo::Dibujar() {
    ifstream archivoCirculo("- Circulo.txt", ios::in);

    if (!archivoCirculo) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoCirculo, line)) {
        line = regex_replace(line, regex("XXrXX"), centrar(to_string(r), 5));

        line = regex_replace(line, regex("XXX3.14\\*rXXX"), centrar(to_string(static_cast<double>(3.14 * r)), 12));
        line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(static_cast<double>(2 * 3.14 * r)), 17));

        line = regex_replace(line, regex("XXr\\*rXX"), centrar(to_string(r * r), 7));
        line = regex_replace(line, regex("XXareaXX"), centrar(to_string(3.14 * (r * r)), 15));

        cout << line << endl;
    }
}