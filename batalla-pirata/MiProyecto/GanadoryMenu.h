#ifndef GANADORYMENU_H
#define GANADORYMENU_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"

class GanadoryMenu : public Escena {
public:
	GanadoryMenu();
	void actualizar (Juego & ) override;
	void dibujar (RenderWindow & ) override;
private:
};


#endif
