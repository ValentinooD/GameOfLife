#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace std;

class game_of_life {
private:
	static const unsigned int COLS = 53;
	static const unsigned int ROWS = 39;
	bool _generation[ROWS][COLS];
	bool _next_generation[ROWS][COLS];
	bool random_value();
	int count_neighbours(int r, int c);
	bool cell_taken(int i, int j);

public:
	game_of_life();
	void next_generation();
	void draw(sf::RenderWindow *window);
};

#endif
