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
string Rectangulo::centrar(string input, int width) {
    int spaces = (width - input.length()) / 2;
    string mid = string(spaces, ' ') + input;
    return mid + string((width - mid.length()), ' ');
}
void Rectangulo::Dibujar() {
    ifstream archivoRectangulo("- Rectangulo.txt", ios::in);

    if (!archivoRectangulo) {
        cout << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoRectangulo, line)) {
        line = regex_replace(line, regex("XXaXX"), centrar(to_string(a), 5));
        line = regex_replace(line, regex("XXbXX"), centrar(to_string(b), 5));
        

        line = regex_replace(line, regex("XXareaXX"), centrar(to_string(static_cast<double>(b * a)), 15));
        line = regex_replace(line, regex("\\XXXb\\+aXXX"), centrar(to_string(a + b), 9));
        line = regex_replace(line, regex("XXperimetroXX"), centrar(to_string(static_cast<double>(2 * (a + b))), 17));
        
        cout << line << endl;
    }
}