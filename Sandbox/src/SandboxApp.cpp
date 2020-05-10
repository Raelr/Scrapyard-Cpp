//
// Created by Aryeh Zinn on 10/5/20.
//

#include "SandboxApp.h"

SandboxApp::SandboxApp() {

}

SandboxApp::~SandboxApp() {

}

Scrapyard::Application * Scrapyard::CreateApplication() {
    return new SandboxApp;
}