#include <stdlib.h>
#include <iostream>
#include "GamePlay3.h"

GamePlay3::GamePlay3()
{
    vidas = 13;
    tiempojugado = 60 * 10;
    points = 0;
    time_inmunidad = 0;
    juego_pausa = false;
    apreta_pausa = false;
    game_over = false;
    llegada = false;
    cambia_nivel = true;
}

int GamePlay3::Run(sf::RenderWindow& window)
{
    sf::Event Event;
    bool Running = true;
    sf::RenderStates states; //Creo RenderState para poder dibujarlo

    texture_fondo.loadFromFile("fondo22.png");
    image.setTexture(texture_fondo);

    font.loadFromFile("8bit.ttf");

    text.setFont(font);
    text_vida.setFont(font);
    text_game_over.setFont(font);
    text_pausa.setFont(font);

    carpincho.respawn();
    camarada.respawn();
    heavy.respawn();
    pelota.respawn();

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
                    if (cambia_nivel) {
                        return(0); //0 es Menu
                    }
                    break;

                default:
                    break;
                }
            }
        }

        //Updating
        aceleracion();
        juego();
        setTextos();
        pausa();
        gameOver();
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

void GamePlay3::update()
{
    if (!game_over && !llegada && !juego_pausa) {
        repartidor.update();
        carpincho.update();
        heavy.update();
        camarada.update();
        pelota.update();

        if (heavy.isCollision(carpincho)) {
            heavy.update();
        }

        if (camarada.isCollision(carpincho)) {
            camarada.update();
        }

        if (camarada.isCollision(heavy)) {
            camarada.update();
        }

        if (tiempojugado <= 5 && !juego_pausa) {
            barrera.update();
        }
    }
    if (llegada) {
        popup.update();
    }

}

void GamePlay3::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(image, states);
    target.draw(repartidor, states);
    target.draw(carpincho, states);
    target.draw(heavy, states);
    target.draw(camarada, states);
    target.draw(pelota, states);
    target.draw(text, states);
    target.draw(text_vida, states);

    if (tiempojugado < 5) {
        //target.draw(barrera, states);
    }

    if (game_over) {
        target.draw(text_game_over, states);
    }

    if (juego_pausa) {
        target.draw(text_pausa, states);
    }

    if (llegada) {
        target.draw(popup, states);
    }
}

void GamePlay3::aceleracion()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (repartidor.getAceleracion() < 12)
        {
            repartidor.setAceleracion(0.05);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (repartidor.getAceleracion() > 6)
        {
            repartidor.setAceleracion(-0.05);
        }
    }
}

void GamePlay3::juego()
{
    if (!juego_pausa && !game_over && !llegada) {

        float velocidad = repartidor.getAceleracion() + 3;
        image.move(0, velocidad);

        if (image.getPosition().y > 0) {
            image.setPosition(image.getPosition().x, -600);
        }

        carpincho.setVelocity(sf::Vector2f(0, velocidad));
        heavy.setVelocity(sf::Vector2f(0, velocidad));
        camarada.setVelocity(sf::Vector2f(0, velocidad));
        barrera.setVelocity(sf::Vector2f(0, velocidad));
        pelota.setVelocity(sf::Vector2f(8, velocidad - 3));

        if (repartidor.getInmunidad()) {
            time_inmunidad++;
        }
        if (repartidor.getInmunidad() && time_inmunidad == 60 * 5) {
            repartidor.setInmunidad(false);
        }
        if (repartidor.isCollision(carpincho)) {
            carpincho.respawn();
            if (!repartidor.getInmunidad()) {
                vidas--;
            }
        }
        if (repartidor.isCollision(heavy)) {
            heavy.respawn();
            if (!repartidor.getInmunidad()) {
                vidas--;
                points -= 50;
            }
        }

        if (repartidor.isCollision(pelota)) {
            pelota.respawn();
            if (!repartidor.getInmunidad()) {
                points -= 50;
            }
        }

        if (repartidor.isCollision(camarada)) {
            repartidor.setInmunidad(true);
            time_inmunidad = 0;
            camarada.respawn();
            points += 100;
        }

        repartidor.setTransparencia(repartidor.getInmunidad());

        if (repartidor.isCollision(barrera)) {
            llegada = true;
        }
        tiempojugado--;
    }
    else {
        image.move(0, 0);
        carpincho.setVelocity(sf::Vector2f(0, 0));
        heavy.setVelocity(sf::Vector2f(0, 0));
        camarada.setVelocity(sf::Vector2f(0, 0));
        repartidor.setAceleracion(0);
    }

    if (llegada) {
        popup.setPuntos(points);
        popup.setVidas(vidas);
        cambia_nivel = true;
    }
}

void GamePlay3::setTextos()
{
    text.setPosition(602, 0);
    text.setString("PUNTOS: " + std::to_string(points));

    text_vida.setPosition(602, 20);
    text_vida.setString("VIDAS: " + std::to_string(vidas));

    text_game_over.setPosition(250, 300);
    text_game_over.setString("GAME OVER");

    text_pausa.setPosition(250, 300);
    text_pausa.setString("PAUSA");
}

void GamePlay3::pausa()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !apreta_pausa) {
        juego_pausa = true;
    }
    else if (juego_pausa && !apreta_pausa) {
        apreta_pausa = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && apreta_pausa) {
        juego_pausa = false;
    }
    else if (!juego_pausa && apreta_pausa) {
        apreta_pausa = false;
    }
}

void GamePlay3::gameOver()
{
    if (vidas < 1) {
        game_over = true;
    }
}

int GamePlay3::getVidas()
{
    return vidas;
}

int GamePlay3::getPuntos()
{
    return points;
}

bool GamePlay3::getCambiaNivel()
{
    return cambia_nivel;
}

void GamePlay3::setCambiaNivel()
{
    cambia_nivel = false;
}


