#pragma once

#include "Application.h"
#include "Log.h"

//extern std::unique_ptr<AE::Application> AE::CreateApplication();

int main(){
    AE::Log::init();
    auto app = AE::CreateApplication();
     ANT_LOG_CORE_TRACE("trace information");
    ANT_LOG_INFO("INFO information");
    app->Run();
    ANT_LOG_CORE_TRACE("trace information");
    ANT_LOG_INFO("INFO information");
}