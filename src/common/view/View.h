#ifndef VIEW_H
#define VIEW_H


#include "../scheduler/Module.h"
#include "../model/Model.h"


class View : public Module, public ModelObserverItf
{
public:

    void update(double dt) override;
};


#endif // VIEW_H

