#include "ant/Application.h"
#include "ant/EntryPoint.h" // IWYU pragma: keep

class ANT_API SandboxApp : public AE::Application{
public:
    SandboxApp() = default;
    ~SandboxApp() override = default ;
};


namespace AE{
    std::unique_ptr<Application> CreateApplication(){
        return std::make_unique<Application>();
    }
}
