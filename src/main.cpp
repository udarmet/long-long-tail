#include <iostream>
#include "common/Model.h"
#include "common/View.h"
#include "common/KeyboardController.h"
#include "common/ModulesSequence.h"
#include "common/Scheduler.h"


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

