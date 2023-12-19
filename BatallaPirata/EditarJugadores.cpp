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
#include <string>
#include "Partida.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;
using namespace sf;

EditarJugadores::EditarJugadores(): 
	avatarSeleccionado(1), rectanguloGrande(Vector2f(560.00,440.00)), 
	rectanguloSiguiente(Vector2f(225,75)), rectanguloEntrada(Vector2f(400.00,60.00)),
	rectanguloAvatars(Vector2f(400.00,160.00)), avatars(10)
{
	//	Imprimir Piratas
	for ( int i = 1; i <= 10; i++ ) {
		Texture pirata;
		string nombreArchivo = "pirata" + to_string(i) + ".png";
		if (!pirata.loadFromFile(nombreArchivo)) 
			cout << "No se pudo cargar la imagen" << endl;
		
		piratas.push_back(pirata);
		avatars[i-1].archivo = nombreArchivo;
		avatars[i-1].id = i;
	}
	
	for ( int i = 0; i < 5; i++ ) {
		RectangleShape avatar1(Vector2f(80.00,80.00));
		avatar1.setTexture(&piratas[i]);
		avatar1.setPosition(200 + (80 * i),270);
		if (avatars[i].id == avatarSeleccionado) 
			avatar1.setOutlineThickness(3.f);
		avatar1.setOutlineColor(sf::Color(102, 44, 6));
		avatars[i].avatar = avatar1;
		
		RectangleShape avatar2(Vector2f(80.00,80.00));
		avatar2.setTexture(&piratas[i+5]);
		avatar2.setPosition(200 + (80 * i),350);
		if (avatars[i+5].id == avatarSeleccionado) 
			avatar2.setOutlineThickness(3.f);
		avatar2.setOutlineColor(sf::Color(102, 44, 6));
		avatars[i+5].avatar = avatar2;
	}
	
	//	Fondo
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}

	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	//	Rectangulo Contenedor Grande
	rectanguloGrande.setFillColor(Color(255,193,88));
	rectanguloGrande.setPosition(120,50);
	
	//	Rectangulo Siguiente
	rectanguloSiguiente.setFillColor(Color(255,193,88));
	rectanguloSiguiente.setPosition(560,510);
	
	//	Rectangulo Input
	rectanguloEntrada.setFillColor(Color(255, 207, 127));
	rectanguloEntrada.setPosition(200,145);
	
	//	Rectangulo Avatars
	rectanguloAvatars.setFillColor(Color(255, 207, 127));
	rectanguloAvatars.setPosition(200,270);
	
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	//	Texto Nombre del Jugador
	nombreTxt.setFont(fuente);
	nombreTxt.setCharacterSize(30);
	nombreTxt.setPosition(205,100);
	nombreTxt.setString("Nombre Jugador");
	nombreTxt.setFillColor(Color(102, 44, 6));
	
	//	Texto Elegir Avatar
	avatarTxt.setFont(fuente);
	avatarTxt.setCharacterSize(30);
	avatarTxt.setPosition(205,225);
	avatarTxt.setString("Avatar");
	avatarTxt.setFillColor(Color(102, 44, 6));
	
	//	Texto Boton Siguiente
	siguienteTxt.setFont(fuente);
	siguienteTxt.setCharacterSize(30);
	siguienteTxt.setPosition(602,527);
	siguienteTxt.setString("Siguiente");
	siguienteTxt.setFillColor(Color(102, 44, 6));
	
}

void EditarJugadores::procesarEvento(Event &evento) {
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
	
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Up) {
		cout << "Se apreto la flechita arriba" << endl;
		if (avatarSeleccionado > 5)
			avatarSeleccionado -= 5;
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Down) {
		cout << "Se apreto la flechita abajo" << endl;
		if (avatarSeleccionado < 6)
			avatarSeleccionado += 5;
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Left) {
		cout << "Se apreto la flechita izquierda" << endl;
		if (avatarSeleccionado > 1)
			avatarSeleccionado--;
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Right) {
		cout << "Se apreto la flechita derecha" << endl;
		if (avatarSeleccionado < 10)
			avatarSeleccionado++;
	}
}

void EditarJugadores::actualizar(Juego &juego) {	
	if (
		tipoEvento == "click"
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 560 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 560+225
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 510 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 510+75
	) {
		juego.cambiarEscena(new Partida);
	}
		
	if (tipoEvento == "siguiente") {
		juego.cambiarEscena(new Partida);
	} else if (tipoEvento == "volver") {
		juego.cambiarEscena(new Menu);
	}
	
	for (personaje &avr: avatars) {
		if (avr.id == avatarSeleccionado)
			avr.avatar.setOutlineThickness(3.f);
		else 
			avr.avatar.setOutlineThickness(0.f);
	}	
	
	tipoEvento = "";
}
void EditarJugadores::dibujar(RenderWindow &ventanita) {	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(rectanguloGrande);
	ventanita.draw(rectanguloSiguiente);
	ventanita.draw(rectanguloEntrada);
	ventanita.draw(nombreTxt);
	ventanita.draw(avatarTxt);
	ventanita.draw(siguienteTxt);
	ventanita.draw(rectanguloAvatars);
	
	for ( personaje &avatar: avatars ) 
		ventanita.draw(avatar.avatar);
	
}






