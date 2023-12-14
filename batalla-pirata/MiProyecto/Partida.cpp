#include "Partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "GanadoryMenu.h"
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
using namespace std;

Partida::Partida() {
}

void Partida::actualizar (Juego & jueguito) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) {
		jueguito.cambiarEscena(new GanadoryMenu);
	}

}

void Partida::dibujar (RenderWindow & ventanita) {
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	
}

