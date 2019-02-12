#include "Scheduler.h"


Scheduler::PeriodicModuleData::PeriodicModuleData(Module& module_, double period_) :
    module(&module_),
    period(static_cast<long>(period_ * 1e9)),
    last(std::chrono::steady_clock::now() - period)
{
}


bool Scheduler::PeriodicModuleData::operator<(const PeriodicModuleData& other) const
{
    return (last + period) >= (other.last + other.period);
}


Scheduler::Scheduler() :
    m_isRunning(false)
{
}


void Scheduler::addPeriodicModule(Module& module, double period)
{
    m_periodicModules.emplace(module, period);
    becomeParentOf(module);
}


void Scheduler::loop()
{
    PeriodicModuleData pmodule = m_periodicModules.top();
    std::this_thread::sleep_until(pmodule.last + pmodule.period);
    pmodule.module->loop();
    pmodule.last += pmodule.period;
    m_periodicModules.pop();
    m_periodicModules.push(pmodule);
}


int Scheduler::run()
{
    m_isRunning = true;
    while (m_isRunning) {
        loop();
    }
    return 0;
}


void Scheduler::handleSignal(Signal signal)
{
    if (signal == EXIT) {
        m_isRunning = false;
    }
}

