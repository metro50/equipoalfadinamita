#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Partida : public Escena {
	private:
		Texture fondoImg;
		Sprite fondo;
		RectangleShape opacidad;
		string tipoEvento;
	public:
		Partida();
		void actualizar (Juego & )override;
		void dibujar (RenderWindow & )override;
		void procesarEvento(Event &) override;
		vector<jugador> jugadores;
};

#endif

