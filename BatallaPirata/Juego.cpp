#include "Juego.h"
#include <SFML/Window/VideoMode.hpp>
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Juego::Juego( Escena *esc ): ventana(VideoMode(800,600), "Batalla Pirata") {
	ventana.setFramerateLimit(30);
	escena_actual = esc;
	
	if (!icono.loadFromFile("pirata8.png"))
		cout << "No se pudo cargar el icono" << endl;
	
	ventana.setIcon(icono.getSize().x,icono.getSize().y,icono.getPixelsPtr());
	
	if (!musica.openFromFile("cancion.ogg")) 
		cout << "No se pudo cargar el tema" << endl;

	musica.setVolume(0);
	musica.setLoop(true);
	musica.play();
}

RenderWindow& Juego::obtenerVentana() {
	return ventana;
}

void Juego::mutearMusica() {
	musica.setVolume(0);
}

void Juego::desmutearMusica() {
	musica.setVolume(20);
}

void Juego::jugar() {
	while (ventana.isOpen()) {
		
		Event evento;
		while (ventana.pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				ventana.close();
			} else {
				escena_actual->procesarEvento(evento);
			}
		}
		
		escena_actual->actualizar(*this);
		escena_actual->dibujar(ventana);
		ventana.display();
		
		if (escena_siguiente) {
			delete escena_actual;
			escena_actual = escena_siguiente;
			escena_siguiente = nullptr;
		}
	}
}
Juego::~Juego() {
	delete escena_actual;
}
void Juego::cambiarEscena(Escena *nueva_escena) {
	escena_siguiente = nueva_escena;
}
void Juego::agregarJugador(jugador nuevoJugador) {
	jugadores.push_back(nuevoJugador);
}
int Juego::cantidadJugadores() {
	return (int)jugadores.size();
}
vector<jugador> Juego::obtenerJugadores() {
	return jugadores;
}
void Juego::resetJugadores() {
	for (int i = 0; i < 2; i++)
		jugadores.pop_back();
}









	
