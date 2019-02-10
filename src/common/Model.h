#ifndef MODEL_H
#define MODEL_H


#include <vector>
#include "ModuleItf.h"
#include "ModelObserverItf.h"
#include "ModelControllerItf.h"


class Model : public ModuleItf
{
protected:

    std::vector<ModelObserverItf*> m_observers;

    friend class ModelObserverItf;
    friend class ModelControllerItf;
};


#endif // MODEL_H

