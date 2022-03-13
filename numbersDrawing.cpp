#include <SFML/Graphics.hpp>
#include <cmath>

bool pixel[17][17];

void resetMatrix()
{
    for( int i=0; i < 17; ++i ){
        for( int j = 0; j < 17; ++j )
        {
            pixel[i][j] = 0;
        }
    }
}

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



    Button(sf::Vector2f Pos, sf::Vector2f Size,sf::Color activeColor,sf::Color defaultColor,sf::Color hoverColor)
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


    /// Update color

    void updateColor(sf::Vector2i mousePos  )
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

    sf::CircleShape getShape()
    {
        return shape;
    }

    bool buttonPressed()
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


};



int main()
{

    sf::RectangleShape buttonsBar( sf::Vector2f( 50, 800 ) );
    buttonsBar.setFillColor( sf::Color(100, 100, 100) );

    Button resetButton(sf::Vector2f(4,7), sf::Vector2f(20,20) ,
                     sf::Color(214, 179, 126) ,
                     sf::Color(214, 166, 53) ,
                     sf::Color(214, 173, 78)  );

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



        applicationWindow.draw(buttonsBar);
        applicationWindow.draw(resetButton.getShape());
        resetButton.updateColor( sf::Mouse::getPosition(applicationWindow) );
        applicationWindow.draw(Sprite);
        applicationWindow.display();


        /* I don't use inheritance, because I have only two buttons */

        if( resetButton.buttonPressed() ){
            resetMatrix();
            Sprite.setPosition( -100, -100 );
            applicationWindow.clear(sf::Color(255, 255, 255) );
        }


    }
    return 0;
}