#include "Juego.h"
#include <SFML/Window/VideoMode.hpp>
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
using namespace sf;

Juego::Juego( Escena *esc ): ventana(VideoMode(800,600), "Batalla Pirata") {
	ventana.setFramerateLimit(60);
	escena_actual = esc;
}
void Juego::jugar() {
	while (ventana.isOpen()) {
		
		Event evento;
		while (ventana.pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				ventana.close();
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






	