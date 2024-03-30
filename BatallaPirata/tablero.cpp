#include "tablero.h"
#include <iostream>
tablero::tablero() : tab(14,14,' ') {}

void tablero::poner_barquito( barquito barco) {
	for (int i = barco.x; i < barco.x + barco.alto; i++) {
		for (int j = barco.y; j < barco.y + barco.ancho; j++) {
			tab[j][i] = 'X';
		}
	}
}

bool tablero::se_puede_poner(barquito barco) {
	for (int i = barco.x; i < barco.x + barco.alto; i++) {
		for (int j = barco.y; j < barco.y + barco.ancho; j++) {
			if(tab[j][i]=='X'){
				return false;
			}
		}
	}
	return true;
}

void tablero::mostrar_tablero() {
	std::cout << "UBICACIONES DE LOS BARQUITOS:" << endl;
	std::cout << "---------------------------------------------------------" << endl;
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			if (j == 0) std::cout << "|";
			std::cout << " " << tab[i][j] << " |";
		}
		std::cout << endl;
		std::cout << "---------------------------------------------------------" << endl;
	}
	std::cout << endl << endl;
}

bool tablero::hay_barquito_en( int posX, int posY ) {
	return tab[posY][posX] == 'X';
}

matrix<char> tablero::obtener_tablero() {
	return tab;
}
