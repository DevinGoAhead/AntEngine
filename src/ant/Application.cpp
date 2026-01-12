#include "ant/Application.h"
#include <iostream>

namespace AE{
    void Application::Run(){
        int i = 0;
        while(true){
            sleep(1);
            std::cout << i++ << "\n";
            break;
        }

    }
}