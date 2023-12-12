#ifndef BOTONJUGAR_H
#define BOTONJUGAR_H
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;

class BotonJugar {
	private:
		Sprite ctn_imagen;
	public:
		BotonJugar();
		Sprite dibujar();
};

#endif
