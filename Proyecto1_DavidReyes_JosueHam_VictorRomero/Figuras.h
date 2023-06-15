#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <regex>
using namespace std;

class Figuras {
public:
	static void Main_Figuras(int argc, char* argv[]);
	static void Mensaje_FiguraInvalida();
	static int Eleccion_Figuras(int argc, char* argv[]);
};
