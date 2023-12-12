#include <SFML/Graphics/RectangleShape.hpp>
#include "BotonJugar.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
using namespace sf;

BotonJugar::BotonJugar() {
	RectangleShape rectangulo(Vector2f(400.00,200.00));
	rectangulo.setFillColor(Color(255,193,88));
	
//	ctn_imagen.setTexture(rectangulo);
//	ctn_imagen.setColor(Color(255,193,88));
//	ctn_imagen.setPosition(200,200);
}

Sprite BotonJugar::dibujar() {
	return ctn_imagen;
}
