#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "../../src/common/Module.h"
#include "../../src/common/Scheduler.h"


class CuckooClock : public Module
{
public:

    CuckooClock(const std::string name) : m_name(name) {}

    void loop() override
    {
        std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
        std::time_t now_c = std::chrono::system_clock::to_time_t(now);
        std::tm* tmb = std::localtime(&now_c);
        std::cout << "[" << std::put_time(tmb, "%H:%M:%S") << "] ";
        std::cout << "[" << m_name << "] ";
        std::cout << "Cuckoo!!" << std::endl;
    }

protected:

    std::string m_name;
};


int main(int argc, char* argv[])
{
    try {
        CuckooClock cuckooEverySecond("Cuckoo clock #1");
        CuckooClock cuckooEvery2Seconds("Cuckoo clock #2");
        CuckooClock cuckooEvery3Seconds("Cuckoo clock #3");

        Scheduler scheduler;
        scheduler.addPeriodicModule(cuckooEverySecond, 1.0);
        scheduler.addPeriodicModule(cuckooEvery2Seconds, 2.0);
        scheduler.addPeriodicModule(cuckooEvery3Seconds, 3.0);
        return scheduler.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}

