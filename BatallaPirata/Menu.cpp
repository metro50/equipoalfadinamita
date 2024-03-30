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
	volumen(Vector2f(30.00,30.00)), musica(true), opacidad(Vector2f(800.00,600.00))
{
	
	if (!fondoImg.loadFromFile("fondo1.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	//	Fondo
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	//	Opacidad del fondo
	opacidad.setPosition(0,0);
	opacidad.setFillColor(Color(0,0,0,50));
	
	
	//	Rectangulo
	rectangulo.setFillColor(Color(185,234,255));
	rectangulo.setPosition(250,250);
	
	//	Texto Boton
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	texto.setFont(fuente);
	texto.setCharacterSize(45);
	texto.setPosition(330,267);
	texto.setString("Jugar");
	texto.setFillColor(Color(51, 104, 116));
	
	//	Instrucciones
	instruccion.setFont(fuente);
	instruccion.setCharacterSize(25);
	instruccion.setPosition(220,526);
	instruccion.setString("( Presione ENTER para Jugar )");
	instruccion.setFillColor(Color(255,255,255));
	instruccion.setOutlineColor(Color(0,0,0,128));
	instruccion.setOutlineThickness(4);
	
	//	Volumen
	cuadroVolumen.setFillColor(Color( 185, 234, 255));
	cuadroVolumen.setPosition(730,530);
	
	
	if (!volumenImg.loadFromFile("volumen-on.png")) {
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
	if (evento.type == Event::MouseMoved) {
		tipoEvento = "mouse";
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
			if (!volumenImg.loadFromFile("volumen-off.png")) 
				cout << "No se pudo cargar la imagen" << endl;
			juego.mutearMusica();
			musica = !musica;
		} else {
			if (!volumenImg.loadFromFile("volumen-on.png")) 
				cout << "No se pudo cargar la imagen" << endl;
			juego.desmutearMusica();
			musica = !musica;
		}
	}
		
	if (
		tipoEvento == "mouse"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 250 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 250+300
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 250 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 250+100
	) {
		rectangulo.setFillColor(Color(113, 204, 242));
	} else if (tipoEvento == "mouse") {
		rectangulo.setFillColor(Color(185,234,255));
	}
	
	if (
		tipoEvento == "mouse"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 730 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 730+50
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 530 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 530+50
	) {
		cuadroVolumen.setFillColor(Color(113, 204, 242));
	} else if (tipoEvento == "mouse") {
		cuadroVolumen.setFillColor(Color(185,234,255));
	}
	
	tipoEvento = "";
}
void Menu::dibujar(RenderWindow &ventanita) {	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(opacidad);
	ventanita.draw(rectangulo);
	ventanita.draw(texto);
	ventanita.draw(instruccion);
	ventanita.draw(cuadroVolumen);
	ventanita.draw(volumen);
}






