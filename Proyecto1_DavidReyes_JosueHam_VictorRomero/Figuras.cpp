#include "Figuras.h"
#include "Circulo.h"
#include "Cometa.h"
#include "Cuadrado.h"
#include "Paralelogramo.h"
#include "Rectangulo.h"
#include "Rombo.h"
#include "Trapecio.h"
#include "Triangulo.h"

using namespace std;

void Figuras::Mensaje_FiguraInvalida() {
	ifstream archivoNoParametros("- Parametros_Invalidos.txt", ios::in);

	if (!archivoNoParametros) {
		cerr << "No se pudo abrir el archivo" << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(archivoNoParametros, line)) {
		cout << line << endl;
	}
}

int Figuras::Eleccion_Figuras(int argc, char* argv[]) {
	string figura = argv[1];

	if (figura == "triangulo") {
		switch (argc) {
		case 6: {
			Triangulo triangulo(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
			triangulo.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "paralelogramo") {
		switch (argc) {
		case 5: {
			Paralelogramo paralelogramo(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]));
			paralelogramo.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "rectangulo") {
		switch (argc) {
		case 4: {
			Rectangulo rectangulo(stoi(argv[2]), stoi(argv[3]));
			rectangulo.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "cuadrado") {
		switch (argc) {
		case 3: {
			Cuadrado cuadrado(stoi(argv[2]));
			cuadrado.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "rombo") {
		switch (argc) {
		case 5: {
			Rombo rombo(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]));
			rombo.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "cometa") {
		switch (argc) {
		case 6: {
			Cometa cometa(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
			cometa.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}
	else if (figura == "trapecio") {
		switch (argc) {
		case 7: {
			Trapecio trapecio(stoi(argv[2]), stoi(argv[3]), stoi(argv[4]), stoi(argv[5]), stoi(argv[6]));
			trapecio.Dibujar();
			break;
		}
		default:
			Mensaje_FiguraInvalida();
			break;
		}
	}

	return 0;
}

void Figuras::Main_Figuras(int argc, char* argv[]) {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	if (argc <= 2) {
		Mensaje_FiguraInvalida();
	}
	else {
		Eleccion_Figuras(argc, argv);
	}
}

