#pragma once

#include "Application.h"
#include "ant/Log.h"

extern std::unique_ptr<AT::Application> AT::CreateApplication();

int main(){
    AT::Log::init();
    auto app = AT::CreateApplication();
    app->Run();
    ANT_CORE_TRACE("trace information");
    ANT_INFO("INFO information");
}