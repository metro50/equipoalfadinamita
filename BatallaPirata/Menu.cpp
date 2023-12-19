#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Menu.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EditarJugadores.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;

Menu::Menu(): 
	rectangulo(Vector2f(300.00,100.00)), cuadroVolumen(Vector2f(50.00,50.00)),
	volumen(Vector2f(30.00,30.00)), musica(true)
{
	
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	//	Fondo
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	//	Rectangulo
	rectangulo.setFillColor(Color(255,193,88));
	rectangulo.setPosition(250,250);
	
	//	Texto Boton
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	texto.setFont(fuente);
	texto.setCharacterSize(45);
	texto.setPosition(330,267);
	texto.setString("Jugar");
	texto.setFillColor(Color(102, 44, 6));
	
	//	Instrucciones
	instruccion.setFont(fuente);
	instruccion.setCharacterSize(25);
	instruccion.setPosition(220,526);
	instruccion.setString("( Presione ENTER para Jugar )");
	instruccion.setFillColor(Color(255,255,255));
	
	//	Volumen
	cuadroVolumen.setFillColor(Color(255,193,88));
	cuadroVolumen.setPosition(730,530);
	
	
	if (!volumenImg.loadFromFile("volumenon.png")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	volumen.setTexture(&volumenImg);
	volumen.setPosition(740,540);
	
}
void Menu::procesarEvento(Event &evento) {
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Return) {
		cout << "Tocaste ENTER" << endl;	
		tipoEvento = "siguiente";
	}
	if (evento.type == Event::MouseButtonPressed && evento.mouseButton.button == Mouse::Left) {
		cout << "Hiciste Click" << endl;
		tipoEvento = "click";
	}
}
void Menu::actualizar(Juego &juego) {
	if (tipoEvento == "siguiente") {
		juego.cambiarEscena(new EditarJugadores);
	}
	if (
		tipoEvento == "click"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 250 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 250+300
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 250 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 250+100
	) {
		juego.cambiarEscena(new EditarJugadores);
	}
	
	if (
		tipoEvento == "click"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 730 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 730+50
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 530 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 530+50
	) {
		if (musica) {
			if (!volumenImg.loadFromFile("volumenoff.png")) 
				cout << "No se pudo cargar la imagen" << endl;
			juego.mutearMusica();
			musica = !musica;
		} else {
			if (!volumenImg.loadFromFile("volumenon.png")) 
				cout << "No se pudo cargar la imagen" << endl;
			juego.desmutearMusica();
			musica = !musica;
		}
	}
	
	tipoEvento = "";
}
void Menu::dibujar(RenderWindow &ventanita) {	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(rectangulo);
	ventanita.draw(texto);
	ventanita.draw(instruccion);
	ventanita.draw(cuadroVolumen);
	ventanita.draw(volumen);
}






