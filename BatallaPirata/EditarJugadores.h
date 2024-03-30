#ifndef EDITARJUGADORES_H
#define EDITARJUGADORES_H
#include "Escena.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
using namespace std;
using namespace sf;

//struct personaje {
//	int id;
//	string archivo;
//	RectangleShape avatar;
//};

class EditarJugadores: public Escena {
private:
	int avatarSeleccionado;
	string tipoEvento;
	vector<personaje> avatars;
	vector<Texture> piratas;
	Texture fondoImg;
	Sprite fondo;
	RectangleShape opacidad;
	Font fuente;
	RectangleShape rectanguloGrande;
	RectangleShape rectanguloSiguiente;
	Text siguienteTxt;
	RectangleShape rectanguloEntrada;
	Text nombreTxt;
	Text nombreJugador;
	RectangleShape rectanguloAvatars;
	Text avatarTxt;
public:
	EditarJugadores();
	void actualizar(Juego &) override;
	void dibujar(RenderWindow &) override;
	void procesarEvento(Event &) override;
};

#endif
