#ifndef MODEL_H
#define MODEL_H

#include <functional>
#include <mnistfilereader.h>
#include <labelfilereader.h>

class Model
{
public:
    Model(std::function<void()> callback, const char* imageFile, const char* labelFile);

    // image
    unsigned char* image;
    int imageHeight;
    int imageWidth;

    // AI
    char accuracy;
    char label;
    char detected;
    int step;
    bool isTrainingMode;

    // file
    int position;
    const char* imageFile;
    const char* labelFile;

    void setTrainingMode(bool isTrainingMode);
    void setStep(int step);
    void start();
    void selectImageFile(char* imageFile);
    void selectLabelFile(char* labelFile);

    char* warning;
private:
    MnistFileReader mnistFileReader;
    LabelFileReader labelFileReader;
};

#endif // MODEL_H
