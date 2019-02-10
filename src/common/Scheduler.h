#ifndef SCHEDULER_H
#define SCHEDULER_H


#include "ModuleItf.h"


class Scheduler
{
public:

    void addPeriodicModule(ModuleItf& module, double timestep, bool inNewThread=false);

    int run();

protected:

    friend class ModuleItf;
};


#endif // SCHEDULER_H

