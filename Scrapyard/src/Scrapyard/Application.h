#ifndef APPLICATION_H
#define APPLICATION_H

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




#endif
