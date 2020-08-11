#include <model.h>
#include <functional>
#include <mnistfilereader.h>
#include <labelfilereader.h>

Model::Model(std::function<void()> callback, const char* imageFile, const char* labelFile)
    : mnistFileReader(imageFile), labelFileReader(labelFile)
{
    this->imageFile = imageFile;
    this->labelFile = labelFile;

    if(!mnistFileReader.isOpen){
        warning = "Couldn't open image file \n";
    }

    if(!labelFileReader.isOpen){
        warning = "Couldn't open label file \n";
    }
}
