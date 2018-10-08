#include "../include/Player.h"
#include "../include/Projetil.h"
#include "../include/Fila.h"
#include "../include/Lista.h"
#include <SFML/Graphics.hpp>

Player::Player(): score(0), life(100), life_max(100), ammo_count(50), speed(3) {
	player_position.set(300,540);						//Define posicao inicial do player
	shot_position.set(28,0);
	size.set(45,25);
	for (int i = 0; i < 50; i++) {						//Inicia o player com 50 projeteis;
		Projetil pj(3,4); 			//Cada projetil inicial tem 3 de power e 3 de velocidade
		ammo.insert(pj);			
	}
}

Player::~Player() {}	

int Player::get_life() {
	return life;
}

int Player::get_x() {
	return player_position.get_x();
}

int Player::get_y() {
	return player_position.get_y();
}

Vector2f Player::get_position() {
	return player_position;
}

Vector2f Player::get_endposition() {
	return player_position + size;
}

int Player::get_speed() {
	return speed;
}

int Player::get_score() {
	return score;
}

void Player::add_score(int x) {
	score = score + x;
}

int Player::get_ammo_count() {
	return ammo_count;
}

void Player::move(Vector2f direction) {
	player_position = player_position + direction;
}

void Player::tira_life(int x) {
	life = life - x;
}

void Player::shot(Vector2f inicio, Vector2f destino, Lista<Projetil> &shooted, sf::Texture &tx_bullet) {
	if (ammo.isEmpty())
		return;
	else {
		Projetil x;
		ammo_count--;
		x = ammo.remove();
		x.bullet.setTexture(tx_bullet);
		x.bullet.setRotation(destino.angle(inicio));
		x.set_pos(inicio+shot_position);
		x.set_direcao(destino);
		shooted.insert(x);
	}
}


void Player::upgrade_life(int x) { 
	life_max = life_max + x;
}

void Player::add_ammo(int x, int p, int s) {
	ammo_count = ammo_count + x;		
	for (int i = 0; i < x; i++) {
		Projetil pj(p,s); 			// adiciona x projeteis 
		ammo.insert(pj);		
	}
}

void Player::regenerate(int x) {
	life = life + x;
	if (life > life_max)
		life = life_max;
}