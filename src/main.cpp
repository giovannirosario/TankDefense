#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/menu.h"
#include "../include/singleplayer.h"
#include <iostream>

#define HEIGTH 768
#define WIDTH 1024

int main() {

    //Inicio da janela, renderizacao, graficos e tamanho.
      sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGTH), "Tank Defense");
      window.setVerticalSyncEnabled(true);

    //Sabe qual a selecao no menu
    bool running = true;
    int selected = 0;

    while (running) {
      Menu menu;
      selected = menu.display(window);
      

      while (selected == 1) {
        SinglePlayer sp;
        selected = sp.display(window);
      }

      if (selected == 5) {
        running = false;
      }

    }

      return 0;
}