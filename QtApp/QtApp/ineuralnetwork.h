#ifndef INEURALNETWORK_H
#define INEURALNETWORK_H


class INeuralNetwork
{
public:
    virtual ~INeuralNetwork() { }
    virtual char RecognizeImage(char* image) = 0;
    virtual char RecognizeAndTrain(char* image, char answer) = 0;
};

#endif // INEURALNETWORK_H
