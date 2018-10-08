#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/singleplayer.h"
#include "../include/Vector2f.h"
#include "../include/Fila.h"
#include "../include/Lista.h"
#include "../include/Player.h"
#include "../include/Projetil.h"
#include <string>
#include <sstream>
#include "../include/explosion.h"
#include "../include/enemy.h"
#include <iostream>
#include "../include/box.h"

#define HEIGTH 768
#define WIDTH 1024

SinglePlayer::SinglePlayer() {
//Carregar fonte de texto
	font.loadFromFile("images/JANCIENT.TTF");
	score.setFont(font);
	score.setCharacterSize(25);
  score.setColor(sf::Color::Black);
  score.setPosition(20,10);
   
	ammo.setFont(font);
	ammo.setCharacterSize(25);
  ammo.setColor(sf::Color::Black);
  ammo.setPosition(200,10);
   
	tempo.setFont(font);
	tempo.setCharacterSize(25);
  tempo.setColor(sf::Color::Black);
  tempo.setPosition(400,10);

  life.setFont(font);
  life.setCharacterSize(25);
  life.setColor(sf::Color::Black);
  life.setPosition(600,10);

    

//Carregar textures
	if (!tx_tank.loadFromFile("images/tank.png"));
  if (!tx_etank.loadFromFile("images/enemy.png"));
	if (!tx_background.loadFromFile("images/background.png"));
	if (!tx_ground.loadFromFile("images/ground.png"));
	if (!tx_turret.loadFromFile("images/turret.png"));
  if (!tx_eturret.loadFromFile("images/eturret.png"));
 	if (!tx_bullet.loadFromFile("images/bullet.png"));
 	if (!tx_base1.loadFromFile("images/base1.png"));
 	if (!tx_base2.loadFromFile("images/base2.png"));
 	if (!tx_base3.loadFromFile("images/base3.png"));
 	if (!tx_base4.loadFromFile("images/base4.png"));
  if (!tx_helicopter.loadFromFile("images/chopper1.png"));
  if (!tx_helicopter2.loadFromFile("images/chopper2.png"));
  if (!tx_helicopter3.loadFromFile("images/chopper3.png"));
  if (!tx_pause_menu.loadFromFile("images/pause_menu.png"));
  if (!tx_check_button.loadFromFile("images/box_check.png"));
  if (!tx_cross_button.loadFromFile("images/box_cross.png"));
  if (!tx_box.loadFromFile("images/box.png"));
  if (!tx_life_bar.loadFromFile("images/life_bar.png"));
  if (!tx_end_menu.loadFromFile("images/end_menu.png"));


//Carregar sprites
	tank.setTexture(tx_tank);
	background.setTexture(tx_background);
	ground.setTexture(tx_ground);
  turret.setTexture(tx_turret);
	turret.setOrigin(0,3);
  pause_menu.setTexture(tx_pause_menu);
  pause_menu.setPosition(350,50);
  life_bar.setTexture(tx_life_bar);
  life_bar.setPosition((WIDTH-147)/2+20, HEIGTH-280);
  end_menu.setTexture(tx_end_menu);
  end_menu.setPosition(300,50);



  check_button.setTexture(tx_check_button);
  cross_button.setTexture(tx_cross_button);

  check_button.setPosition(550,155);
  cross_button.setPosition(550,235);

	base.setTexture(tx_base1);
	base.setPosition((WIDTH-147)/2, HEIGTH-200-56);

  base_pos.set((WIDTH-147)/2, HEIGTH-200-56);
  base_endpos.set((WIDTH-147)/2 + 147, HEIGTH-200-56 + 55);
  enemy_aim.set(WIDTH/2, 558);

	hold = false;
  hold_spawn = false;
  hold_spawn2 = false;
  hold_shot = false;
	sp_running = true;
  won = false;
}

SinglePlayer::~SinglePlayer(){}

