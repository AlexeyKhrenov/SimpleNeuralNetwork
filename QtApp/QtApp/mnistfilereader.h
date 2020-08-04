#ifndef MNISTFILEREADER_H
#define MNISTFILEREADER_H

#include <iostream>
#include <fstream>


class MnistFileReader
{
public:
    MnistFileReader(const char* fileName);
    int maginNumber;
    int numberOfImages;
    int numberOfRows;
    int numberOfColumns;

    unsigned char* getNextImage();

private:
    std::ifstream source;
};

#endif // MNISTFILEREADER_H
