//
// Created by Aryeh Zinn on 9/5/20.
//

#ifndef VULKANPRACTICE_HELLOTRIANGLEAPPLICATION_H
#define VULKANPRACTICE_HELLOTRIANGLEAPPLICATION_H

#include <vulkan/vulkan.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class HelloTriangleApplication {

public:
    void run();
private:
    void init_vulkan();
    void main_loop();
    void cleanup();
};


#endif //VULKANPRACTICE_HELLOTRIANGLEAPPLICATION_H
