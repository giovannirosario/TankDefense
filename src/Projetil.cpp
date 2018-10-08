#include "../include/Vector2f.h"
#include "../include/Projetil.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Projetil::Projetil(){
}

Projetil::Projetil(int p, int s): power(p), speed(s) {}

Projetil::~Projetil(){}


void Projetil::set_pos(Vector2f x) {
	pos = x;
}

void Projetil::set_direcao(Vector2f destino) {
	direcao = (destino - pos).unit();
}

Vector2f Projetil::get_pos() {
	return pos;
}

void Projetil::advance() {
	pos = pos + direcao * speed;
}

int Projetil::get_x() {
	return pos.get_x();
}

int Projetil::get_y() {
	return pos.get_y();
}

int Projetil::get_power() {
	return power;
}