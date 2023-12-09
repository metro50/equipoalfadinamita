#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Menu.h"
using namespace std;
using namespace sf;

Menu::Menu() {
}
void Menu::actualizar(Juego &jueguito) {
}
void Menu::dibujar(RenderWindow &ventanita) {
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	
}






