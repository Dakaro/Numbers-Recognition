#include <SFML/Graphics.hpp>
#include <cmath>

bool pixel[17][17];

bool containsPoint( float x, float y )
{
    if( x >= 0 && x <= 50 && y >= 0 && y <= 50 ){
        return 1;
    }

    return 0;
}



int main()
{
    int mouseX = 0;
    int mouseY = 0;
    sf::RectangleShape buttonsBar( sf::Vector2f( 50, 800 ) );
    buttonsBar.setFillColor( sf::Color(100, 100, 100) );

    sf::RectangleShape Sprite( sf::Vector2f(50, 50));
    Sprite.setFillColor( sf::Color(70, 100, 70) );

    sf::RenderWindow applicationWindow( sf::VideoMode( 450, 400, 32 ), "Numberss Drawing" );
    sf::Event event;

    applicationWindow.clear( sf::Color(255, 255, 255) );

    while( applicationWindow.isOpen() ){


        while( applicationWindow.pollEvent( event ) ){
             if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
                 mouseX = int(round(sf::Mouse::getPosition(applicationWindow).x / 50));
                 mouseY = int(round(sf::Mouse::getPosition(applicationWindow).y / 50));

                 if (pixel[mouseX][mouseY] == 0 && mouseX*50 >= 50 ) {
                     pixel[mouseX][mouseY] = 1;
                     Sprite.setPosition(mouseX * 50, mouseY * 50);
                     Sprite.setFillColor( sf::Color((mouseX*50)%255, 34, 98));
                 }


             }
             if( event.type == sf::Event::Closed ){
                 applicationWindow.close();
             }


        }


        applicationWindow.draw(Sprite);
        applicationWindow.draw(buttonsBar);
        applicationWindow.display();


    }
    return 0;
}