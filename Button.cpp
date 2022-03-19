#include "Button.hpp"
#include <SFML/Graphics.hpp>

Button::Button(sf::Vector2f Pos, sf::Vector2f Size,sf::Color activeColor,sf::Color defaultColor,sf::Color hoverColor)
{
this->Pos = Pos;
this->Size = Size;
shape = sf::CircleShape ( Size.y ) ;
shape.setFillColor( defaultColor );
shape.setPosition( Pos );
this->activeColor = activeColor;
this->defaultColor = defaultColor;
this->hoverColor = hoverColor;
button_state = DEFAULT;
}

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

sf::CircleShape Button::getShape()
{
    return shape;
}

bool Button::buttonPressed()
{
    if( button_state == ACTIVE )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

