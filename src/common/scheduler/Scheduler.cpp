#include "Scheduler.h"


bool Scheduler::PeriodicModuleData::ComparePtr::operator()(const PeriodicModuleData* left, const PeriodicModuleData* right)
{
    return left->deadline > right->deadline;
}


Scheduler::Scheduler() :
    m_isRunning(false)
{
}


void Scheduler::addPeriodicModule(Module& module, double period)
{
    PeriodicModuleData periodicModule;
    periodicModule.module = &module;
    periodicModule.period = std::chrono::nanoseconds(static_cast<long>(period * 1e9));
    m_periodicModules.push_back(periodicModule);
    becomeParentOf(module);
}


int Scheduler::run()
{
    init();
    m_isRunning = true;
    while (m_isRunning) {
        update(-1);
    }
    return 0;
}


void Scheduler::init()
{
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    for (PeriodicModuleData& periodicModule : m_periodicModules) {
        periodicModule.deadline = now;
        m_periodicModulesSequencer.push(&periodicModule);
    }
}


void Scheduler::update(double)
{
    PeriodicModuleData* nextModulePtr = m_periodicModulesSequencer.top();
    std::this_thread::sleep_until(nextModulePtr->deadline);
    nextModulePtr->module->update(nextModulePtr->period.count() * 1e-9);
    nextModulePtr->deadline += nextModulePtr->period;
    m_periodicModulesSequencer.pop();
    m_periodicModulesSequencer.push(nextModulePtr);
}


void Scheduler::handleSignal(Signal signal)
{
    if (signal == EXIT) {
        m_isRunning = false;
    }
}

