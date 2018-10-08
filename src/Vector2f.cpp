#include "../include/Vector2f.h"
#include "../include/math.h"
#include <iostream>

Vector2f::Vector2f() : x(0), y(0) {}
Vector2f::Vector2f (float a, float b) : x(a), y(b) { }

void Vector2f::set (float a, float b) {
	x = a;
	y = b;
}

Vector2f::~Vector2f () {}

Vector2f Vector2f::operator+ (const Vector2f &vector2f) {
	Vector2f resultado(x + vector2f.x, y + vector2f.y);
	return resultado;
}

int Vector2f::get_x() {
	return x;
}

int Vector2f::get_y() {
	return y;
}

Vector2f& Vector2f::operator= (const sf::Vector2i &vector2i) {		//Implementacao para usar retornos do sfml
		x = vector2i.x;
		y = vector2i.y;
		
	return *this; 		//Retorna o proprio objeto para atribuicao em cadeia
}

Vector2f Vector2f::operator- (const Vector2f &vector2f) {
	Vector2f resultado(x - vector2f.x, y - vector2f.y);
	return resultado;
}


Vector2f& Vector2f::operator= (const Vector2f &vector2f) {
	if (this != &vector2f) {
		x = vector2f.x;
		y = vector2f.y;
	}
	return *this; 		//Retorna o proprio objeto para atribuicao em cadeia
}

bool Vector2f::operator==(const Vector2f &vector2f) {
	bool resultado = (x == vector2f.x) && (y == vector2f.y);
	return resultado;
}


Vector2f Vector2f::operator*(float a) {
	Vector2f resultado(x*a, y*a);
	return resultado;
}

Vector2f Vector2f::operator/(float a) {
	Vector2f resultado(x/a, y/a);
	return resultado;
}


float Vector2f::length () {
	return sqrt(x*x + y*y);
}

Vector2f Vector2f::unit() {
	Vector2f resultado(x,y);
	return resultado/length();
}

/*
friend ostream &operator<<( ostream &output, const Vector2f &vector2f ){
	output << "X : " << vector2f.x << " Y : " << vector2f.y;
         return output;            
}
*/

void Vector2f::print(){
	std::cout << "X: " << x << "   Y: " << y << std::endl;
}


//Retorna o angulo em graus em relacao a outro vetor (inicio) 
float Vector2f::angle(Vector2f inicio) {
	const float PI = 3.14159265;

	int angle = atan2(y - inicio.y , x-inicio.x) * 180/PI;
	
		return angle;
}


