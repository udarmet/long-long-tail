#include "Module.h"


void Module::propagateSignal(Signal signal)
{
    if (m_parent != nullptr) {
        m_parent->handleSignal(signal);
    }
}


void Module::becomeParentOf(Module& child)
{
    child.m_parent = this;
}

