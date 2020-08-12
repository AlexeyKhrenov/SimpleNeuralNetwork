#include <model.h>
#include <functional>
#include <mnistfilereader.h>
#include <labelfilereader.h>

Model::Model(std::function<void()> callback, const char* imageFile, const char* labelFile)
    : mnistFileReader(imageFile), labelFileReader(labelFile)
{
    this->imageFile = imageFile;
    this->labelFile = labelFile;
    this->callback = callback;

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

    label = labelFileReader.getNextLabel();

    char *p;
    p = image;
    mnistFileReader.getNextImage(p);
    position = 0;
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
    warning = "Started";
    callback();

    // todo - add some neurologic here
}
