#include <SFML/Graphics.hpp>
#include <time.h>
#include "settings.hpp"

struct point
{int x, y;};

int main()
{
    srand(time(0));

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(winSize[0], winSize[1]), gameTitle);
    app.setFramerateLimit(60);

    // Load a sprite to display
    sf::Texture texture1;
    if (!texture1.loadFromFile("res/background.png"))
        return EXIT_FAILURE;

    sf::Texture texture2;
    if (!texture2.loadFromFile("res/platform.png"))
        return EXIT_FAILURE;

    sf::Texture texture3;
    if (!texture3.loadFromFile("res/doodle.png"))
        return EXIT_FAILURE;

    sf::Sprite sBackground(texture1);
    sf::Sprite sPlatform(texture2);
    sf::Sprite sPers(texture3);

    point plat[20];
    for(int i=0; i<10; i++)
    {
        plat[i].x = rand() % winSize[0];
        plat[i].y = rand() % winSize[1];
    }

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sBackground);
        app.draw(sPers);
        for(int i=0; i<10; i++)
        {
            sPlatform.setPosition(plat[i].x, plat[i].y);
            app.draw(sPlatform);
        }

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
