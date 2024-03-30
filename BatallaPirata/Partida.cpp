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
	barquitosSlc(6), ctnBarcos(Vector2f(250.00,350.00)), 
	rectanguloVert(Vector2f(400.00,150.00)), rectanguloHor(Vector2f(400.00,150.00)),
	cuadradoVert(Vector2f(150.00,150.00)), cuadradoHor(Vector2f(150.00,150.00)),
	orientacionElecta(true)
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
	
	rectanguloHor.setPosition(200,150);
	rectanguloHor.setFillColor(Color(113, 204, 242));
	
	rectanguloVert.setPosition(200,325);
	rectanguloVert.setFillColor(Color(113, 204, 242));
	
	cuadradoHor.setPosition(200,150);
	cuadradoHor.setFillColor(Color(62, 162, 201));
	
	cuadradoVert.setPosition(200,325);
	cuadradoVert.setFillColor(Color(62, 162, 201));
	
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	verticalTxt.setFont(fuente);
	verticalTxt.setCharacterSize(30);
	verticalTxt.setPosition(380,205);
	verticalTxt.setString("Vertical");
	verticalTxt.setFillColor(Color(51, 104, 116));
	
	horizontalTxt.setFont(fuente);
	horizontalTxt.setCharacterSize(30);
	horizontalTxt.setPosition(380,380);
	horizontalTxt.setString("Horizontal");
	horizontalTxt.setFillColor(Color(51, 104, 116));
	
	if (orientacionElecta) {
		rectanguloHor.setOutlineColor(sf::Color(113, 204, 242));
		rectanguloHor.setOutlineThickness(10.f);
	} else {
		rectanguloVert.setOutlineColor(sf::Color(113, 204, 242));
		rectanguloVert.setOutlineThickness(10.f);
	}
	tipoEvento = "obtener jugadores";
}

void Partida::procesarEvento(Event &evento) {
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
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Down) {
		cout << "Tocaste ABAJO" << endl;	
		tipoEvento = "abajo";
	}
	if (evento.type == Event::KeyPressed && evento.key.code == Keyboard::Up) {
		cout << "Tocaste ARRIBA" << endl;	
		tipoEvento = "arriba";
	}
	
}

