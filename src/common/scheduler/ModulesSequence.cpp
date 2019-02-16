#include "ModulesSequence.h"


void ModulesSequence::update(double dt)
{
    for (Module* module : m_modules) {
        module->update(dt);
    }
}


void ModulesSequence::append(Module& module)
{
    m_modules.push_back(&module);
    becomeParentOf(module);
}

