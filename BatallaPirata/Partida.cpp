#include "Partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "GanadoryMenu.h"
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "EditarJugadores.h"
#include <SFML/Window/Mouse.hpp>
using namespace std;

Partida::Partida() {
}

void Partida::actualizar (Juego & juego) {
	if (
		Keyboard::isKeyPressed(Keyboard::Key::Return)
		|| Mouse::isButtonPressed(Mouse::Button::Left)
	) {
		cout << "Se hizo click o se apreto Enter" << endl;
		juego.cambiarEscena(new GanadoryMenu);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		juego.cambiarEscena(new EditarJugadores);
	}

}

void Partida::dibujar (RenderWindow & ventanita) {
	Texture fondoImg;
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	Sprite fondo;
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	ventanita.clear();
	ventanita.draw(fondo);
	
}

