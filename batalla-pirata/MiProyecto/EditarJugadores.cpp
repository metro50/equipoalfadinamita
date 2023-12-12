#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Menu.h"
#include "BotonJugar.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EditarJugadores.h"
using namespace std;
using namespace sf;

EditarJugadores::EditarJugadores() {
}
void EditarJugadores::actualizar(Juego &jueguito) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		cout << "Se apreto el Espacio" << endl;
	}
}
void EditarJugadores::dibujar(RenderWindow &ventanita) {
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	//	Fondo
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
}






