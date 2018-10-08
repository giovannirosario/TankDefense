#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Fila.h"
#include "Projetil.h"
#include "Vector2f.h"
#include "Lista.h"
#include <SFML/Graphics.hpp>

class Player {
	private:
		Vector2f player_position;
		Vector2f size;
		Vector2f shot_position;
		int score;				//pontuacao
		int life;				//vida atual
		int life_max;			//vida maxima
		int ammo_count;			//Contador de municao
		Fila <Projetil> ammo;	//municao
		int speed;

	public:
		Player();
		~Player();
		int get_x();
		int get_y();
		Vector2f get_position();
		int get_speed();
		int get_score();
		void add_score(int x);
		void tira_life(int x);
		int get_ammo_count();
		void move(Vector2f direction);
		int get_life();				//retorna a life do jogador
		void shot(Vector2f inicio, Vector2f destino, Lista<Projetil> &shooted, sf::Texture &tx_bullet);				//dispara projetil
		void upgrade_life(int x);	//Aumento de life
		void add_ammo(int x, int p, int s);		//Adiciona municao
		void regenerate(int x);			//recupera até 25 pontos de vida
		Vector2f get_endposition();

};

#endif
