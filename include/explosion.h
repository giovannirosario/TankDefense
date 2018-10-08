#ifndef _EXPLOSION_H_
#define _EXPLOSION_H_

class Explosion {
	private:
		sf::Texture tx_ground_explosion1;
		sf::Texture tx_ground_explosion2;
		sf::Texture tx_ground_explosion3;
		sf::Texture tx_ground_explosion4;
		sf::Texture tx_ground_explosion5;
		sf::Texture tx_ground_explosion6;
		sf::Texture tx_ground_explosion7;
		sf::Texture tx_ground_explosion8;
		sf::Texture tx_ground_explosion9;
		sf::Texture tx_ground_explosion10;
		sf::Texture tx_ground_explosion11;
		sf::Texture tx_ground_explosion12;
		sf::Texture tx_ground_explosion13;
		sf::Texture tx_ground_explosion14;
		sf::Texture tx_ground_explosion15;
		sf::Texture tx_ground_explosion16;
		sf::Texture tx_ground_explosion17;
		sf::Texture tx_ground_explosion18;
		sf::Texture tx_ground_explosion19;
		sf::Texture tx_ground_explosion20;
		sf::Texture tx_ground_explosion21;
		sf::Texture tx_ground_explosion22;
		sf::Texture tx_ground_explosion23;


		sf::Sprite ground_explosion;

		int counter;


	public:
		Explosion(){};
		Explosion(int x, int y);
		~Explosion();
		sf::Sprite advance();
		int get_counter();
};

#endif