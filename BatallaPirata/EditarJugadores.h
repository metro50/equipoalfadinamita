#ifndef EDITARJUGADORES_H
#define EDITARJUGADORES_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
using namespace std;
using namespace sf;

struct personaje {
	int id;
	string archivo;
};

class EditarJugadores: public Escena {
private:
	int avatarSeleccionado;
	vector<personaje> avatars;
public:
	EditarJugadores();
	void actualizar(Juego &) override;
	void dibujar(RenderWindow &) override;
};

#endif
