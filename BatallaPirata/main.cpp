#include "Juego.h"
#include "Menu.h"
using namespace sf;

int main(int argc, char *argv[]){
	
	Juego batallaNaval(new Menu);
	batallaNaval.jugar();
	
	return 0;
}

