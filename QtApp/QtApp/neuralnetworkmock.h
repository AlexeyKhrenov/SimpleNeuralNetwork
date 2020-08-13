#ifndef NEURALNETWORKMOCK_H
#define NEURALNETWORKMOCK_H

#include <ineuralnetwork.h>

class NeuralNetworkmock : public INeuralNetwork
{
public:
    NeuralNetworkmock();
    //virtual ~NeuralNetworkmock();// todo - add desctructor
    virtual char RecognizeImage(char* image);
    virtual char RecognizeAndTrain(char* image, char answer);
};

#endif // NEURALNETWORKMOCK_H
