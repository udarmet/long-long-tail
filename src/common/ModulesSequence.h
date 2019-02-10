#ifndef MODULES_SEQUENCE_H
#define MODULES_SEQUENCE_H


#include <vector>
#include "ModuleItf.h"


class ModulesSequence : public ModuleItf
{
public:

    bool setup() override;
    void loop() override;
    void teardown() override;

    void append(ModuleItf& module);

protected:

    std::vector<ModuleItf*> m_modules;
};


#endif // MODULES_SEQUENCE_H