int SinglePlayer::display (sf::RenderWindow &window) {	
//Loop principal
	while (sp_running) {	
    	sf::Event event;
      	while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)  //fecha o programa
          	return 5;
          

        	else if (event.type == sf::Event::LostFocus || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				    int t = pause_game(window);
            if (t != 0)
              return t;
        	}
   			}
           


    //Atualizando relogio
      time1 = clock1.getElapsedTime();
      minutes = time1.asSeconds();
      minutes = minutes/60;
      seconds = time1.asSeconds();
      seconds = seconds%60;

    //Atualiza e seta todos os textos (Score, Ammo e Time)

      std::stringstream sc;
      sc << player.get_score();
      score.setString("SCORE:   " + sc.str());

      std::stringstream ss;
      ss << player.get_ammo_count();
      ammo.setString("AMMO:   " + ss.str());


      std::stringstream xx;
      xx << minutes;
      std::stringstream mm;
      mm << seconds;
      tempo.setString("TIME:  " + xx.str() + " : " + mm.str());

      std::stringstream ll;
      ll << player.get_life();
      life.setString("LIFE:  " + ll.str());
  
 

   	//Controles;
   		//Acompanha as coordenadas do mouse;			
   			mouse_pos = sf::Mouse::getPosition(window);
   			//pos.print();

   		//dispara
   			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false) {
   				player.shot(player.get_position(),mouse_pos,shooted, tx_bullet);
         		hold = true;
			  }

        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
          hold = false;
        }

			//mover para esquerda
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.get_x() > 0)	{
          Vector2f left(-player.get_speed(),0);
   				player.move(left);
			}

			//mover para direita
			  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.get_x() < (WIDTH - 44))	{
				  Vector2f right(player.get_speed(),0);
   				player.move(right);
			  }


      //Spawn de inimigo helicoptero a cada 5 segundos
        if (seconds % 4 == 0 && hold_spawn == false) {
          EnemyHelicopter x(&tx_helicopter, &tx_helicopter2, &tx_helicopter3);
          lista_enemy.insert(x);
          hold_spawn = true;
        }
        else
          if (seconds % 4 != 0)
            hold_spawn = false;

      //Spawn de inimigo tank a cada 6 segundos
        if (seconds % 5 == 0 && hold_spawn2 == false) {
          EnemyTank x(tx_etank, tx_eturret);
          lista_enemy.insert(x);
          hold_spawn2 = true;
        }

        else
          if (seconds % 5 != 0)
            hold_spawn2 = false;    

        // limpa o buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // desenha. os elementos...
        background.setPosition(0,0);
        window.draw(background);
        window.draw(base);

        window.draw(score);
        window.draw(ammo);
        window.draw(tempo);
        window.draw(life);
        window.draw(score);

        double lfsz = player.get_life();
        lfsz = lfsz * 0.01f;
        life_bar.setScale(lfsz, 1);
        window.draw(life_bar);

       	tank.setPosition(player.get_x(),player.get_y());
        window.draw(tank);

        ground.setPosition(0,HEIGTH-200);
        window.draw(ground);

        turret.setPosition(player.get_x()+28, player.get_y()+11);

          //calcula o angulo do turret  - angulo de mouse_pos em relacao a player_position -
          int angle = mouse_pos.angle(player.get_position());
          if (angle > 0 && angle < 90){
            angle = 0;
          }
          if (angle > 90 && angle < 180) {
            angle = 180;
          }
         
          turret.setRotation(angle);   
          window.draw(turret);


          //percorre a lista de enemys
          if (!lista_enemy.isEmpty()) {
              lista_enemy.aux = lista_enemy.inicio;
              //percorre a lista
              while (lista_enemy.aux != nullptr) {
                  int x,y;
                  x = lista_enemy.aux->data.get_x();
                  y = lista_enemy.aux->data.get_y();
                  lista_enemy.aux->data.move();
                  window.draw(lista_enemy.aux->data.enemy_sprite);
                  window.draw(lista_enemy.aux->data.turret_sprite); 

                  if (detect_colision(player.get_position(), player.get_endposition(), lista_enemy.aux->data.get_position(), lista_enemy.aux->data.get_end_position())) {
                      return end_game(window, player.get_score());
                  }

                  if (detect_colision(lista_enemy.aux->data.get_position(), lista_enemy.aux->data.get_end_position(),base_pos, base_endpos)) {
                      return end_game(window, player.get_score());
                  } 


                  if (seconds % 5 == 0 && hold_shot == false) {
                    lista_enemy.aux->data.shot(enemy_aim, shooted, tx_bullet);
                  }

                  lista_enemy.aux = lista_enemy.aux->next;
              }
               hold_shot = true;
              if (seconds % 5 != 0) {
                hold_shot = false;
              }
          }
          



          //percorre a lista de projeteis shooted, desenha cada um e atualiza a posicao
        if (!shooted.isEmpty()) {
            shooted.aux = shooted.inicio;

            //percorre a lista
            while (shooted.aux != nullptr) {
              int x,y;
              x = shooted.aux->data.get_x();
              y = shooted.aux->data.get_y();
              
            	if (x > WIDTH || x < 0 || y > HEIGTH-200 || y < 0 || 
                bullet_detect_colision(shooted.aux->data.get_pos(), shooted.aux->data.get_power())) 

              {
            		  //cria uma explosao e caixa
                  Explosion explo(x,y);
                                    //insere na fila 
                  fila_explosao.insert(explo);
                  
                	shooted.aux2 = shooted.aux->next;
                	shooted.remove(shooted.aux);
                	shooted.aux = shooted.aux2;
            	}

            	else {
                	shooted.aux->data.bullet.setPosition(x,y);
                	window.draw(shooted.aux->data.bullet); 
                	shooted.aux->data.advance();
                	shooted.aux = shooted.aux->next;
            	}
            }
        }


        //percorre a fila de explosoes 
        if (!fila_explosao.isEmpty()) {
          fila_explosao.busca = fila_explosao.inicio;

          //percorre a fila
          while (fila_explosao.busca != nullptr) {
            //desenha cada explosao no seu devido estagio e avanca seu estagio
            if (fila_explosao.busca->data.get_counter() != 24) {
              window.draw(fila_explosao.busca->data.advance());
              fila_explosao.busca = fila_explosao.busca->next;
            }

            //Se era o ultimo estagio, remove da fila de explosao
            else {
              fila_explosao.remove();
              break;
            }
          }
        }

        //percore a lista de box
         if (!lista_box.isEmpty()) {
            lista_box.aux = lista_box.inicio;

            //percorre a lista
            while (lista_box.aux != nullptr) {
                  window.draw(lista_box.aux->data.get_sprite());
                 
              //se houver colisao (pegar a box)
              if(detect_colision(lista_box.aux->data.pos,lista_box.aux->data.end_pos, player.get_position(), player.get_endposition())){
                  player.add_ammo(seconds%4 + 1,1,4);
                  lista_box.aux2 = lista_box.aux->next;
                  lista_box.remove(lista_box.aux);
                  lista_box.aux = lista_box.aux2;
                  break;
              }


              //se a caixa ja existir a 10 segundos, destruir caixa
              else if (time1.asSeconds() > lista_box.aux->data.ini_time.asSeconds() + 10) {
                  lista_box.aux2 = lista_box.aux->next;
                  lista_box.remove(lista_box.aux);
                  lista_box.aux = lista_box.aux2;
                  break;
              }


                  lista_box.aux->data.advance();
                  lista_box.aux = lista_box.aux->next;
              }

        }

        if (player.get_life() <= 0) {
          return end_game(window, player.get_score());
        }

        if (minutes == 2) {
          won = true;
          return end_game(window, player.get_score());
        }
       
             
	    // display...
        window.display();
	}
}


