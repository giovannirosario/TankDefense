#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/explosion.h"

Explosion::Explosion(int x, int y) {
	counter = 1;
	ground_explosion.setOrigin(28,60);
	ground_explosion.setPosition(x,y);

	if (!tx_ground_explosion1.loadFromFile("images/ground_explosion/expl_03_0001.png"));
 	if (!tx_ground_explosion2.loadFromFile("images/ground_explosion/expl_03_0002.png"));
 	if (!tx_ground_explosion3.loadFromFile("images/ground_explosion/expl_03_0003.png"));
 	if (!tx_ground_explosion4.loadFromFile("images/ground_explosion/expl_03_0004.png"));
 	if (!tx_ground_explosion5.loadFromFile("images/ground_explosion/expl_03_0005.png"));
 	if (!tx_ground_explosion6.loadFromFile("images/ground_explosion/expl_03_0006.png"));
 	if (!tx_ground_explosion7.loadFromFile("images/ground_explosion/expl_03_0007.png"));
 	if (!tx_ground_explosion8.loadFromFile("images/ground_explosion/expl_03_0008.png"));
 	if (!tx_ground_explosion9.loadFromFile("images/ground_explosion/expl_03_0009.png"));
 	if (!tx_ground_explosion10.loadFromFile("images/ground_explosion/expl_03_0010.png"));
 	if (!tx_ground_explosion11.loadFromFile("images/ground_explosion/expl_03_0011.png"));
 	if (!tx_ground_explosion12.loadFromFile("images/ground_explosion/expl_03_0012.png"));
 	if (!tx_ground_explosion13.loadFromFile("images/ground_explosion/expl_03_0013.png"));
 	if (!tx_ground_explosion14.loadFromFile("images/ground_explosion/expl_03_0014.png"));
 	if (!tx_ground_explosion15.loadFromFile("images/ground_explosion/expl_03_0015.png"));
 	if (!tx_ground_explosion16.loadFromFile("images/ground_explosion/expl_03_0016.png"));
 	if (!tx_ground_explosion17.loadFromFile("images/ground_explosion/expl_03_0017.png"));
 	if (!tx_ground_explosion18.loadFromFile("images/ground_explosion/expl_03_0018.png"));
 	if (!tx_ground_explosion19.loadFromFile("images/ground_explosion/expl_03_0019.png"));
 	if (!tx_ground_explosion20.loadFromFile("images/ground_explosion/expl_03_0020.png"));
 	if (!tx_ground_explosion21.loadFromFile("images/ground_explosion/expl_03_0021.png"));
 	if (!tx_ground_explosion22.loadFromFile("images/ground_explosion/expl_03_0022.png"));
 	if (!tx_ground_explosion23.loadFromFile("images/ground_explosion/expl_03_0023.png"));

}

Explosion::~Explosion() {}

sf::Sprite Explosion::advance() {
	if (counter == 1)
		ground_explosion.setTexture(tx_ground_explosion1);
	if (counter == 2)
		ground_explosion.setTexture(tx_ground_explosion2);
	if (counter == 3)
		ground_explosion.setTexture(tx_ground_explosion3);
	if (counter == 4)
		ground_explosion.setTexture(tx_ground_explosion4);
	if (counter == 5)
		ground_explosion.setTexture(tx_ground_explosion5);
	if (counter == 6)
		ground_explosion.setTexture(tx_ground_explosion6);
	if (counter == 7)
		ground_explosion.setTexture(tx_ground_explosion7);
	if (counter == 8)
		ground_explosion.setTexture(tx_ground_explosion8);
	if (counter == 9)
		ground_explosion.setTexture(tx_ground_explosion9);
	if (counter == 10)
		ground_explosion.setTexture(tx_ground_explosion10);
	if (counter == 11)
		ground_explosion.setTexture(tx_ground_explosion11);
	if (counter == 12)
		ground_explosion.setTexture(tx_ground_explosion12);
	if (counter == 13)
		ground_explosion.setTexture(tx_ground_explosion13);
	if (counter == 14)
		ground_explosion.setTexture(tx_ground_explosion14);
	if (counter == 15)
		ground_explosion.setTexture(tx_ground_explosion15);
	if (counter == 16)
		ground_explosion.setTexture(tx_ground_explosion16);
	if (counter == 17)
		ground_explosion.setTexture(tx_ground_explosion17);
	if (counter == 18)
		ground_explosion.setTexture(tx_ground_explosion18);
	if (counter == 19)
		ground_explosion.setTexture(tx_ground_explosion19);
	if (counter == 20)
		ground_explosion.setTexture(tx_ground_explosion20);
	if (counter == 21)
		ground_explosion.setTexture(tx_ground_explosion21);
	if (counter == 22)
		ground_explosion.setTexture(tx_ground_explosion22);
	if (counter == 23)
		ground_explosion.setTexture(tx_ground_explosion23);

	counter++;

	return ground_explosion;
}


int Explosion::get_counter() {
	return counter;
}
