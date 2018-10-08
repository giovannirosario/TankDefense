#ifndef _MENU_H_
#define _MENU_H_

class Menu {
private:
	//Para cada button:
	// 0 = imagem normal
	// 1 = mouse em cima, imagem hoover
	// 2 = foi clicado

	int singleplayer;
	int multiplayer;
	int options;
	int credits;
	bool menu_running;
	
	sf::Texture tx_menu_background;
	sf::Texture tx_button;
	sf::Texture tx_button_hover;

	sf::Sprite menu_background;
	sf::Sprite button;
	sf::Sprite button_hover;

	sf::Font font;
	sf::Text um;
	sf::Text dois;
	sf::Text tres;
	sf::Text quatro;

public:
	Menu();
	~Menu();
	int display(sf::RenderWindow &window);
};


#endif