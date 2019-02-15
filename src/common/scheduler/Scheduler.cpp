#include "Scheduler.h"


Scheduler::PeriodicModuleData::PeriodicModuleData(Module& module_, double period_) :
    module(&module_),
    period(static_cast<long>(period_ * 1e9))
{
}


bool Scheduler::PeriodicModuleData::Compare::operator()(const PeriodicModuleData* left, const PeriodicModuleData* right)
{
    return (left->last + left->period) > (right->last + right->period);
}


Scheduler::Scheduler() :
    m_isRunning(false)
{
}


void Scheduler::addPeriodicModule(Module& module, double period)
{
    m_periodicModules.emplace_back(module, period);
    becomeParentOf(module);
}


int Scheduler::run()
{
    setup();
    m_isRunning = true;
    while (m_isRunning) {
        loop();
    }
    return 0;
}


void Scheduler::setup()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    for (PeriodicModuleData& periodicModule : m_periodicModules) {
        periodicModule.last = now - periodicModule.period;
        m_periodicModulesSequencer.push(&periodicModule);
    }
}


void Scheduler::loop()
{
    PeriodicModuleData* pmodule = m_periodicModulesSequencer.top();
    std::this_thread::sleep_until(pmodule->last + pmodule->period);
    pmodule->module->loop();
    pmodule->last += pmodule->period;
    m_periodicModulesSequencer.pop();
    m_periodicModulesSequencer.push(pmodule);
}


void Scheduler::handleSignal(Signal signal)
{
    if (signal == EXIT) {
        m_isRunning = false;
    }
}

