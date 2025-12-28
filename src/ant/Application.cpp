#include "ant/Application.h"
#include <iostream>
#include <thread>

namespace AT{
    void Application::Run(){
        int i = 0;
        while(true){
            sleep(1);
            std::cout << i++ << "\n";
        }

    }
}