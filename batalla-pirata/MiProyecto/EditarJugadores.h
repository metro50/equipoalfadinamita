#ifndef EDITARJUGADORES_H
#define EDITARJUGADORES_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
using namespace sf;

class EditarJugadores: public Escena {
private:
	
public:
	EditarJugadores();
	void actualizar(Juego &) override;
	void dibujar(RenderWindow &) override;
};

#endif
