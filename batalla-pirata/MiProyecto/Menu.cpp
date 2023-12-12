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

Menu::Menu() {
}
void Menu::actualizar(Juego &jueguito) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		cout << "Se apreto el Espacio" << endl;
		jueguito.cambiarEscena(new EditarJugadores);
	}
}
void Menu::dibujar(RenderWindow &ventanita) {
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}

//	Fondo
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);
	
//	Rectangulo
	RectangleShape rectangulo(Vector2f(300.00,100.00));
	rectangulo.setFillColor(Color(255,193,88));
	rectangulo.setPosition(250,250);
	
//	Texto
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	Text texto;
	texto.setFont(fuente);
	texto.setCharacterSize(60);
	texto.setPosition(305,258);
	texto.setString("JUGAR");
	texto.setColor(Color(102, 44, 6));
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	ventanita.draw(rectangulo);
	ventanita.draw(texto);
//	Pequenio cambio
}






