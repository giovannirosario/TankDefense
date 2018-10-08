	#ifndef _VECTOR2F_H_
#define _VECTOR2F_H_

#include <SFML/Window.hpp>


class Vector2f {
	private:
		float x;
		float y;

	public:
		Vector2f();
		Vector2f(float a, float b);
		void set(float a, float b);
		~Vector2f();
		int get_x();
		int get_y();
		Vector2f operator+(const Vector2f &vector2f);
		Vector2f operator-(const Vector2f &vector2f);
		Vector2f& operator=(const Vector2f &vector2f);
		Vector2f& operator=(const sf::Vector2i &vector2i);		//Implementacao para usar retornos do sfml  sf::vector2
		bool operator==(const Vector2f &vector2f);
		//Vector2f operator*(const Vector2f &vector2f);
		//Vector2f operator/(const Vector2f &vector2f);	
		Vector2f operator*(float a);
		Vector2f operator/(float a);
		float length();
		Vector2f unit(); // **to fix
		//Vector2f rotate(float angle);
		//friend ostream &operator<<( ostream &output, const Vector2f &vector2f);   **to fix
 		void print();
 		float angle(Vector2f inicio);


};


#endif