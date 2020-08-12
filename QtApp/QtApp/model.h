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
    char image[28*28];
    int imageHeight;
    int imageWidth;

    // AI
    char accuracy;
    char label;
    char detected;
    int step;
    bool isTestingMode;

    // file
    int position;
    const char* imageFile;
    const char* labelFile;

    void setTrainingMode(bool isTestingMode);
    void setStep(int step);
    void start();
    void selectImageFile(char* imageFile);
    void selectLabelFile(char* labelFile);

    char* warning;
private:
    MnistFileReader mnistFileReader;
    LabelFileReader labelFileReader;
    std::function<void()> callback;
};

#endif // MODEL_H
