#include "MainState.hpp"
#include <cmath>
#include <iostream>

MainState::MainState(){

    // dark left bar
    buttonsBar = sf::RectangleShape( sf::Vector2f( 50, 800 ) );
    buttonsBar.setFillColor( sf::Color(100, 100, 100) );

    // reset button
     resetButton = Button(sf::Vector2f(4,7), sf::Vector2f(16,16) ,
                       sf::Color(214, 179, 126) ,
                       sf::Color(214, 166, 53) ,
                       sf::Color(214, 173, 78), "R"  );

    // save button
    saveButton = Button ( sf::Vector2f(4,45), sf::Vector2f(16,16) ,
                       sf::Color(159, 200, 126) ,
                       sf::Color(146, 200, 53) ,
                       sf::Color(153, 200, 78) ,  "S" );

    // number select button
    for( int i = 0; i < 10; ++i ){
        numberButton[i] = Button ( sf::Vector2f(6,55 + (32 * (i+1) ) ), sf::Vector2f(14,14) ,
                                   sf::Color(59, 32 * (i+1), 126) ,
                                   sf::Color(46, 32 * (i+1), 53) ,
                                   sf::Color(53, 32 * (i+1), 78), std::to_string(i));
    }

    // sprite for matrix
    Sprite = sf::RectangleShape(sf::Vector2f(50, 50));
    Sprite.setFillColor( sf::Color(70, 100, 70) );
    Sprite.setPosition(-100, -100);

    // create matrix
    matrix = Matrix();

}

void MainState::render(){

    applicationWindow.draw(buttonsBar);
    resetButton.renderButton(applicationWindow);
    saveButton.renderButton(applicationWindow);
    resetButton.updateColor( sf::Mouse::getPosition(applicationWindow) );
    saveButton.updateColor( sf::Mouse::getPosition(applicationWindow) );
    applicationWindow.draw(Sprite);

    numberButton[0].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[0].renderButton(applicationWindow);
    numberButton[1].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[1].renderButton(applicationWindow);
    numberButton[2].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[2].renderButton(applicationWindow);
    numberButton[3].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[3].renderButton(applicationWindow);
    numberButton[4].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[4].renderButton(applicationWindow);
    numberButton[5].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[5].renderButton(applicationWindow);
    numberButton[6].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[6].renderButton(applicationWindow);
    numberButton[7].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[7].renderButton(applicationWindow);
    numberButton[8].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[8].renderButton(applicationWindow);
    numberButton[9].updateColor(sf::Mouse::getPosition(applicationWindow) );
    numberButton[9].renderButton(applicationWindow);

    applicationWindow.display();
}

void MainState::run(){

    matrix.resetMatrix();
    applicationWindow.clear( sf::Color(255, 255, 255) );
    sf::Event event;

    while( applicationWindow.isOpen() ){

        while( applicationWindow.pollEvent( event ) ){
            if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) ) {
                int mouseX = int(round(sf::Mouse::getPosition(applicationWindow).x / 50));
                int mouseY = int(round(sf::Mouse::getPosition(applicationWindow).y / 50));

                matrix.selectMatrix(Sprite, mouseX, mouseY );
            }
                // close application
                if( event.type == sf::Event::Closed ){
                    applicationWindow.close();
                 }
        }



        // reset button function
        if( resetButton.buttonPressed() ){
            matrix.resetMatrix();
            Sprite.setPosition( -100, -100 );
            applicationWindow.clear(sf::Color(255, 255, 255) );
        }

        // save button function
        if( saveButton.buttonPressed() ){

        }

        this->render();

    }



}