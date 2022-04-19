#ifndef NUMBERSDRAWING_CPP_MENUSTATE_H
#define NUMBERSDRAWING_CPP_MENUSTATE_H

#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include "Matrix.hpp"
#include "FileSaving.hpp"

class MainState{

private:
    sf::RectangleShape buttonsBar;
    Button resetButton;
    Button saveButton;
    Button numberButton[10];
    Matrix matrix;
    sf::RectangleShape Sprite;
    sf::Font font;
    int selectedNumber = -1;

public:
    sf::RenderWindow applicationWindow = sf::RenderWindow( sf::VideoMode( 450, 400, 32 ), "Numbers Drawing" );;
    MainState();
    void render();
    void run();


};


#endif //NUMBERSDRAWING_CPP_MENUSTATE_H
