#include <model.h>
#include <functional>
#include <mnistfilereader.h>
#include <labelfilereader.h>

Model::Model(std::function<void()> callback, const char* imageFile, const char* labelFile, INeuralNetwork* ai)
    : mnistFileReader(imageFile), labelFileReader(labelFile)
{
    this->imageFile = imageFile;
    this->labelFile = labelFile;
    this->callback = callback;
    this->ai = ai;

    warning = "Everything's ok";

    if(!mnistFileReader.isOpen){
        warning = "Couldn't open image file \n";
        return;
    }

    if(!labelFileReader.isOpen){
        warning = "Couldn't open label file \n";
        return;
    }

    isTestingMode = false;

    position = 0;
    errorNum = 0;
    step = 1;

    start();
}

void Model::setTrainingMode(bool isTestingMode){
    if(this->isTestingMode != isTestingMode){
        this->isTestingMode = isTestingMode;
        warning = "Training/testing mode changed";
        callback();

        // todo - add some neurologic here
    }
}

void Model::setStep(int step){
    if(this->step != step){
        this->step = step;
        warning = "Step changed";
        callback();

        // todo - add some neurologic here
    }
}

void Model::start(){

    if(position >= mnistFileReader.numberOfImages -1){
        warning = "Reached the end of the dataset sequence";
        callback();
        return;
    }

    if(position + step > mnistFileReader.numberOfImages){
        warning = "Step is too large";
        callback();
        return;
    }

    for(int i = 0; i < step; i++){
        label = labelFileReader.getNextLabel();
        mnistFileReader.getNextImage(image);

        if(isTestingMode){
            detected = ai->RecognizeImage(image);
        }
        else{
            detected = ai->RecognizeAndTrain(image, label);
        }

        if(label != detected){
            errorNum++;
        }

        accuracy = 100 - errorNum * 100/ (position + 1);

        position++;
    }

    warning = "Finished";
    callback();
}
