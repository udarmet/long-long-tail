#ifndef MODEL_H
#define MODEL_H


#include <vector>
#include "Module.h"
#include "ModelObserverItf.h"
#include "ModelControllerItf.h"


class Model : public Module
{
public:

    void loop() override;

protected:

    std::vector<ModelObserverItf*> m_observers;

    friend class ModelObserverItf;
    friend class ModelControllerItf;
};


#endif // MODEL_H
