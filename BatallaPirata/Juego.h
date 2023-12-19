#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <SFML/Graphics/Image.hpp>
using namespace sf;
using namespace std;

class Juego {
	private:
		RenderWindow ventana;
		Music musica;
		Image icono;
		Escena *escena_actual;
		Escena *escena_siguiente = nullptr;
	public:
		Juego( Escena *esc );
		void jugar();
		~Juego();
		RenderWindow& obtenerVentana();
		void cambiarEscena(Escena *nueva_escena);
};

#endif

























