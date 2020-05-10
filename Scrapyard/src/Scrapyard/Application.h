//
// Created by Aryeh Zinn on 10/5/20.
//

#ifndef VULKANPRACTICE_APPLICATION_H
#define VULKANPRACTICE_APPLICATION_H

#include "stdio.h"

namespace Scrapyard {

    class Application {

    public:
        Application();
        ~Application();
        void run();
    };

    // To be defined in CLIENT.
    Application* CreateApplication();
}




#endif //VULKANPRACTICE_APPLICATION_H
