#include "Menu.h"

Menu::Menu()
{
    _menuSelected = -1;
    playing = false;
    credits = false;
    scores = false;
}

int Menu::Run(sf::RenderWindow& window)
{   
    sf::Event Event;
    bool Running = true;

    _textureback.loadFromFile("backmenu.png");
    _background.setTexture(_textureback);

    _font.loadFromFile("8bit.ttf");

    _menu[0].setFont(_font);
    _menu[0].setFillColor(sf::Color::White);
    _menu[0].setString("JUGAR");
    _menu[0].setCharacterSize(40);
    _menu[0].setPosition(500, 300);

    _menu[1].setFont(_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("CREDITOS");
    _menu[1].setCharacterSize(40);
    _menu[1].setPosition(500, 325);

    _menu[2].setFont(_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("SCORES");
    _menu[2].setCharacterSize(40);
    _menu[2].setPosition(500, 350);

    _menu[3].setFont(_font);
    _menu[3].setFillColor(sf::Color::White);
    _menu[3].setString("SALIR");
    _menu[3].setCharacterSize(40);
    _menu[3].setPosition(500, 375);


    while (Running)
    {
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }

            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {

                case sf::Keyboard::Up:
                    MoveUp();
                    break;

                case sf::Keyboard::Down:
                    MoveDown();
                    break;

                case sf::Keyboard::Return:

                    int x = MenuPressed();

                    switch (x)
                    {
                    case 0:
                        playing = true;
                        return (3);
                        break;

                    case 1:
                        credits = true;
                        return (1);
                        break;

                    case 2:
                        scores = true;
                        return (2);
                        break;

                    case 3:
                        return (-1);
                        break;

                    }
                }
            }
        }

        window.clear();

        window.draw(_background);
        draw(window);

        window.display();

    }

    return (-1);
}



void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < items; i++) {
        window.draw(_menu[i]);
    }
}

void Menu::MoveUp()
{
    if (_menuSelected - 1 >= 0) {

        _menu[_menuSelected].setFillColor(sf::Color::White);
        _menuSelected--;

        if (_menuSelected == -1) {
            _menuSelected = 2;
        }

        _menu[_menuSelected].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (_menuSelected + 1 <= items) {

        _menu[_menuSelected].setFillColor(sf::Color::White);
        _menuSelected++;

        if (_menuSelected == 4) {
            _menuSelected = 0;
        }

        _menu[_menuSelected].setFillColor(sf::Color::Red);
    }
}

int Menu::MenuPressed()
{
    return _menuSelected;
}
