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
#include <SFML/Window/Mouse.hpp>
using namespace std;


GanadoryMenu::GanadoryMenu() {}

void GanadoryMenu::actualizar (Juego &juego ) {

	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		juego.cambiarEscena(new Partida);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) {
		juego.cambiarEscena(new Menu);
	}
	if (
		Mouse::isButtonPressed(Mouse::Button::Left)
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 200+400
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 275 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 275+70
	) {
		cout << "Se hizo click" << endl;
		juego.cambiarEscena(new Partida);
	}
	if (
		Mouse::isButtonPressed(Mouse::Button::Left)
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 200+400
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 360
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 360+70
	) {
		juego.cambiarEscena(new Menu);
	}
}

void GanadoryMenu::dibujar (RenderWindow &ventanita) {	
	Texture fondoImg;
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
//fondo
	Sprite fondo;
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);

//el ganador es
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	Text ganadorTxt;
	ganadorTxt.setFont(fuente);
	ganadorTxt.setCharacterSize(45);
	ganadorTxt.setPosition(245,150);
	ganadorTxt.setString("El ganador es:");
	ganadorTxt.setFillColor(Color(102, 44, 6));
	
	RectangleShape rectanguloGrande(Vector2f(500.00,400.00));
	rectanguloGrande.setFillColor(Color(255,193,88));
	rectanguloGrande.setPosition(150,100);
	
	
//revancha	
	RectangleShape rectanguloRevancha(Vector2f(400.00,70.00));
	rectanguloRevancha.setFillColor(Color(255, 207, 127));
	rectanguloRevancha.setPosition(200,275);
	
	Text revanchaTxt;
	revanchaTxt.setFont(fuente);
	revanchaTxt.setCharacterSize(30);
	revanchaTxt.setPosition(330,290);
	revanchaTxt.setString("revancha");
	revanchaTxt.setFillColor(Color(102, 44, 6));
	
	
// volver al menu
	RectangleShape rectanguloVolver(Vector2f(400.00,70.00));
	rectanguloVolver.setFillColor(Color(255, 207, 127));
	rectanguloVolver.setPosition(200,360);
	
	Text volverTxt;
	volverTxt.setFont(fuente);
	volverTxt.setCharacterSize(30);
	volverTxt.setPosition(300,375);
	volverTxt.setString("volver al menu");
	volverTxt.setFillColor(Color(102, 44, 6));
	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(rectanguloGrande);
	ventanita.draw(ganadorTxt);
	ventanita.draw(rectanguloRevancha);
	ventanita.draw(revanchaTxt);
	ventanita.draw(rectanguloVolver);
	ventanita.draw(volverTxt);
};




	
	
