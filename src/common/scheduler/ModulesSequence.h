#ifndef MODULES_SEQUENCE_H
#define MODULES_SEQUENCE_H


#include <vector>
#include "Module.h"


class ModulesSequence : public Module
{
public:

    void loop() override;

    void append(Module& module);

protected:

    std::vector<Module*> m_modules;
};


#endif // MODULES_SEQUENCE_H

