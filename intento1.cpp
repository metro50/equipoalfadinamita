#include <iostream>
#include "matrix";
using namespace std;

// struct jugador {
//     string nombre;
//     float id;
//     avatar personaje;
//     tablero tab1;
// };

// class avatar {
//     private:
//         string nombre, imagen;
//     public:
//         avatar() {
            
//         }
        
// };

struct barquito {
    int ancho, alto;
    int x, y;
};

class tablero {
    private:
        matrix<char> tab;
    public:
        tablero() : tab(10,10,' ') {
            
        }
        void poner_barquito( barquito barco) {
            for (int i = barco.y; i < barco.y + barco.alto; i++) {
                for (int j = barco.x; j < barco.x + barco.ancho; j++) {
                    tab[i][j] = 'X';
                }
            }
        }
        void mostrar_tablero() {
            std::cout << "-----------------------------------------" << endl;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << tab[i][j] << " |";
                }
                    std::cout << endl;
                    std::cout << "-----------------------------------------" << endl;
            }
            // std::cout << "-----------------------------------------" << endl;
        }
        
};

int main() {
	
    tablero tb1;
    int alto = 2, ancho = 3, xPos = 2, yPos = 6;
    barquito barco1 = {alto, ancho, xPos, yPos};
    tb1.poner_barquito(barco1);
    tb1.mostrar_tablero();

	return 0;
}

