#ifndef MNISTFILEREADER_H
#define MNISTFILEREADER_H

#include <fstream>


class MnistFileReader
{
public:
    MnistFileReader(const char* fileName);
    int magicNumber;
    int numberOfImages;
    int numberOfRows;
    int numberOfColumns;

    void getNextImage(char* target);

private:
    std::ifstream source;
    int imageLength;
};

#endif // MNISTFILEREADER_H
