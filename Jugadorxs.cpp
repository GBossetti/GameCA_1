#include "Jugadorxs.h"

Jugadorxs::Jugadorxs()
{
    ingreso_nombre = false;
}


int Jugadorxs::Run(sf::RenderWindow& window)
{
    sf::Event Event;
    bool Running = true;
    sf::RenderStates states;

    //Cuadro de texto
    _cuadro.setSize(sf::Vector2f(400, 300));
    _cuadro.setOrigin(sf::Vector2f(_cuadro.getLocalBounds().width / 2, _cuadro.getLocalBounds().height / 2));
    _cuadro.setPosition(sf::Vector2f(300, 300));
    _cuadro.setFillColor(sf::Color::Black);	_font.loadFromFile("8bit.ttf");

    // Establecemos fuente y tamanio
    _font.loadFromFile("8bit.ttf");

    //Texto Pide Nombre
    _pideNombre.setFont(_font);
    _pideNombre.setCharacterSize(30);
    _pideNombre.setPosition(sf::Vector2f(200, 150));
    _pideNombre.setString("INSERTE SU NOMBRE:");

    //Carga Nombre
    _playerText.setFont(_font);
    _playerText.setCharacterSize(30);
    _playerText.setPosition(sf::Vector2f(200, 170));

    while (Running)
    {
        //Verifying events
        while (window.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Escape:
                    return (0);
                    break;

                case sf::Keyboard::Enter:
                    if (ingreso_nombre) {
                        return(4); //4 es GamePlay2
                    }
                    break;

                default:
                    break;
                }
            }


            if (!ingreso_nombre && Event.type == sf::Event::TextEntered)
            {
                cargarNombre(static_cast<char>(Event.text.unicode));

                std::cout << "ASCII character typed: " << static_cast<char>(Event.text.unicode) << std::endl;
                std::cout << "ASCII character typed: " << static_cast<int>(Event.text.unicode) << std::endl;
                if (_playerInput.getSize() > 0 && Event.text.unicode == 13) {
                    ingreso_nombre = true;
                }
            }

        }

        //Updating
        update();

        //Clearing screen
        window.clear(sf::Color::Black);

        //Drawing
        draw(window, states);
        window.display();
    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}

void Jugadorxs::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_cuadro, states);
	target.draw(_pideNombre, states);
	target.draw(_playerText, states);
}



void Jugadorxs::cargarNombre(int n)
{
	
	int unicode = n;
	int textSize = _playerInput.getSize();


	if (unicode == 8) { //If backspace
		if (textSize > 0)
			_playerInput.erase(static_cast<size_t>(textSize) - 1, 1); //Genera un arithmetic overflow
	}
	else if (unicode >= 32 && unicode <= 126) {
		
	}
	else if (unicode >= 192 && unicode <= 255) {
		_playerInput += (char)unicode;
	}    

	else if (unicode == 10) {
		_playerInput += "/0";
	}
}

void Jugadorxs::update() 
{
	_playerText.setString(_playerInput);
}

