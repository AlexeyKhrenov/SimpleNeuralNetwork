#include "mnistfilereader.h"

#include <fstream>
#include <endian.h>

MnistFileReader::MnistFileReader(const char* fileName)
{
    source = std::ifstream(fileName);

    // todo - throw exception is stream is not opened
    bool isopen = source.is_open();

    source.read((char *)&magicNumber, 4);
    source.read((char *)&numberOfImages, 4);
    source.read((char *)&numberOfRows, 4);
    source.read((char *)&numberOfColumns, 4);

    magicNumber = be32toh(magicNumber);
    numberOfImages = be32toh(numberOfImages);
    numberOfRows = be32toh(numberOfRows);
    numberOfColumns = be32toh(numberOfColumns);
    imageLength = numberOfRows * numberOfColumns;
}

void MnistFileReader:: getNextImage(char* target){
    source.read(target, imageLength);
}

// todo - add disposing of file stream

