#include "Credits.h"

Credits::Credits()
{
}

int Credits::Run(sf::RenderWindow& window)
{
	_texturecred.loadFromFile("creditoscp.png");
	_backgroundcred.setTexture(_texturecred);

    _font.loadFromFile("8bit.ttf");
    nombre1.setFont(_font);
    nombre2.setFont(_font);
    nombre1.setPosition(300, 500);
    nombre2.setPosition(300, 525);
    nombre1.setFillColor(sf::Color::White);
    nombre2.setFillColor(sf::Color::White);
    nombre1.setString("GONZALO BOSSETTI");
    nombre2.setString("ANDREA NUNEZ");

    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Escape:

                        return (0);
                        break;
                }
            }
        }

        window.clear();
        window.draw(_backgroundcred);
        window.draw(nombre1);
        window.draw(nombre2);
        window.display();
    }

	return (-1);
}
