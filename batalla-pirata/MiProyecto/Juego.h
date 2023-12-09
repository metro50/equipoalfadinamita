#ifndef JUEGO_H
#define JUEGO_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Juego {
	private:
		RenderWindow ventana;
		Escena *escena_actual;
		Escena *escena_siguiente = nullptr;
	public:
		Juego( Escena *esc );
		void jugar();
		~Juego();
		void cambiarEscena(Escena *nueva_escena);
};

#endif

























