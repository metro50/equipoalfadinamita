#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
using namespace sf;

class Menu: public Escena {
	private:
	
	public:
		Menu();
		void actualizar(Juego &) override;
		void dibujar(RenderWindow &) override;
};

#endif
