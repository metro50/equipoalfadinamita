#ifndef MENU_H
#define MENU_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace sf;

class Menu: public Escena {
	private:
		Texture fondoImg;
		Sprite fondo;
		string tipoEvento;
		RectangleShape rectangulo;
		Font fuente;
		Text instruccion;
		Text texto;
		RectangleShape cuadroVolumen;
		Texture volumenImg;
		RectangleShape volumen;
		RectangleShape opacidad;
		bool musica;
	public:
		Menu();
		void actualizar(Juego &) override;
		void dibujar(RenderWindow &) override;
		void procesarEvento(Event &) override;
};

#endif
