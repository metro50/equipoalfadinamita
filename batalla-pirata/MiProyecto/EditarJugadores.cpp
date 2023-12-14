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
#include <string>
using namespace std;
using namespace sf;

EditarJugadores::EditarJugadores()
: avatarSeleccionado(1) {
	for ( int i = 1; i <= 10; i++ ) {
		string nombreArchivo = "pirata" + to_string(i) + ".png";
		avatars.push_back({i,nombreArchivo});
		cout << "Archivo: " << avatars[i-1].archivo << endl;
		cout << "ID: " << avatars[i-1].id << endl;	
	}
}

void EditarJugadores::actualizar(Juego &jueguito) {	
	
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		cout << "Se apreto la flechita arriba" << endl;
		avatarSeleccionado -= 5;
		cout << avatarSeleccionado << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		cout << "Se apreto la flechita abajo" << endl;
		avatarSeleccionado += 5;
		cout << avatarSeleccionado << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
		cout << "Se apreto la flechita izquierda" << endl;
		avatarSeleccionado--;
		cout << avatarSeleccionado << endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
		cout << "Se apreto la flechita derecha" << endl;
		avatarSeleccionado++;
		cout << avatarSeleccionado << endl;
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
	
	//	Rectangulo Contenedor Grande
	RectangleShape rectgrande(Vector2f(560.00,440.00));
	rectgrande.setFillColor(Color(255,193,88));
	rectgrande.setPosition(120,50);
	
	//	Rectangulo Siguiente
	RectangleShape sig(Vector2f(225,75));
	sig.setFillColor(Color(255,193,88));
	sig.setPosition(560,510);
	
	//	Rectangulo Input
	RectangleShape rectmini(Vector2f(400.00,60.00));
	rectmini.setFillColor(Color(255, 207, 127));
	rectmini.setPosition(200,145);
	
	//	Rectangulo Avatars
	RectangleShape rectAvatar(Vector2f(400.00,160.00));
	rectAvatar.setFillColor(Color(255, 207, 127));
	rectAvatar.setPosition(200,270);
	
	
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	//	Texto Nombre del Jugador
	Text nombre;
	nombre.setFont(fuente);
	nombre.setCharacterSize(30);
	nombre.setPosition(205,100);
	nombre.setString("Nombre Jugador");
	nombre.setFillColor(Color(102, 44, 6));
	
	//	Texto Elegir Avatar
	Text avatar;
	avatar.setFont(fuente);
	avatar.setCharacterSize(30);
	avatar.setPosition(205,225);
	avatar.setString("Avatar");
	avatar.setFillColor(Color(102, 44, 6));
	
	//	Texto Boton Siguiente
	Text siguiente;
	siguiente.setFont(fuente);
	siguiente.setCharacterSize(30);
	siguiente.setPosition(602,527);
	siguiente.setString("Siguiente");
	siguiente.setFillColor(Color(102, 44, 6));
	
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	ventanita.draw(rectgrande);
	ventanita.draw(sig);
	ventanita.draw(rectmini);
	ventanita.draw(nombre);
	ventanita.draw(avatar);
	ventanita.draw(siguiente);
	ventanita.draw(rectAvatar);
	
	//	Evatar Imagen
	for (int i = 0; i < 5; i++) {
		Texture pirata1;
		if (!pirata1.loadFromFile(avatars[i].archivo)) {
			cout << "No se pudo cargar la imagen" << endl;
		}	
		RectangleShape avr1(Vector2f(80.00,80.00));
		avr1.setTexture(&pirata1);
		avr1.setPosition(200 + (80 * i),270);
		if (avatars[i].id == avatarSeleccionado) {
			avr1.setOutlineThickness(3.f);
			avr1.setOutlineColor(sf::Color(102, 44, 6));
		}
		
		Texture pirata2;
		if (!pirata2.loadFromFile(avatars[i+5].archivo)) {
			cout << "No se pudo cargar la imagen" << endl;
		}	
		RectangleShape avr2(Vector2f(80.00,80.00));
		avr2.setTexture(&pirata2);
		avr2.setPosition(200 + (80 * i),350);
		if (avatars[i+5].id == avatarSeleccionado) {
			avr2.setOutlineThickness(3.f);
			avr2.setOutlineColor(sf::Color(102, 44, 6));
		}
		
		ventanita.draw(avr1);
		ventanita.draw(avr2);
	}
	
}






