#include "mnistfilereader.h"

#include <fstream>

MnistFileReader::MnistFileReader(const char* fileName)
{
    source = std::ifstream(fileName);

    // todo - check if stream is opened
}

unsigned char*  MnistFileReader:: getNextImage(){
    char c = source.get();
    while (ifs.good()) {
      std::cout << c;
      c = ifs.get();
    }
}