bool SinglePlayer::detect_colision (Vector2f Ainicial, Vector2f Afinal, Vector2f Binicial, Vector2f Bfinal) {
  if (Ainicial.get_x() <= Bfinal.get_x() &&
      Afinal.get_x() >= Binicial.get_x() &&
      Ainicial.get_y() <= Bfinal.get_y() &&
      Afinal.get_y() >= Binicial.get_y())
      return true;

  else 
    return false;
}


bool SinglePlayer::bullet_detect_colision(Vector2f bullet_pos, int power) {
//percorre a lista de enemys
          if (!lista_enemy.isEmpty()) {
              lista_enemy.aux = lista_enemy.inicio;
              //percorre a lista
              while (lista_enemy.aux != nullptr) {
                  Vector2f pos = lista_enemy.aux->data.get_position();
                  Vector2f endpos = lista_enemy.aux->data.get_end_position();
                  
                  if(bullet_pos.get_x() > pos.get_x() && bullet_pos.get_x() < endpos.get_x() && 
                    bullet_pos.get_y() > pos.get_y() && bullet_pos.get_y() < endpos.get_y()) {
                    //Por enquanto, elimina. Ira apenas tirar vida, e o processo de eliminar sera separado 
                    // e acontecera a vida chegar a 0;
                    lista_enemy.remove(lista_enemy.aux);
                    player.add_score(10);
                    
                    //dropa caixa
                    Box bx(1,shooted.aux->data.get_pos(),tx_box, time1);
                    lista_box.insert(bx);

                    return true;
                    
                  }

                  else
                    lista_enemy.aux = lista_enemy.aux->next;
              }
          }

          if(bullet_pos.get_x() > base_pos.get_x() && bullet_pos.get_x() < base_endpos.get_x() && 
                    bullet_pos.get_y() > base_pos.get_y() && bullet_pos.get_y() < base_endpos.get_y()) {
                    player.tira_life(power);
                    return true;
          }
         
          else
              return false;
}
            


