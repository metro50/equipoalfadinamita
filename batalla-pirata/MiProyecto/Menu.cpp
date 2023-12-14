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
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) {
//		cout << "Se apreto el Enter" << endl;
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
	texto.setCharacterSize(45);
	texto.setPosition(330,267);
	texto.setString("Jugar");
	texto.setFillColor(Color(102, 44, 6));
	
	Text instruccion;
	instruccion.setFont(fuente);
	instruccion.setCharacterSize(25);
	instruccion.setPosition(220,526);
	instruccion.setString("( Presione ENTER para Jugar )");
	instruccion.setFillColor(Color(255,255,255));
	
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	ventanita.draw(rectangulo);
	ventanita.draw(texto);
	ventanita.draw(instruccion);
	
}






