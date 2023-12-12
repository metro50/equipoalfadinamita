#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Juego.h"
#include "Menu.h"
#include "BotonJugar.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "EditarJugadores.h"
using namespace std;
using namespace sf;

EditarJugadores::EditarJugadores() {
}
void EditarJugadores::actualizar(Juego &jueguito) {
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		cout << "Se apreto el Espacio" << endl;
	}
}
void EditarJugadores::dibujar(RenderWindow &ventanita) {
	Texture fondo;
	if (!fondo.loadFromFile("fondo.jpg")) {
		cout << "No se pudo cargar la imagen" << endl;
	}
	
	//	Fondo
	Sprite ctnFondo;
	ctnFondo.setTexture(fondo);
	ctnFondo.setPosition(0,-100);
	ctnFondo.setScale(0.8,0.7);
	
	
	RectangleShape rectgrande(Vector2f(700.00,450.00));
	rectgrande.setFillColor(Color(255,193,88));
	rectgrande.setPosition(50,50);
	
	RectangleShape sig(Vector2f(170,50));
	sig.setFillColor(Color(255,193,88));
	sig.setPosition(590,520);
	
	RectangleShape rectmini(Vector2f(600.00,50.00));
	rectmini.setFillColor(Color(255, 207, 127));
	rectmini.setPosition(100,125);
	
	Font fuente;
	if (!fuente.loadFromFile("PixelifySans-VariableFont_wght.ttf"))
		cout << "No se pudo cargar la fuente" << endl;
	
	Text nom;
	nom.setFont(fuente);
	nom.setCharacterSize(30);
	nom.setPosition(100,90);
	nom.setString("NOMBRE DEL JUGADOR");
	nom.setColor(Color(102, 44, 6));
		
			
	Text avatar;
	avatar.setFont(fuente);
	avatar.setCharacterSize(30);
	avatar.setPosition(100,200);
	avatar.setString("AVATAR");
	avatar.setColor(Color(102, 44, 6));
	
	
	Text siguiente;
	siguiente.setFont(fuente);
	siguiente.setCharacterSize(30);
	siguiente.setPosition(600,525);
	siguiente.setString("SIGUIENTE");
	siguiente.setColor(Color(102, 44, 6));
	
	
	ventanita.clear();
	ventanita.draw(ctnFondo);
	ventanita.draw(rectgrande);
	ventanita.draw(sig);
	ventanita.draw(rectmini);
	ventanita.draw(nom);
	ventanita.draw(avatar);
	ventanita.draw(siguiente);
}






