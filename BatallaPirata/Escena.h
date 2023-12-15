#ifndef ESCENA_H
#define ESCENA_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
using namespace sf;

class Juego;

class Escena {
	private:
	public:
		virtual void actualizar(Juego &) = 0;
		virtual void dibujar(RenderWindow &) = 0;
};

#endif
