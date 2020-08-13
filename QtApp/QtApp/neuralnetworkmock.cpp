#include "neuralnetworkmock.h"
#include "stdlib.h"

NeuralNetworkmock::NeuralNetworkmock()
{
}

char NeuralNetworkmock::RecognizeImage(char *image){
    char result = rand() % 9 + 1;
    return result;
}

char NeuralNetworkmock::RecognizeAndTrain(char* image, char answer){
    return RecognizeImage(image);
}
