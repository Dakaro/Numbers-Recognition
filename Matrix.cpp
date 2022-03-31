#include "Matrix.hpp"


void Matrix::resetMatrix() {
    for( int i=0; i < 17; ++i ){
        for( int j = 0; j < 17; ++j )
        {
            Matrix::pixel[i][j] = 0;
        }
    }
}

void Matrix::selectMatrix (sf::RectangleShape &Sprite, int mouseX, int mouseY) {
    if (pixel[mouseX][mouseY] == 0 && mouseX*50 >= 50 ) {
        pixel[mouseX][mouseY] = 1;
        Sprite.setPosition(mouseX * 50, mouseY * 50);
        Sprite.setFillColor( sf::Color((mouseX*50)%255, 34, 98));
    }
}

Matrix::Matrix(){
    Matrix::resetMatrix();
}