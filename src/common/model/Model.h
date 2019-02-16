#ifndef MODEL_H
#define MODEL_H


#include <vector>
#include "../scheduler/Module.h"


class Model;


class ModelObserverItf
{
public:

    void observe(Model& model);
};


class ModelControllerItf
{
public:

    void manipulate(Model& model);

protected:

    Model* m_model;
};


class Model : public Module
{
public:

    void update(double dt) override;

protected:

    std::vector<ModelObserverItf*> m_observers;

    friend class ModelObserverItf;
    friend class ModelControllerItf;
};


#endif // MODEL_H

