#ifndef VIEW_H
#define VIEW_H


#include "Module.h"
#include "ModelObserverItf.h"


class View : public Module, public ModelObserverItf
{
public:

    void loop() override;
};


#endif // VIEW_H

