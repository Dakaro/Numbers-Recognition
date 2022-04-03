#ifndef NUMBERSRECOGNITION_BUTTON_HPP
#define NUMBERSRECOGNITION_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <cstring>

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

    sf::Font font;
    sf::Text text = sf::Text("", font);

    sf::CircleShape shape;

public:

    Button();
    Button(sf::Vector2f Pos, sf::Vector2f Size,sf::Color activeColor,sf::Color defaultColor,sf::Color hoverColor, std::string text = "");
    ~Button();
    void updateColor(sf::Vector2i mousePos  );
    void renderButton(sf::RenderWindow &target);
    bool buttonPressed();
    sf::Text setText(std::string text, sf::Font setFont, int size = 0, float xPos = 0, float yPos = 0, sf::Color color = sf::Color::Black);
};



#endif //NUMBERSRECOGNITION_BUTTON_HPP
