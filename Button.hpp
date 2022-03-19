#ifndef NUMBERSRECOGNITION_BUTTON_HPP
#define NUMBERSRECOGNITION_BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button
{
private:

    enum BUTTON_STATES { DEFAULT = 0, ACTIVE, HOVER };

    int button_state;

    sf::Color activeColor;
    sf::Color defaultColor;
    sf::Color hoverColor;

    sf::Vector2f Pos;
    sf::Vector2f Size;

    sf::CircleShape shape;

public:

    Button(sf::Vector2f Pos, sf::Vector2f Size,sf::Color activeColor,sf::Color defaultColor,sf::Color hoverColor);
    ~Button();
    void updateColor(sf::Vector2i mousePos  );
    sf::CircleShape getShape();
    bool buttonPressed();
};



#endif //NUMBERSRECOGNITION_BUTTON_HPP
