#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H


#include "Module.h"
#include "ModelControllerItf.h"


class KeyboardController : public Module, public ModelControllerItf
{
public:

    void loop() override;
};


#endif // KEYBOARD_CONTROLLER_H

