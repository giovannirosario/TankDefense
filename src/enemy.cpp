#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <time.h>
#include <stdlib.h>
#include "../include/enemy.h"
#include "../include/Projetil.h"
#include "../include/Vector2f.h"
#include <iostream>

Enemy::Enemy(){}

EnemyHelicopter::EnemyHelicopter(sf::Texture *texture1, sf::Texture *texture2, sf::Texture *texture3){
	an = 1;
	heli1 = texture1;
	heli2 = texture2;
	heli3 = texture3;

	life = 3;
	speed = 10;
	srand(time(NULL));
	int y_random = (rand() % 270) + 30;
	int x = 0;
	//enemy_sprite.setTexture(*texture1);

	direcao.set(1,0);

	position.set(x,y_random);						//Define posicao inicial do player
	size.set(48,22);
	end_position = position + size;
	shot_position.set(24,24);

	for (int i = 0; i < 10; i++) {						//Inicia o player com 50 projeteis;
		Projetil pj(2,2); 			//Cada projetil inicial tem 3 de power e 3 de velocidade
		e_ammo.insert(pj);			
	}
}

EnemyTank::EnemyTank(sf::Texture &tank, sf::Texture &turret){
	life = 3;
	speed = 10;
	int y = 540;
	an = 0;

	enemy_sprite.setTexture(tank);
	turret_sprite.setTexture(turret);
	
	srand(time(NULL));
	int r = (rand() % 2);

	//se vierem da direita
	if (r == 0) {
		direcao.set(-1,0);
		int x = 1024;
		position.set(x,y);
		shot_position.set(0,15);
		enemy_sprite.scale(-1,1);
		enemy_sprite.setOrigin(45,0);
		turret_sprite.scale(-1,1);
		turret_sprite.setOrigin(45,0);
	}
	//se vierem da esquerda
	if (r == 1) {
		int x = 0;
		direcao.set(1,0);
		position.set(x,y);							
		shot_position.set(47,0);
	}
	
	size.set(45,25);
	end_position = position + size;

	for (int i = 0; i < 10; i++) {						//Inicia o player com 50 projeteis;
		Projetil pj(1,2); 			//Cada projetil inicial tem 3 de power e 3 de velocidade
		e_ammo.insert(pj);			
	}
}

Enemy::~Enemy() {}

int Enemy::get_life() {
	return life;
}

int Enemy::get_x() {
	return position.get_x();
}

int Enemy::get_y() {
	return position.get_y();
}

Vector2f Enemy::get_position() {
	return position;
}

Vector2f Enemy::get_end_position() {
	return end_position;
}

int Enemy::get_speed() {
	return speed;
}

void Enemy::move() {
	if (an == 1) {
		enemy_sprite.setTexture(*heli1);
		an = 2;
	}

	else if (an == 2) {		
		enemy_sprite.setTexture(*heli2);
		an = 3;
	}

	else if (an == 3) {
		enemy_sprite.setTexture(*heli3);
		an = 1;
	}

	position = position + direcao*0.1*speed;
	end_position = position + size;
	enemy_sprite.setPosition(position.get_x(), position.get_y());
	turret_sprite.setPosition(position.get_x()+(28*direcao.get_x()), position.get_y() + 9);
}


void Enemy::shot(Vector2f destino, Lista<Projetil> &shooted, sf::Texture &tx_bullet) {
	if (e_ammo.isEmpty())
		return;
	else {
		Projetil x;
		x = e_ammo.remove();
		x.bullet.setTexture(tx_bullet);
		x.bullet.setRotation(destino.angle(position));
		x.set_pos(position + shot_position);
		x.set_direcao(destino);
		shooted.insert(x);
	}
}