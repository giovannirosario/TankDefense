#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/menu.h"
#include "../include/Vector2f.h"


Menu::Menu ()
: 	singleplayer(0), 
	multiplayer(0),
	options(0),
	credits(0),
	menu_running(true)

{
	if (!tx_menu_background.loadFromFile("images/menu_background.png"));	
	if (!tx_button.loadFromFile("images/button.png"));
	if (!tx_button_hover.loadFromFile("images/button_hover.png"));

	menu_background.setTexture(tx_menu_background);
	button.setTexture(tx_button);
	button_hover.setTexture(tx_button_hover);

	if (!font.loadFromFile("images/JANCIENT.TTF"));

	um.setFont(font);
    um.setString("SINGLEPLAYER");
    um.setCharacterSize(25);
    um.setColor(sf::Color::Black);
    um.setPosition(512-85,197);

    dois.setFont(font);
    dois.setString("MULTIPLAYER");
    dois.setCharacterSize(25);
    dois.setColor(sf::Color::Black);
    dois.setPosition(512-85,297);

    tres.setFont(font);
    tres.setString("OPTIONS");
    tres.setCharacterSize(25);
    tres.setColor(sf::Color::Black);
    tres.setPosition(512-55,397);

    quatro.setFont(font);
    quatro.setString("CREDITS");
    quatro.setCharacterSize(25);
    quatro.setColor(sf::Color::Black);
    quatro.setPosition(512-55,497);
}

Menu::~Menu(){}

int Menu::display(sf::RenderWindow &window) {
    while(menu_running) {
        //Acompanha as coordenadas do mouse;
            Vector2f mouse_pos;                     
            mouse_pos = sf::Mouse::getPosition(window);

    	sf::Event event;
      	while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)  //fecha o programa
          return 5;
      	}

    	// limpa o buffer
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    	//draw...
		menu_background.setPosition(0,0);
    	window.draw(menu_background);

        int x,y;
        x = mouse_pos.get_x();
        y = mouse_pos.get_y();


    	if (x > 512-95 && x < 512-95+190 && y > 192 && y < 192+49) {
            button_hover.setPosition(512-95, 192);
            window.draw(button_hover);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                return 1;
            }
        }
        else {
            button.setPosition(512-95,192);
            window.draw(button);
        }


        if (x > 512-95 && x < 512-95+190 && y > 292 && y < 292+49) {
            button_hover.setPosition(512-95, 292);
            window.draw(button_hover);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return 2;
        }        
        else {
            button.setPosition(512-95,292);
            window.draw(button);
        }


        if (x > 512-95 && x < 512-95+190 && y > 392 && y < 392+49) {
            button_hover.setPosition(512-95, 392);
            window.draw(button_hover);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return 3;
        }        
        else {
            button.setPosition(512-95,392);
            window.draw(button);
        }


        if (x > 512-95 && x < 512-95+190 && y > 492 && y < 492+49) {
            button_hover.setPosition(512-95, 492);
            window.draw(button_hover);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                return 4;
        }        
        else {
            button.setPosition(512-95,492);
            window.draw(button);
        }



    	window.draw(um);
    	window.draw(dois);
   		window.draw(tres);
    	window.draw(quatro);

    	//display
    	window.display();
    }

}