#ifndef MODEL_CONTROLLER_ITF_H
#define MODEL_CONTROLLER_ITF_H


class Model;


class ModelControllerItf
{
public:

    void manipulate(Model& model);

protected:

    Model* m_model;
};


#endif // MODEL_CONTROLLER_ITF_H

