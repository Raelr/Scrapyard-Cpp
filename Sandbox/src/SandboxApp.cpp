#include <Scrapyard.h>

class SandBoxApp : public Scrapyard::Application {
    
public: 
    SandBoxApp() {

    }

    ~SandBoxApp() {

    }
};


Scrapyard::Application * Scrapyard::CreateApplication() {
    return new SandBoxApp;
}





