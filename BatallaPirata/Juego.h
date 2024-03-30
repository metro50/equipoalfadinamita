#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "Escena.h"
#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <SFML/Graphics/Image.hpp>
#include <vector>
#include <SFML/Graphics/RectangleShape.hpp>
#include "tablero.h"
using namespace sf;
using namespace std;

struct personaje {
	int id;
	string archivo;
	RectangleShape avatar;
};

struct jugador {
	string nombre;
	personaje avatar;
//	float id;
//	tablero tab;
//	ataques ataq;
};

class Juego {
	private:
		vector<jugador> jugadores;
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
		void mutearMusica();
		void desmutearMusica();
		void agregarJugador(jugador);
		int cantidadJugadores();
		void resetJugadores();
		vector<jugador> obtenerJugadores();
};

#endif

























