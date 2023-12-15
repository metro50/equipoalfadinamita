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
using namespace std;
using namespace sf;

EditarJugadores::EditarJugadores()
: avatarSeleccionado(1) {
	for ( int i = 1; i <= 10; i++ ) {
		string nombreArchivo = "pirata" + to_string(i) + ".png";
		avatars.push_back({i,nombreArchivo});
	}
}

void EditarJugadores::actualizar(Juego &juego) {	
	if (
		Mouse::isButtonPressed(Mouse::Button::Left)
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 560 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 560+225
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 510 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 510+75
	) {
		cout << "Se hizo click" << endl;
		juego.cambiarEscena(new Partida);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Return)) {
		juego.cambiarEscena(new Partida);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
		juego.cambiarEscena(new Menu);
	}
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		cout << "Se apreto la flechita arriba" << endl;
		if (avatarSeleccionado > 5)
			avatarSeleccionado -= 5;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		cout << "Se apreto la flechita abajo" << endl;
		if (avatarSeleccionado < 6)
			avatarSeleccionado += 5;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		cout << "Se apreto la flechita izquierda" << endl;
		if (avatarSeleccionado > 1)
			avatarSeleccionado--;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		cout << "Se apreto la flechita derecha" << endl;
		if (avatarSeleccionado < 10)
			avatarSeleccionado++;
	}

}
void EditarJugadores::dibujar(RenderWindow &ventanita) {
	Texture fondoImg;
	if (!fondoImg.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	//	Fondo
	Sprite fondo;
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);
	
	//	Rectangulo Contenedor Grande
	RectangleShape rectanguloGrande(Vector2f(560.00,440.00));
	rectanguloGrande.setFillColor(Color(255,193,88));
	rectanguloGrande.setPosition(120,50);
	
	//	Rectangulo Siguiente
	RectangleShape rectanguloSiguiente(Vector2f(225,75));
	rectanguloSiguiente.setFillColor(Color(255,193,88));
	rectanguloSiguiente.setPosition(560,510);
	
	//	Rectangulo Input
	RectangleShape rectanguloEntrada(Vector2f(400.00,60.00));
	rectanguloEntrada.setFillColor(Color(255, 207, 127));
	rectanguloEntrada.setPosition(200,145);
	
	//	Rectangulo Avatars
	RectangleShape rectanguloAvatars(Vector2f(400.00,160.00));
	rectanguloAvatars.setFillColor(Color(255, 207, 127));
	rectanguloAvatars.setPosition(200,270);
	
	
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	//	Texto Nombre del Jugador
	Text nombreTxt;
	nombreTxt.setFont(fuente);
	nombreTxt.setCharacterSize(30);
	nombreTxt.setPosition(205,100);
	nombreTxt.setString("Nombre Jugador");
	nombreTxt.setFillColor(Color(102, 44, 6));
	
	//	Texto Elegir Avatar
	Text avatarTxt;
	avatarTxt.setFont(fuente);
	avatarTxt.setCharacterSize(30);
	avatarTxt.setPosition(205,225);
	avatarTxt.setString("Avatar");
	avatarTxt.setFillColor(Color(102, 44, 6));
	
	//	Texto Boton Siguiente
	Text siguienteTxt;
	siguienteTxt.setFont(fuente);
	siguienteTxt.setCharacterSize(30);
	siguienteTxt.setPosition(602,527);
	siguienteTxt.setString("Siguiente");
	siguienteTxt.setFillColor(Color(102, 44, 6));
	
	
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(rectanguloGrande);
	ventanita.draw(rectanguloSiguiente);
	ventanita.draw(rectanguloEntrada);
	ventanita.draw(nombreTxt);
	ventanita.draw(avatarTxt);
	ventanita.draw(siguienteTxt);
	ventanita.draw(rectanguloAvatars);
	
	//	Evatar Imagen
	for (int i = 0; i < 5; i++) {
		Texture pirata1;
		if (!pirata1.loadFromFile(avatars[i].archivo)) {
			cout << "No se pudo cargar la imagen" << endl;
		}	
		RectangleShape avatar1(Vector2f(80.00,80.00));
		avatar1.setTexture(&pirata1);
		avatar1.setPosition(200 + (80 * i),270);
		if (avatars[i].id == avatarSeleccionado) {
			avatar1.setOutlineThickness(3.f);
			avatar1.setOutlineColor(sf::Color(102, 44, 6));
		}
		
		Texture pirata2;
		if (!pirata2.loadFromFile(avatars[i+5].archivo)) {
			cout << "No se pudo cargar la imagen" << endl;
		}	
		RectangleShape avatar2(Vector2f(80.00,80.00));
		avatar2.setTexture(&pirata2);
		avatar2.setPosition(200 + (80 * i),350);
		if (avatars[i+5].id == avatarSeleccionado) {
			avatar2.setOutlineThickness(3.f);
			avatar2.setOutlineColor(sf::Color(102, 44, 6));
		}
		
		ventanita.draw(avatar1);
		ventanita.draw(avatar2);
	}
	
}






