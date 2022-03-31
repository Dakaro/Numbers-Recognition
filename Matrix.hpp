#ifndef NUMBERSRECOGNITION_MATRIX_HPP
#define NUMBERSRECOGNITION_MATRIX_HPP

#include <SFML/Graphics.hpp>

class Matrix{
public:
    int pixel[17][17];

    Matrix();
    void resetMatrix();
    void selectMatrix(sf::RectangleShape & Sprite, int mouseX, int mouseY );

};

#endif //NUMBERSRECOGNITION_MATRIX_HPP
