#include "GameScene.h"

int GameScene::Run(sf::RenderWindow& window)
{
    sf::Event Event;
    bool Running = true;
    sf::RenderStates states;

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

                default:
                    break;
                }
            }
        }
    
	    while (!gp1.getCambiaNivel()) {
		    gp1.Run(window);
            gp1.update();
        }
	
	    while (!gp2.getCambiaNivel()) {
		    gp2.Run(window);
            gp2.update();

	    }

	    while (!gp3.getCambiaNivel()) {
		    gp3.Run(window);
            gp3.update();
	    }

        ////Clearing screen
        //window.clear(sf::Color::Black);
        //
        ////Drawing
        //window.display();
        
        
        return 0;
    }

    //Never reaching this point normally, but just in case, exit the application
    return -1;
}