int SinglePlayer::pause_game(sf::RenderWindow &window) {
    int x,y;
    bool running = true;

      window.draw(pause_menu);
      window.draw(check_button);
      window.draw(cross_button);
      

      window.display();

    while(running) {
      sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)  //fecha o programa
            return 5;
    }

      mouse_pos = sf::Mouse::getPosition(window);
      x = mouse_pos.get_x();
      y = mouse_pos.get_y();

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false && 
          x > 385 && x < 600 && y > 315 && y < 355) {
          hold = true;
          return 0;
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false && 
          x > 385 && x < 600 && y > 405 && y < 445) {
          hold = true;
          return 1;
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false && 
          x > 385 && x < 600 && y > 490 && y < 535) {
          hold = true;
          return 2;
      }

      hold = false;
    }
}

int SinglePlayer::end_game(sf::RenderWindow &window, int score) {
    int x,y;
    bool running = true;
    window.draw(end_menu);
    sf::Text end_message;

  end_message.setFont(font);
  end_message.setCharacterSize(70);
  end_message.setColor(sf::Color::Black);
  end_message.setPosition(320,100);

  std::stringstream yy;
  yy << score;

  if (won) {
    end_message.setString("     You Won ! \n Your score is: \n             " + yy.str());
  }

  else {
    end_message.setString("     You Lose ! \n Your score is: \n            " + yy.str());
  }


  window.draw(end_message);
  window.display();


    while(running) {
      sf::Event event;
        while (window.pollEvent(event)) {
          if (event.type == sf::Event::Closed)  //fecha o programa
            return 5;
        }

      mouse_pos = sf::Mouse::getPosition(window);
      x = mouse_pos.get_x();
      y = mouse_pos.get_y();


      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false && 
          x > 385 && x < 600 && y > 405 && y < 445) {
          hold = true;
          return 1;
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hold == false && 
          x > 385 && x < 600 && y > 490 && y < 535) {
          hold = true;
          return 2;
      }

      hold = false;
    }




}