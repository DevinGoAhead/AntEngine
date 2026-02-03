#pragma once

#include "ant/Application.h"
#include "ant/Log.h"

//extern std::unique_ptr<AE::Application> AE::CreateApplication();

int main() {
    AE::Log::init();
    auto app = AE::CreateApplication();
    app->Run();
}