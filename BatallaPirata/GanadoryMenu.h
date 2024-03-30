#ifndef GANADORYMENU_H
#define GANADORYMENU_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class GanadoryMenu : public Escena {
	private:
		Texture fondoImg;
		Sprite fondo;
		RectangleShape opacidad;
		string tipoEvento;
		Font fuente;
		Text ganadorTxt;
		RectangleShape rectanguloGrande;
		RectangleShape rectanguloRevancha;
		Text revanchaTxt;
		RectangleShape rectanguloVolver;
		Text volverTxt;
public:
		GanadoryMenu();
		void actualizar (Juego & ) override;
		void dibujar (RenderWindow & ) override;
		void procesarEvento(Event &) override;
};


#endif
