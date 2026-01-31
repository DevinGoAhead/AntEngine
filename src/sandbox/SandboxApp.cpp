#include "ant/Ant.h"

class SandboxApp : public AE::Application{
public:
    SandboxApp() = default;
    ~SandboxApp() override = default ;
};


namespace AE{
    std::unique_ptr<Application> CreateApplication(){
        return std::make_unique<Application>();
    }
}
