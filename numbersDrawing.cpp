#include <SFML/Graphics.hpp>
#include <cmath>
#include <fstream>
#include "Button.hpp"
#include "Matrix.hpp"


int main()
{

    Matrix matrix;

    matrix.resetMatrix();

    sf::RectangleShape buttonsBar( sf::Vector2f( 50, 800 ) );
    buttonsBar.setFillColor( sf::Color(100, 100, 100) );

    Button resetButton(sf::Vector2f(4,7), sf::Vector2f(20,20) ,
                     sf::Color(214, 179, 126) ,
                     sf::Color(214, 166, 53) ,
                     sf::Color(214, 173, 78)  );

    Button saveButton( sf::Vector2f(4,61), sf::Vector2f(20,20) ,
                       sf::Color(159, 200, 126) ,
                       sf::Color(146, 200, 53) ,
                       sf::Color(153, 200, 78)  );

    sf::RectangleShape Sprite( sf::Vector2f(50, 50));
    Sprite.setFillColor( sf::Color(70, 100, 70) );
    Sprite.setPosition(-100, -100);

    sf::RenderWindow applicationWindow( sf::VideoMode( 450, 400, 32 ), "Numbers Drawing" );
    sf::Event event;

    applicationWindow.clear( sf::Color(255, 255, 255) );

    while( applicationWindow.isOpen() ){


        while( applicationWindow.pollEvent( event ) ){
             if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
                 int mouseX = int(round(sf::Mouse::getPosition(applicationWindow).x / 50));
                 int mouseY = int(round(sf::Mouse::getPosition(applicationWindow).y / 50));

                 if (matrix.pixel[mouseX][mouseY] == 0 && mouseX*50 >= 50 ) {
                     matrix.pixel[mouseX][mouseY] = 1;
                     Sprite.setPosition(mouseX * 50, mouseY * 50);
                     Sprite.setFillColor( sf::Color((mouseX*50)%255, 34, 98));
                 }


             }
             if( event.type == sf::Event::Closed ){
                 applicationWindow.close();
             }


        }



        applicationWindow.draw(buttonsBar);
        applicationWindow.draw(resetButton.getShape());
        applicationWindow.draw(saveButton.getShape());
        resetButton.updateColor( sf::Mouse::getPosition(applicationWindow) );
        saveButton.updateColor( sf::Mouse::getPosition(applicationWindow) );
        applicationWindow.draw(Sprite);
        applicationWindow.display();


        /* I don't use inheritance, because I have only two buttons */

        if( resetButton.buttonPressed() ){
            matrix.resetMatrix();
            Sprite.setPosition( -100, -100 );
            applicationWindow.clear(sf::Color(255, 255, 255) );
        }

        if( saveButton.buttonPressed() ){

        }


    }
    return 0;
}