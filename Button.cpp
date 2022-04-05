#include "Button.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Button::Button(sf::Vector2f Pos, sf::Vector2f Size,sf::Color activeColor,sf::Color defaultColor,sf::Color hoverColor, std::string renderText)
{
this->Pos = Pos;
this->Size = Size;

shape = sf::CircleShape ( Size.y ) ;
shape.setFillColor( defaultColor );
shape.setPosition( Pos );

this->activeColor = activeColor;
this->defaultColor = defaultColor;
this->hoverColor = hoverColor;

    if( !font.loadFromFile("fonts/FredokaOne-Regular.ttf") ){
        std::cout << "NIE ZALADOWANO" << std::endl;
    }
    else{
        std::cout << "udalo sie" << std::endl;
    }

this->text.setFont(font);
this->text.setString(renderText);

// DEFAULT BUTTON COLOR
this->text.setFillColor(sf::Color(200, 200, 200));


button_state = DEFAULT;
}

Button::Button(){};

Button::~Button(){}



void Button::updateColor(sf::Vector2i mousePos  )
{
    button_state = DEFAULT;
    if( shape.getGlobalBounds().contains( sf::Vector2f (mousePos) ) ){
        button_state = HOVER;
        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
        {
            button_state = ACTIVE;
        }
    }

    switch (button_state)
    {
        case DEFAULT:
            shape.setFillColor(defaultColor);
            break;

        case ACTIVE:
            shape.setFillColor(activeColor);
            break;

        case HOVER:
            shape.setFillColor(hoverColor);
            break;
    }

}

void Button::renderButton(sf::RenderWindow &target)
{

    target.draw(shape);

    sf::Text renderText;
    renderText.setString(this->text.getString());
    renderText.setFont(font);
    renderText.setFillColor(this->text.getFillColor());
    renderText.setPosition(this->Pos.x + 5, this->Pos.y - 5);
    target.draw(renderText);
}

bool Button::buttonPressed()
{
    if( button_state == ACTIVE )
    {
        return true;
    }
    else
    {
        return false;
    }
}


sf::Text Button::setText(std::string text, sf::Font setFont, int size, float xPos, float yPos, sf::Color color) {
    sf::Text renderText{text, setFont};
    renderText.setPosition(xPos, yPos);
    renderText.setFillColor(color);
    renderText.setCharacterSize(size);
    return renderText;
}
