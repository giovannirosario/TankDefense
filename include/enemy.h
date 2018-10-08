#ifndef _ENEMY_HELICOPTER_H_
#define _ENEMY_HELICOPTER_H_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vector2f.h"
#include "Player.h"
#include "Projetil.h"
#include <string>
#include <sstream>
#include "explosion.h"

class Enemy {
	protected:
		Vector2f position;
		Vector2f end_position;
		Vector2f size;
		Vector2f shot_position;
		int life;
		int speed;
		Fila <Projetil> e_ammo;	//municao
		Vector2f direcao;
		int an;
		sf::Texture* heli1;
		sf::Texture* heli2;
		sf::Texture* heli3;

	public:
		sf::Sprite enemy_sprite;
		sf::Sprite turret_sprite;
		
		Enemy();
		~Enemy();
		int get_x();
		int get_y();
		Vector2f get_position();
		Vector2f get_end_position();
		int get_speed();
		void move();
		int get_life();
		void shot(Vector2f destino, Lista<Projetil> &shooted,  sf::Texture &tx_bullet);

};
	

class EnemyHelicopter : public Enemy {
	public:
		EnemyHelicopter(){};
		EnemyHelicopter(sf::Texture *texture1, sf::Texture *texture2, sf::Texture *texture3);
		//void move();
};

class EnemyTank : public Enemy {
	public:
		EnemyTank(){};
		EnemyTank(sf::Texture &tank, sf::Texture &turret);

		//void move();
};

#endif