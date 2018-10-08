#ifndef _PROJETIL_H_
#define _PROJETIL_H_

#include "Vector2f.h"
#include <SFML/Graphics.hpp>


class Projetil {
	private:
		Vector2f pos;
		Vector2f direcao;
		float angle;
		int power;
		int speed;

	public:
		sf::Sprite bullet;

		Projetil();
		Projetil(int p, int s);
		~Projetil();
		void set_pos(Vector2f x);
		void set_direcao(Vector2f destino);
		Vector2f get_pos();
		int get_x();
		int get_y();
		void advance();
		int get_power();
};	

#endif