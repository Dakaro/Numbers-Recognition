#include "Matrix.hpp"


void Matrix::resetMatrix() {
    for( int i=0; i < 17; ++i ){
        for( int j = 0; j < 17; ++j )
        {
            Matrix::pixel[i][j] = 0;
        }
    }
}

Matrix::Matrix(){
    Matrix::resetMatrix();
}