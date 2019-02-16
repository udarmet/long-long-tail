#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H


#include "../scheduler/Module.h"
#include "../model/Model.h"


class KeyboardController : public Module, public ModelControllerItf
{
public:

    void update(double dt) override;
};


#endif // KEYBOARD_CONTROLLER_H

