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
#include <SFML/Window/Event.hpp>
using namespace std;


GanadoryMenu::GanadoryMenu(): 
	rectanguloGrande(Vector2f(500.00,400.00)), rectanguloRevancha(Vector2f(400.00,70.00)),
	rectanguloVolver(Vector2f(400.00,70.00))

{
	// Fondo
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	// Ganador
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	ganadorTxt.setFont(fuente);
	ganadorTxt.setCharacterSize(45);
	ganadorTxt.setPosition(245,150);
	ganadorTxt.setString("El ganador es:");
	ganadorTxt.setFillColor(Color(102, 44, 6));
	
	rectanguloGrande.setFillColor(Color(255,193,88));
	rectanguloGrande.setPosition(150,100);
	
	// Boton Revancha
	rectanguloRevancha.setFillColor(Color(255, 207, 127));
	rectanguloRevancha.setPosition(200,275);
	
	revanchaTxt.setFont(fuente);
	revanchaTxt.setCharacterSize(30);
	revanchaTxt.setPosition(330,290);
	revanchaTxt.setString("revancha");
	revanchaTxt.setFillColor(Color(102, 44, 6));
	
	
	// Boton Volver al Menu
	rectanguloVolver.setFillColor(Color(255, 207, 127));
	rectanguloVolver.setPosition(200,360);
	
	volverTxt.setFont(fuente);
	volverTxt.setCharacterSize(30);
	volverTxt.setPosition(300,375);
	volverTxt.setString("volver al menu");
	volverTxt.setFillColor(Color(102, 44, 6));
	
}

void GanadoryMenu::procesarEvento(Event &evento) {
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
		tipoEvento = "click";
	}
}

void GanadoryMenu::actualizar (Juego &juego ) {

	if (tipoEvento == "volver") {
		juego.cambiarEscena(new Partida);
	}
	if (tipoEvento == "siguiente") {
		juego.cambiarEscena(new Menu);
	}
	if (
		tipoEvento == "click"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 200+400
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 275 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 275+70
	) {
		juego.cambiarEscena(new Partida);
	}
	if (
		tipoEvento == "click"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 200+400
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 360
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 360+70
	) {
		juego.cambiarEscena(new Menu);
	}
	
	tipoEvento = "";
}

void GanadoryMenu::dibujar (RenderWindow &ventanita) {	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(rectanguloGrande);
	ventanita.draw(ganadorTxt);
	ventanita.draw(rectanguloRevancha);
	ventanita.draw(revanchaTxt);
	ventanita.draw(rectanguloVolver);
	ventanita.draw(volverTxt);
};




	
	