void Partida::actualizar (Juego & juego) {
	if (tipoEvento == "siguiente") {
		if (modal) {
			cout << "seleccionaste el barco Nro " << barcoSeleccionadoId << endl;
			cout << "en posicion " << (orientacionElecta ? "vertical" : "horizontal") << endl;
			modal = false;
		} else 
			juego.cambiarEscena(new GanadoryMenu);
	}
	if (tipoEvento == "volver") {
		if (modal) {
			modal = false;
			opcionesBarco.resize(0);
		} else 
			juego.cambiarEscena(new EditarJugadores);
	}
	if (tipoEvento == "click") {
		if (
			modal
			&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 600
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 150 
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 300
		) {
			cout << "seleccionaste el barco Nro " << barcoSeleccionadoId << endl;
			cout << "en posicion " << (orientacionElecta ? "vertical" : "horizontal") << endl;
			modal = false;
		} else if (
			modal
			&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 600
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 325 
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 475
		) {
			cout << "seleccionaste el barco Nro " << barcoSeleccionadoId << endl;
			cout << "en posicion " << (orientacionElecta ? "vertical" : "horizontal") << endl;
			modal = false;
		}
		if (
			Mouse::getPosition(juego.obtenerVentana()).x >= 590 
			&& Mouse::getPosition(juego.obtenerVentana()).x <= 590+100
			&& Mouse::getPosition(juego.obtenerVentana()).y >= 30 
			&& Mouse::getPosition(juego.obtenerVentana()).y <= 30+40
		) {
			cout << "Seleccionaste el barco Nro 1" << endl;
			barcoSeleccionadoId = 1;
			if (!barcoSeleccionado.loadFromFile("barco0.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(100.00,40.00));
			barcoVer.setPosition(240+55,150+25);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(100.00,40.00));
			barcoHor.setPosition(200+25,325+55);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
			barcoSeleccionadoId = 2;
			if (!barcoSeleccionado.loadFromFile("barco1.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(140.00,20.00));
			barcoVer.setPosition(220+65,130+20);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(140.00,20.00));
			barcoHor.setPosition(180+20,325+65);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
			barcoSeleccionadoId = 3;
			if (!barcoSeleccionado.loadFromFile("barco2.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(100.00,20.00));
			barcoVer.setPosition(220+65,150+25);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(100.00,20.00));
			barcoHor.setPosition(200+25,325+65);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
			barcoSeleccionadoId = 4;
			if (!barcoSeleccionado.loadFromFile("barco3.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(80.00,20.00));
			barcoVer.setPosition(225+65,150+35);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(80.00,20.00));
			barcoHor.setPosition(205+35,325+65);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
			barcoSeleccionadoId = 5;
			if (!barcoSeleccionado.loadFromFile("barco4.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(80.00,20.00));
			barcoVer.setPosition(220+65,150+35);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(80.00,20.00));
			barcoHor.setPosition(200+35,325+65);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
			barcoSeleccionadoId = 6;
			if (!barcoSeleccionado.loadFromFile("barco5.png")) {
				cout << "No se pudo cargar la imagen" << endl;
			}
			RectangleShape barcoVer(Vector2f(60.00,20.00));
			barcoVer.setPosition(220+65,150+45);
			barcoVer.setTexture(&barcoSeleccionado);
			//barcoVer.setScale(2,2);
			barcoVer.setRotation(90);
			
			RectangleShape barcoHor(Vector2f(60.00,20.00));
			barcoHor.setPosition(200+45,325+65);
			barcoHor.setTexture(&barcoSeleccionado);
			//barcoHor.setScale(2,2);
			
			opcionesBarco.resize(0);
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
	
	if (
		modal
		&& Mouse::getPosition(juego.obtenerVentana()).x >= 200 
		&& Mouse::getPosition(juego.obtenerVentana()).x <= 600
		&& Mouse::getPosition(juego.obtenerVentana()).y >= 150 
		&& Mouse::getPosition(juego.obtenerVentana()).y <= 300
	) {
		rectanguloHor.setFillColor(Color(62, 162, 201));
		rectanguloVert.setFillColor(Color(113, 204, 242));
	} else if (
	   modal
	   && Mouse::getPosition(juego.obtenerVentana()).x >= 200 
	   && Mouse::getPosition(juego.obtenerVentana()).x <= 600
	   && Mouse::getPosition(juego.obtenerVentana()).y >= 325 
	   && Mouse::getPosition(juego.obtenerVentana()).y <= 475
    ) {
		rectanguloVert.setFillColor(Color(62, 162, 201));
		rectanguloHor.setFillColor(Color(113, 204, 242));
	} else {
	   rectanguloHor.setFillColor(Color(113, 204, 242));
	   rectanguloVert.setFillColor(Color(113, 204, 242));
	}
	
	if (modal && (tipoEvento == "arriba" || tipoEvento == "abajo")) 
		orientacionElecta = !orientacionElecta;
	
	if (orientacionElecta) {
		rectanguloHor.setOutlineColor(sf::Color(113, 204, 242));
		rectanguloHor.setOutlineThickness(10.f);
		rectanguloVert.setOutlineThickness(0.f);
	} else {
		rectanguloVert.setOutlineColor(sf::Color(113, 204, 242));
		rectanguloVert.setOutlineThickness(10.f);
		rectanguloHor.setOutlineThickness(0.f);
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
	if (modal) {
		ventanita.draw(fondoModal);
		ventanita.draw(rectanguloVert);
		ventanita.draw(rectanguloHor);
		ventanita.draw(cuadradoHor);
		ventanita.draw(cuadradoVert);
		ventanita.draw(verticalTxt);
		ventanita.draw(horizontalTxt);
		for (RectangleShape &opt: opcionesBarco)
			ventanita.draw(opt);		
	}	
}

