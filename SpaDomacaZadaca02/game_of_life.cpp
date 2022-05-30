#include "game_of_life.h"

game_of_life::game_of_life() {
	srand(time(nullptr));
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			_generation[row][col] = random_value();
		}
	}
}

bool game_of_life::random_value() {
	return rand() % 4 == 0;
}

int game_of_life::count_neighbours(int r, int c) {
	int r_start = r - 1;
	int c_start = c - 1;
	int r_end = r + 1;
	int c_end = c + 1;

	// check bounds
	if (r_start < 0) r_start = r;
	if (c_start < 0) c_start = c;
	if (r_end > ROWS) r_end = r;
	if (c_end > COLS) c_end = c;
	
	int count = 0;

	for (int row = r_start; row <= r_end; row++) {
		for (int col = c_start; col <= c_end; col++) {
			if (cell_taken(row, col) && row != r && col != c) {
				count++;
			}
		}
	}
	
	return count;
}

bool game_of_life::cell_taken(int i, int j) {
	return _generation[i][j];
}

void game_of_life::next_generation() {
	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			int neighbours = count_neighbours(row, col);
			// if none are met we keep what's in _generation
			_next_generation[row][col] = _generation[row][col];

			// alive cell rules
			if (cell_taken(row, col)) {
				if (neighbours < 2) { // underpopulation
					_next_generation[row][col] = 0;
				}
				else if (neighbours == 2 || neighbours == 3) { // just right
					_next_generation[row][col] = 1;
				}
				else if (neighbours > 3) { // overpopulation
					_next_generation[row][col] = 0;
				}
			}
			else {
				if (neighbours == 3) {
					_next_generation[row][col] = 1;
				}
			}
		}
	}

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			_generation[row][col] = _next_generation[row][col];
		}
	}
}

void game_of_life::draw(sf::RenderWindow *window) {
	const float SIZE = 15.0f;
	sf::RectangleShape rect(sf::Vector2f(SIZE, SIZE));

	for (int row = 0; row < ROWS; row++) {
		for (int col = 0; col < COLS; col++) {
			if (cell_taken(row, col)) {
				rect.setPosition(col * SIZE, row * SIZE);
				window->draw(rect);
			}
		}
	}
}
