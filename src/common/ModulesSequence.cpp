#include "ModulesSequence.h"


bool ModulesSequence::setup()
{
    for (auto module : m_modules) {
        if (!module->setup()) {
            return false;
        }
    }
    return true;
}


void ModulesSequence::loop()
{
    for (auto module : m_modules) {
        module->loop();
    }
}


void ModulesSequence::teardown()
{
    for (auto module : m_modules) {
        module->teardown();
    }
}


void ModulesSequence::append(ModuleItf& module)
{
    m_modules.push_back(&module);
}

