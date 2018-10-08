all:
	g++ -std=c++11 src/main.cpp src/Vector2f.cpp src/Player.cpp src/Projetil.cpp src/menu.cpp src/singleplayer.cpp src/explosion.cpp src/enemy.cpp src/box.cpp -o teste -lGL -lGLU -lsfml-system -lsfml-window -lsfml-graphics
	