#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
    Model(void* callback());

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
    char* imageFile;
    char* labelFile;

    void setTrainingMode(bool isTrainingMode);
    void setStep(int step);
    void start();
    void selectImageFile(char* imageFile);
    void selectLabelFile(char* labelFile);

    char* warning;
private:

};

#endif // MODEL_H
