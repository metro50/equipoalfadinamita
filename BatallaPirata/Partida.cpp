#include "Partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "GanadoryMenu.h"
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "EditarJugadores.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;

Partida::Partida() {
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
}

void Partida::procesarEvento(Event &evento) {
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Return) {
		cout << "Tocaste ENTER" << endl;	
		tipoEvento = "siguiente";
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape) {
		cout << "Tocaste ESCAPE" << endl;	
		tipoEvento = "volver";
	}
	if (evento.type == Event::MouseButtonPressed && evento.mouseButton.button == Mouse::Left) {
		cout << "Hiciste Click" << endl;
		tipoEvento = "siguiente";
	}
}

void Partida::actualizar (Juego & juego) {
	if (tipoEvento == "siguiente") {
		juego.cambiarEscena(new GanadoryMenu);
	}
	if (tipoEvento == "volver") {
		juego.cambiarEscena(new EditarJugadores);
	}

	tipoEvento = "";
}

void Partida::dibujar (RenderWindow & ventanita) {
	ventanita.clear();
	ventanita.draw(fondo);
}

