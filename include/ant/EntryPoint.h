#pragma once

#include "Application.h"

extern std::unique_ptr<AT::Application> AT::CreateApplication();

int main(){
    auto app = AT::CreateApplication();
    app->Run();
}