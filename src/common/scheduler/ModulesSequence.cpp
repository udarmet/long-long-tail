#include "ModulesSequence.h"


void ModulesSequence::loop()
{
    for (Module* module : m_modules) {
        module->loop();
    }
}


void ModulesSequence::append(Module& module)
{
    m_modules.push_back(&module);
    becomeParentOf(module);
}

