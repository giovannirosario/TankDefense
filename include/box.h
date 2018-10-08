#ifndef _BOX_H_
#define _BOX_H_

class Box {
private:
	int type;
	Vector2f size;
	Vector2f gravity;
	sf::Sprite sp_box;

public:
	Vector2f pos;
	Vector2f end_pos;
	sf::Time ini_time;

	Box();
	Box(int x, Vector2f y, sf::Texture &tx_box, sf::Time time1);
	~Box();
	sf::Sprite get_sprite();
	void advance();
	int get_type();
};


#endif