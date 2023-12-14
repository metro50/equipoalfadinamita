#ifndef PARTIDA_H
#define PARTIDA_H
#include "Escena.h"

class Partida : public Escena {
public:
	Partida();
	void actualizar (Juego & )override;
	void dibujar (RenderWindow & )override;
private:
};

#endif

