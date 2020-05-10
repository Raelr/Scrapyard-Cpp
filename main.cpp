#include "Sandbox.h"

int main() {
    auto* app = new SandboxApp;
    app->run();
    delete app;
    return 0;
}
