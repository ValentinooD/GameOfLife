#include <SFML/Graphics.hpp>
#include "game_of_life.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);
	game_of_life gol;

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() <= 2) continue;
		clock.restart();

		window.clear();
		gol.draw(&window);
		gol.next_generation();
		window.display();
	}

	return 0;
}