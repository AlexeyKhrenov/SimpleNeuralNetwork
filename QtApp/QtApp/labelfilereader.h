#ifndef LABELFILEREADER_H
#define LABELFILEREADER_H

#include <fstream>

class LabelFileReader
{
public:
    LabelFileReader(const char* fileName);

    int magicNumber;
    int numberOfLabels;

    char getNextLabel();

    bool isOpen;

private:
    std::ifstream source;
};

#endif // LABELFILEREADER_H
