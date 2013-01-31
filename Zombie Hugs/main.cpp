#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game.h"

int main()
{
	Game game;
	srand(time(NULL));
    // Create the main window
	sf::RenderWindow window;
	
	window.clear(sf::Color::Black);

	window.create(sf::VideoMode(1280,720,32), "Zombie Hugs"/*, sf::Style::Fullscreen*/);

	window.setFramerateLimit(60);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
                window.close();			 
			}
			if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						game.leftMouseClick(window);
					}
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						game.rightMouseClick(window);
					}
				}
        }


		game.run(window);

        // Update the window
        window.display();
		window.clear();
    }
	
    return EXIT_SUCCESS;
}