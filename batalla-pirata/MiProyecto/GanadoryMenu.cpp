#include "GanadoryMenu.h"
#include <iomanip>
#include <SFML/Window/Keyboard.hpp>
#include "Menu.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Juego.h"
#include "Escena.h"
#include "Partida.h"
using namespace std;


GanadoryMenu::GanadoryMenu() {
}

void GanadoryMenu::actualizar (Juego &jueguito ) {
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		jueguito.cambiarEscena(new Partida);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		jueguito.cambiarEscena(new Menu);
	}
	
}

void GanadoryMenu::dibujar (RenderWindow &ventanita) {	
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
//fondo
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);

//el ganador es
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	Text fin;
	fin.setFont(fuente);
	fin.setCharacterSize(45);
	fin.setPosition(205,100);
	fin.setString("El ganador es:");
	fin.setFillColor(Color(102, 44, 6));
	
	RectangleShape rectg(Vector2f(500.00,400.00));
	rectg.setFillColor(Color(255,193,88));
	rectg.setPosition(120,50);
	
	
//revancha	
	RectangleShape rev(Vector2f(400.00,70.00));
	rev.setFillColor(Color(255, 207, 127));
	rev.setPosition(200,270);
	
	Text r;
	r.setFont(fuente);
	r.setCharacterSize(30);
	r.setPosition(205,270);
	r.setString("revancha");
	r.setFillColor(Color(102, 44, 6));
	
	
// volver al menu
	RectangleShape volver(Vector2f(400.00,70.00));
	volver.setFillColor(Color(255, 207, 127));
	volver.setPosition(250,350);
	
	Text v;
	v.setFont(fuente);
	v.setCharacterSize(30);
	v.setPosition(205,270);
	v.setString("volver al menu");
	v.setFillColor(Color(102, 44, 6));
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	ventanita.draw(rectg);
	ventanita.draw(fin);
	ventanita.draw(rev);
	ventanita.draw(r);
	ventanita.draw(volver);
	ventanita.draw(v);
};




	
	
