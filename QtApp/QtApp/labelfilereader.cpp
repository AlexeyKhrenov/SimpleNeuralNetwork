#include "labelfilereader.h"

#include <endian.h>>

LabelFileReader::LabelFileReader(const char* fileName)
{
    source = std::ifstream(fileName);

    // todo - throw exception is stream is not opened
    bool isopen = source.is_open();

    source.read((char *)&magicNumber, 4);
    source.read((char *)&numberOfLabels, 4);

    magicNumber = be32toh(magicNumber);
    numberOfLabels = be32toh(numberOfLabels);
}

char LabelFileReader::getNextLabel(){
    char result;
    source.read(&result, 1);
}
