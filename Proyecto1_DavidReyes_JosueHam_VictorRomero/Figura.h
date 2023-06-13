#ifndef FIGURA_H
#define FIGURA_H

class Figura {
public:
	virtual void formula_Area() = 0;
	virtual void formula_Perimetro() = 0;
	void Dibujar();
	void Area();
	void Perimetro();
};

#endif
