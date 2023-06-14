#include "Rombo.h"

//Cuerpos de los constructores
Rombo::Rombo() 
	: a(0), d(0), D(0){
}

Rombo::Rombo(int ax, int dx, int DX)
	: a(ax), d(dx), D(DX) {
}

//Cuerpos de los getters
int Rombo::getA() const{
	return a;
}
int Rombo::getd() const{
	return d;
}
int Rombo::getD() const{
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

void Rombo::Dibujar() const {
    ifstream archivoRombo("- Rombo.txt", ios::in);

    if (!archivoRombo) {
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(archivoRombo, line)) {
        line.replace(line.find("XXaXX"), 5, to_string(a));
        line.replace(line.find("XXdXX"), 5, to_string(d));
        line.replace(line.find("XXDXX"), 5, to_string(D));

        line.replace(line.find("XXperimetroXX"), 13, to_string(static_cast < double>(4 * a)));

        line.replace(line.find("XXD*dXX"), 7, to_string(D * d));
        line.replace(line.find("XXareaXX"), 8, to_string(static_cast<double>(D * d)/2.0));


        cout << line << endl;
    }
}