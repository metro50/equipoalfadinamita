#include <iostream>
#include "matrix"
using namespace std;



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
            for (int i = barco.x; i < barco.x + barco.alto; i++) {
                for (int j = barco.y; j < barco.y + barco.ancho; j++) {
                    tab[j][i] = 'X';
                }
            }
        }
        void mostrar_tablero() {
            std::cout << "UBICACIONES DE LOS BARQUITOS:" << endl;
            std::cout << "-----------------------------------------" << endl;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << tab[i][j] << " |";
                }
                    std::cout << endl;
                    std::cout << "-----------------------------------------" << endl;
            }
            std::cout << endl << endl;
        }
        bool hay_barquito_en( int posX, int posY ) {
            return tab[posY][posX] == 'X';
        }
        matrix<char> obtener_tablero() {
            return tab;
        }
        
};


class ataques {
    private:
        matrix<char> bombitas;
    public:
        ataques() : bombitas(10,10,' ') {}

        void AgregarAtaque( int posX, int posY, tablero jugador2 ) {
            matrix<char> tab2 = jugador2.obtener_tablero();

            if ( tab2[posY][posX] == 'X' ) {
                bombitas[posY][posX] = 'A';
            } else {
                bombitas[posY][posX] = 'F';
            }
        }

        void VerAtaques() {
            std::cout << "ATAQUES:" << endl;
            std::cout << "-----------------------------------------" << endl;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << bombitas[i][j] << " |";
                }
                    std::cout << endl;
                    std::cout << "-----------------------------------------" << endl;
            }
            std::cout << endl << endl;
        }
        
};

struct jugador {
    string nombre;
    float id;
    tablero tab;
    ataques ataq;
};

int main() {
	
    int alto = 2, 
        ancho = 3, 
        xPos = 2, 
        yPos = 6;


    tablero tb1;
    tablero tb2;
    ataques ataq1;
    ataques ataq2;
    jugador knd = { "Candela", 28, tb1, ataq1};
    jugador ian = { "Ian", 26, tb2, ataq2};


    barquito barquito1 = {alto, ancho, xPos, yPos};
    knd.tab.poner_barquito(barquito1);
    knd.tab.mostrar_tablero();

    ian.ataq.AgregarAtaque(2, 6, knd.tab);
    ian.ataq.VerAtaques();



	return 0;
}


