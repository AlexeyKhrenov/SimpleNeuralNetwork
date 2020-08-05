#include <model.h>

Model::Model(void (*callback)())
{
    warning = "No files are selected yet";
    callback();
}


