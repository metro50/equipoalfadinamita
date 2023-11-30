#include <iostream>
#include <ostream>
#include <vector>
#include "matrix"
using namespace std;

struct barquito {
    int ancho, alto;
    int x, y;
};

class tablero {
    private:
        matrix<char> tab;
    public:
        tablero() : tab(14,14,' ') {}
        void poner_barquito( barquito barco) {
            for (int i = barco.x; i < barco.x + barco.alto; i++) {
                for (int j = barco.y; j < barco.y + barco.ancho; j++) {
                    tab[j][i] = 'X';
                }
            }
        }
        void mostrar_tablero() {
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
        ataques() : bombitas(14,14,' ') {}
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
            std::cout << "---------------------------------------------------------" << endl;
            for (int i = 0; i < 14; i++) {
                for (int j = 0; j < 14; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << bombitas[i][j] << " |";
                }
                std::cout << endl;
                std::cout << "---------------------------------------------------------" << endl;
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

/*int contador(ataques a){
	int cont=0;
	for(int i=0;i<a.size(0);i++){
		for(int j=0;j<a.size(1);j++){
			if (a[i][j]=='A'){
				cont++;
			}
		}
	}
return cont;	
}
	*/

int main() {
	
    tablero tb1, tb2;
    ataques ataq1, ataq2;

    jugador 
        knd = { "Candela", 28, tb1, ataq1}, 
        ian = { "Ian", 26, tb2, ataq2};

    vector<barquito> barquitos = {
        // ALINEADOS VERTICALMENTE (POR DEFECTO)
        {4, 1, 0, 0},      // {4, 1, 0, 10},
        {6, 1, 0, 0},      // {6, 1, 2, 8},
        {5, 1, 0, 0},      // {5, 1, 4, 9},
        {5, 2, 0, 0},      // {5, 2, 6, 9},
        {3, 1, 0, 0},      // {3, 1, 9, 11},
        {4, 1, 0, 0}       // {4, 1, 11, 10}
    };

    vector<jugador> jugadores ={ian, knd};
    for(jugador &jr:jugadores){
        int contBarquitos = 1;
        for ( barquito &barq: barquitos ) {
            
            // Menu fachero
            system("cls");
            std::cout << "TURNO DE " << jr.nombre << endl;
            std::cout << "\nQueres el barquito Nro " << contBarquitos << " en verticar u horizontal?\n" << endl;

            std::cout << "1. Vertical\n\n";
            for (int i = 0; i < barq.alto; i++) 
                for (int i = 0; i < barq.ancho; i++) 
                    std::cout << "\tX" << endl;
            
            std::cout << endl;

            std::cout << "2. Horizontal" << endl;
            std::cout << endl << "       ";
            for (int i = 0; i < barq.ancho; i++) 
                for (int i = 0; i < barq.alto; i++) 
                    std::cout << "X";
            
            
            std::cout << "\n: ";
            // Se ingresa la orientacion del barquito
            int orientacion; cin >> orientacion;
            std::cout << endl << endl;
            system("cls");

            // Cambio de orientacion del barquito: 
            // vertical (default) --> horizontal
            if (orientacion == 2) {
                int aux = barq.alto;
                barq.alto = barq.ancho;
                barq.ancho = aux;
            }

            // Otra cosa del MENU (no tiene relevancia)
            std::cout << "Donde queres ubicar el barquito?\n\n";
            jr.tab.mostrar_tablero();

            // Establece la ubicacion del barquito
            std::cout << "\nFila: ";
            std::cin >> barq.y;

            std::cout << "Columna: ";
            std::cin >> barq.x; std::cout << "\n";

            // Agrega el barquito al jugador
            jr.tab.poner_barquito(barq);
            contBarquitos++;
        }

        system("cls"); // Muestra los tableros de ambos
        for ( jugador jr: jugadores ) {
            std::cout << "Estos son los barquitos de " << jr.nombre << endl;
            jr.tab.mostrar_tablero();
            std::cout << endl;
        }
    }

	return 0;
}


