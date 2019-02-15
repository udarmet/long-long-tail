#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <chrono>
#include <vector>
#include <queue>
#include <list>
#include <thread>
#include <atomic>
#include "Module.h"


class Scheduler : public Module
{
public:

    Scheduler();

    void addPeriodicModule(Module& module, double period);
    void addThreadedModule(Module& module);  // Not implemented

    int run();

protected:

    struct PeriodicModuleData
    {
        PeriodicModuleData(Module& module_, double period_);

        struct Compare {
            bool operator()(const PeriodicModuleData* left, const PeriodicModuleData* right);
        };

        Module* module;
        std::chrono::nanoseconds period;
        std::chrono::steady_clock::time_point last;
    };

    void setup();
    void loop() override;

    void handleSignal(Signal signal) override;

    std::vector<PeriodicModuleData> m_periodicModules;
    std::priority_queue<
        PeriodicModuleData*,
        std::vector<PeriodicModuleData*>,
        PeriodicModuleData::Compare> m_periodicModulesSequencer;
    std::atomic_bool m_isRunning;
};


#endif // SCHEDULER_H

