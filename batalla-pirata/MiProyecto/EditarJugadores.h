#ifndef EDITARJUGADORES_H
#define EDITARJUGADORES_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
using namespace std;
using namespace sf;

struct personita {
	int id;
	string archivo;
};

class EditarJugadores: public Escena {
private:
	int avatarSeleccionado;
	vector<personita> avatars;
public:
	EditarJugadores();
	void actualizar(Juego &) override;
	void dibujar(RenderWindow &) override;
};

#endif
