#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/Vector2f.h"
#include "../include/Player.h"
#include "../include/Projetil.h"
#include "../include/box.h"

Box::Box () {}

Box::Box(int x, Vector2f y, sf::Texture &tx_box, sf::Time time1) {
	ini_time = time1;
	type = x;
	pos = y;
	if(pos.get_y() > 768 - 200 - 30) {
		pos.set(pos.get_x(), 768-200-30);
	}

	size.set(30,30);
	gravity.set(0,2);
	end_pos = pos + size;

	sp_box.setTexture(tx_box);
	sp_box.setPosition(pos.get_x(), pos.get_y());
}

Box::~Box() {}


sf::Sprite Box::get_sprite() {
	return sp_box;
}

void Box::advance() {
	if (end_pos.get_y() < 768 - 200) {
		pos = pos + gravity;
		end_pos = pos + size;
		sp_box.setPosition(pos.get_x(), pos.get_y());
	}
}

int Box::get_type() {
	return type;
}