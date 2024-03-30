#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Partida : public Escena {
	private:
		Texture fondoImg;
		Texture gradient;
		Sprite fondo;
		Sprite degrade;
		string tipoEvento;
		RectangleShape ctnBarcos;
		vector<Texture> imgBarquitos;
		vector<RectangleShape> barquitosSlc;
		bool modal;
		RectangleShape fondoModal;
		Texture barcoSeleccionado;
		int barcoSeleccionadoId;
		vector<RectangleShape> opcionesBarco;
		string orientacionBarco;
		RectangleShape rectanguloVert;
		RectangleShape cuadradoVert;
		RectangleShape rectanguloHor;
		RectangleShape cuadradoHor;
		bool orientacionElecta;
		Font fuente;
		Text verticalTxt;
		Text horizontalTxt;
	public:
		Partida();
		void actualizar (Juego & )override;
		void dibujar (RenderWindow & )override;
		void procesarEvento(Event &) override;
		vector<jugador> jugadores;
};

#endif

