#include "Partida.h"
#include <SFML/Window/Keyboard.hpp>
#include "GanadoryMenu.h"
#include "Juego.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "EditarJugadores.h"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Event.hpp>
using namespace std;

Partida::Partida():
	imgBarquitos(6), fondoModal(Vector2f(800.00,600.00)), modal(false),
	barquitosSlc(6), ctnBarcos(Vector2f(250.00,350.00))
{
	if (!fondoImg.loadFromFile("fondo1.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	fondo.setTexture(fondoImg);
	fondo.setPosition(0,-100);
	fondo.setScale(0.8,0.7);

	if (!gradient.loadFromFile("gradient.png")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	degrade.setTexture(gradient);
	degrade.setPosition(0,0);
		
	ctnBarcos.setPosition(500,20);
	ctnBarcos.setFillColor(Color(0, 0, 0, 90));
	
	for (int i = 1; i <= 6; i++) {
		if (!imgBarquitos[i-1].loadFromFile("barco" + to_string(i-1) + ".png")) {
			cout << "No se pudo cargar la imagen" << endl;
		}
	}	
	
	for (int i = 0; i < 6; i++) {
		if (i == 0) {
			barquitosSlc[i].setPosition(550 + 20 * 2, i * 50 + 30 );	
			barquitosSlc[i].setSize(Vector2f(100,40));
		} else if (i == 1) {
			barquitosSlc[i].setPosition(550, i * 50 + 50 );
			barquitosSlc[i].setSize(Vector2f(140,20));
		} else if (i == 2) {
			barquitosSlc[i].setPosition(550 + 20 * 2, i * 50 + 50 );
			barquitosSlc[i].setSize(Vector2f(100,20)); 
		} else if (i == 5) {
			barquitosSlc[i].setPosition(550 + 20 * 4, i * 50 + 50 );
			barquitosSlc[i].setSize(Vector2f(60,20));
		} else {
			barquitosSlc[i].setPosition(550 + 20 * 3, i * 50 + 50 );
			barquitosSlc[i].setSize(Vector2f(80,20));
		}
		
		barquitosSlc[i].setTexture(&imgBarquitos[i]);
		barquitosSlc[i].setScale(1.5,1.5);
	}
	
	fondoModal.setPosition(0,0);
	fondoModal.setFillColor(Color(0,0,0,150));
	
	tipoEvento = "obtener jugadores";
}

void Partida::procesarEvento(Event &evento) {
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Return) {
		cout << "Tocaste ENTER" << endl;	
		tipoEvento = "siguiente";
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Escape) {
		cout << "Tocaste ESCAPE" << endl;	
//		tipoEvento = "volver";
	}
	if (evento.type == Event::MouseButtonPressed && evento.mouseButton.button == Mouse::Left) {
		cout << "Hiciste Click" << endl;
		tipoEvento = "click";
	}
	
}

void Partida::actualizar (Juego & juego) {
	if (tipoEvento == "siguiente") {
		juego.cambiarEscena(new GanadoryMenu);
	}
	if (tipoEvento == "volver") {
		juego.cambiarEscena(new EditarJugadores);
	}
	if (tipoEvento == "click") {
		if (
			Mouse::getPosition(juego.obtenerVentana()).x >= 590 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 590+100
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 30 
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 30+40
		) {
			cout << "Seleccionaste el barco Nro 1" << endl;
			if (!barcoSeleccionado.loadFromFile("barco0.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(100.00,40.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(100.00,40.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			
			modal = true;
		} else if (
			Mouse::getPosition(juego.obtenerVentana()).x >= 550 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 550+140
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 100 
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 100+20
		) {
			cout << "Seleccionaste el barco Nro 2" << endl;
			if (!barcoSeleccionado.loadFromFile("barco1.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(140.00,20.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(140.00,20.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			modal = true;
		} else if (
		    Mouse::getPosition(juego.obtenerVentana()).x >= 590 
		    && Mouse::getPosition(juego.obtenerVentana()).x <= 590+100
		    && Mouse::getPosition(juego.obtenerVentana()).y >= 150 
		    && Mouse::getPosition(juego.obtenerVentana()).y <= 150+20
		) {
			cout << "Seleccionaste el barco Nro 3" << endl;
			if (!barcoSeleccionado.loadFromFile("barco2.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(100.00,20.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(100.00,20.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			modal = true;
		} else if (
		    Mouse::getPosition(juego.obtenerVentana()).x >= 610
		    && Mouse::getPosition(juego.obtenerVentana()).x <= 610+80
		    && Mouse::getPosition(juego.obtenerVentana()).y >= 200 
		    && Mouse::getPosition(juego.obtenerVentana()).y <= 200+20
		) {
			cout << "Seleccionaste el barco Nro 4" << endl;
			if (!barcoSeleccionado.loadFromFile("barco3.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(80.00,20.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(80.00,20.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			
			modal = true;
	    } else if (
			Mouse::getPosition(juego.obtenerVentana()).x >= 610 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 610+80
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 250
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 250+20
		) {
			cout << "Seleccionaste el barco Nro 5" << endl;
			if (!barcoSeleccionado.loadFromFile("barco4.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(80.00,20.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(80.00,20.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			
			modal = true;
		} else if (
			Mouse::getPosition(juego.obtenerVentana()).x >= 630
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 630+60
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 300
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 300+20
		) {
			cout << "Seleccionaste el barco Nro 6" << endl;
			if (!barcoSeleccionado.loadFromFile("barco5.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(60.00,20.00));
			barcoVer.setPosition(250,300);
			barcoVer.setTexture(&barcoSeleccionado);
			barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(60.00,20.00));
			barcoHor.setPosition(500,300);
			barcoHor.setTexture(&barcoSeleccionado);
			barcoHor.setScale(2,2);
			
			opcionesBarco.push_back(barcoVer);
			opcionesBarco.push_back(barcoHor);
			
			modal = true;
		}
	}
	if (tipoEvento == "obtener jugadores") {
		cout << juego.obtenerJugadores()[0].nombre << endl;
		cout << juego.obtenerJugadores()[1].nombre << endl;
		jugadores = juego.obtenerJugadores();
		
		jugadores[0].avatar.avatar.setPosition(790,365);
		jugadores[0].avatar.avatar.setOutlineThickness(0.f);
		jugadores[0].avatar.avatar.setScale(-3,3);
		
		jugadores[1].avatar.avatar.setPosition(0,480);
		jugadores[1].avatar.avatar.setOutlineThickness(0.f);
		jugadores[1].avatar.avatar.setScale(1.5,1.5);
		
		
		tipoEvento == "";
	}

	tipoEvento = "";
}

void Partida::dibujar (RenderWindow & ventanita) {
	ventanita.clear();
	ventanita.draw(fondo);
	ventanita.draw(degrade);
	ventanita.draw(jugadores[0].avatar.avatar);
	ventanita.draw(jugadores[1].avatar.avatar);
	for (RectangleShape &brq: barquitosSlc) 
		ventanita.draw(brq);
	if (modal)
		ventanita.draw(fondoModal);
	for (RectangleShape &opt: opcionesBarco)
		ventanita.draw(opt);
}

