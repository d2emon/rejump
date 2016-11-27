#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <SFML/Graphics.hpp>

sf::String gameTitle = "Doodle Jumper";
int winSize[2] = {800, 600};

int fps = 60;

int backgroundsCount = 10;
sf::String backgrounds[10] = {
    "res/background/1.png",
    "res/background/2.png",
    "res/background/3.png",
    "res/background/4.png",
    "res/background/5.png",
    "res/background/6.png",
    "res/background/7.png",
    "res/background/8.png",
    "res/background/9.png",
    "res/background/10.png",
};

#endif // SETTINGS_HPP_INCLUDED
