#include <iostream>
#include <vector>
#include <matrix>
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
        tablero() : tab(16,16,' ') {
            
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
            std::cout << "------------------------------------------------------------------" << endl;
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << tab[i][j] << " |";
                }
                    std::cout << endl;
                    std::cout << "------------------------------------------------------------------" << endl;
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
        ataques() : bombitas(16,16,' ') {}

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
            std::cout << "------------------------------------------------------------------" << endl;
            for (int i = 0; i < 16; i++) {
                for (int j = 0; j < 16; j++) {
                    if (j == 0) std::cout << "|";
                    std::cout << " " << bombitas[i][j] << " |";
                }
                    std::cout << endl;
                    std::cout << "------------------------------------------------------------------" << endl;
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
	
    tablero tb1;
    tablero tb2;
    ataques ataq1;
    ataques ataq2;
    jugador knd = { "Candela", 28, tb1, ataq1};
    jugador ian = { "Ian", 26, tb2, ataq2};


   /* barquito barquito1 = {alto, ancho, xPos, yPos};
    knd.tab.poner_barquito(barquito1);
    knd.tab.mostrar_tablero();

    ian.ataq.AgregarAtaque(2, 6, knd.tab);
    ian.ataq.VerAtaques();
*/

vector<jugador> jugadores ={ian, knd};
for(jugador &jr:jugadores){
		
	jr.tab.poner_barquito({4,1,0,10});
	jr.tab.poner_barquito({6, 1, 2, 8});
	jr.tab.poner_barquito({5, 1, 4, 9});
	jr.tab.poner_barquito({5, 2, 6, 9});
	jr.tab.poner_barquito({3, 1, 9, 11});
	jr.tab.poner_barquito({4, 1, 11, 10});
	jr.tab.mostrar_tablero();
}



	
	return 0;
}


