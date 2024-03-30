#ifndef TABLERO_H
#define TABLERO_H
#include "matrix"
#include <string>
using namespace std;

struct barquito {
	string id;
	int ancho, alto;
	int x, y;
};

class tablero {
private:
	matrix<char> tab;
public:
	tablero();
	void poner_barquito( barquito barco);
	bool se_puede_poner(barquito barco);
	void mostrar_tablero();
	bool hay_barquito_en( int posX, int posY );
	matrix<char> obtener_tablero();
};

#endif
