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

    int x=100;
    int y=100;
    int h=200;

    float dx=0;
    float dy=0;

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                app.close();
            // if (event.type == sf::Event::KeyPressed)
                // if (event.key.code == sf::Keyboard::Up) rotate = true;
                // if (event.key.code == sf::Keyboard::Right) x += 3;
                // else if (event.key.code == sf::Keyboard::Left) x -= 3;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x += 3;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x -= 3;

        dy += 0.2;
        y += dy;
        if (y>500)
            dy = -10;

        for(int i=0; i<10; i++)
            if((x + 50 > plat[i].x) && (x + 20 < plat[i].x + 68)
                && (y + 70 > plat[i].y) && (y + 70 < plat[i].y + 14) && (dy > 0))
                dy = -10;

        sPers.setPosition(x, y);

        // Clear screen
        // app.clear();

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
