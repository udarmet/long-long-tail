#include <iostream>
#include "common/model/Model.h"
#include "common/view/View.h"
#include "common/controller/KeyboardController.h"
#include "common/scheduler/ModulesSequence.h"
#include "common/scheduler/Scheduler.h"


int main(int argc, char* argv[])
{
    try {
        Model model;

        View view;
        view.observe(model);

        KeyboardController controller;
        controller.manipulate(model);

        ModulesSequence game;
        game.append(controller);
        game.append(model);
        game.append(view);

        Scheduler scheduler;
        scheduler.addPeriodicModule(game, 1 / 60.0);
        return scheduler.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}

