#include "Matrix.hpp"

void Matrix::resetMatrix() {
    for( int i=0; i < 17; ++i ){
        for( int j = 0; j < 17; ++j )
        {
            pixel[i][j] = 0;
        }
    }
}