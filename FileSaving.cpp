#include "FileSaving.hpp"
#include <string>
#include <fstream>

void saveFile(int number, const Matrix &matrix ){
    std::fstream file;
    file.open("output/" + std::to_string(number) + ".txt", std::ios::out | std::ios::app );

    file << "\n \n";
    for( int i = 0; i < 8; ++i ){
        for( int j = 0; j < 8; ++j){
            file << matrix.pixel[j][i] << " ";
        }
        file << "\n";
    }

    file.close();
}