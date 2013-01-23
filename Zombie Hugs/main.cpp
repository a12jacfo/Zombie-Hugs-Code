
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Game.h"

int main()
{
	Game game;

    // Create the main window
	sf::RenderWindow window;
	
	window.clear();

	window.create(sf::VideoMode(1280,720,32), "Zombie Hugs", sf::Style::Fullscreen);

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
        }


		game.update(window);

        // Update the window
        window.display();
		window.clear();
    }
	
    return EXIT_SUCCESS;
}