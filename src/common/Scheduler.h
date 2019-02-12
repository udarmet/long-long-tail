#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <chrono>
#include <queue>
#include <thread>
#include <atomic>
#include "Module.h"


class Scheduler : public Module
{
public:

    Scheduler();

    void loop() override;

    void addPeriodicModule(Module& module, double period);
    void addThreadedModule(Module& module);  // Not implemented

    int run();

protected:

    struct PeriodicModuleData
    {
        PeriodicModuleData(Module& module_, double period_);
        bool operator<(const PeriodicModuleData& other) const;

        Module* module;
        std::chrono::nanoseconds period;
        std::chrono::steady_clock::time_point last;
    };

    void handleSignal(Signal signal) override;

    std::priority_queue<PeriodicModuleData> m_periodicModules;
    std::atomic_bool m_isRunning;
};


#endif // SCHEDULER_H

