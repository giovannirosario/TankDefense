#ifndef _SINGLEPLAYER_H_
#define _SINGLEPLAYER_H_

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Vector2f.h"
#include "Fila.h"
#include "Lista.h"
#include "Player.h"
#include "Projetil.h"
#include <string>
#include <sstream>
#include "explosion.h"
#include "enemy.h"
#include "box.h"


class SinglePlayer {
	private:
	//Iniciar e configurar relogio geral;
		sf::Clock clock1;
		sf::Time time1;
		int minutes;
		int seconds;

	//Player principal
		Player player;

	//fontes de texto
		sf::Font font;
		sf::Text score;
		sf::Text ammo;
		sf::Text tempo;
		sf::Text life;

	//textures
		sf::Texture tx_tank;
		sf::Texture tx_etank;
		sf::Texture tx_background;
		sf::Texture tx_ground;
		sf::Texture tx_turret;
		sf::Texture tx_eturret;
		sf::Texture tx_bullet;
		sf::Texture tx_base1;
		sf::Texture tx_base2;
		sf::Texture tx_base3;
		sf::Texture tx_base4;
		sf::Texture tx_helicopter;
		sf::Texture tx_helicopter2;
		sf::Texture tx_helicopter3;
		sf::Texture tx_pause_menu;
		sf::Texture tx_check_button;
		sf::Texture tx_cross_button;
		sf::Texture tx_box;
		sf::Texture tx_life_bar;
		sf::Texture tx_end_menu;

	//Sprites
		sf::Sprite tank;
		sf::Sprite background;
		sf::Sprite ground;
		sf::Sprite turret;
		sf::Sprite base;
		sf::Sprite pause_menu;
		sf::Sprite check_button;
		sf::Sprite cross_button;
		sf::Sprite life_bar;
		sf::Sprite end_menu;

	//Lista de projeteis no ar;
		Lista<Projetil> shooted;

	//uma bala por click...
		bool hold;
		bool hold_spawn;
		bool hold_spawn2;
		bool hold_shot;
	//
		bool sp_running;
		bool won;

	//positions
		Vector2f mouse_pos;
		Vector2f base_pos;
		Vector2f base_endpos;
		Vector2f enemy_aim;

	//Fila de explosions
		Fila <Explosion> fila_explosao;

	//Lista de Helicopteros
		Lista <Enemy> lista_enemy;

	//Lista de Box
		Lista <Box> lista_box;

	public: 
		SinglePlayer();
		~SinglePlayer();
		int display(sf::RenderWindow &window);
		void display_ground_explosion(int x, int y);
		bool detect_colision(Vector2f Ainicial, Vector2f Afinal, Vector2f Binicial, Vector2f Bfinal);
		bool bullet_detect_colision(Vector2f bullet_pos, int power);
		int pause_game(sf::RenderWindow &window);
		int end_game(sf::RenderWindow &window, int score);
};


#endif