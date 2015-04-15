#include <SFML/Graphics.hpp>
#include <unistd.h>
#include <iostream>
#include "Main_Game.hpp"
/*struct screens
{

    sf::Text text[4];
    sf::RectangleShape shapes[1];
    static int i = 0;
    void addText(sf::Text newText)
    {
        text[i] = newText;
    }
    void addRect(sf::RectangleShape shape)
    {
        shapes[0] = shape;
    }
    void draw(sf::RenderWindow window)
    {
        for(int i = 0; i < 4; i++)
        {
            window.draw(text[i]);
        }
        window.draw(RectangleShape[0]);
    }
};*/

int main()
{
    unsigned int pos = 0;
    sf::RenderWindow window(sf::VideoMode(600,600), "SFML Works");
    sf::Font font;
    sf::Text newGame("New Game", font, 30);
    sf::Text loadGame("Load Game", font, 30);
    sf::Text settings("Settings", font, 30);
    sf::Text quit("Quit", font, 30);

    newGame.setPosition(250, 150);
    loadGame.setPosition(250, 250);
    settings.setPosition(250, 350);
    quit.setPosition(250, 450);

    sf::RectangleShape select(sf::Vector2f(300, 150));
    select.setPosition(200, 150);
    select.setSize(sf::Vector2f(200, 50));
    select.setFillColor(sf::Color(150, 50, 200));

    if (!font.loadFromFile("/usr/share/fonts/truetype/dustin/progenisis.ttf"))
    {
        return 1;
    }
    while (window.isOpen())
    {
        sf::Event event;
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            pos = abs((pos - 1) % 4);
            select.setPosition(200, (pos * 100 + 150));
            usleep(100000);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            pos = abs((pos + 1) % 4);
            select.setPosition(200, (pos * 100 + 150));
            usleep(100000);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            usleep(100000);
            switch(pos)
            {
                case 0:
                    window.close();
                    Game_Main();
                    break;
                case 1:
                    std::cout << "Load Game";
                    break;
                case 2:
                    std::cout << "Settings";
                    break;
                case 3:
                    window.close();
                    break;
                default:
                    std::cout << "ERROR";
            }

        }
        window.clear();
        window.draw(select);
        window.draw(newGame);
        window.draw(loadGame);
        window.draw(settings);
        window.draw(quit);
        window.display();
    }
}

