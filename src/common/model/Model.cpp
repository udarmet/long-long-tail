#include "Model.h"


void ModelObserverItf::observe(Model& model)
{
    model.m_observers.push_back(this);
}


void ModelControllerItf::manipulate(Model &model)
{
    m_model = &model;
}


void Model::update(double dt)
{
}

