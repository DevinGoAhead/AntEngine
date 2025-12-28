#include "ant/Application.h"
#include "ant/EntryPoint.h"

class ANT_API SandboxApp : public AT::Application{
public:
    SandboxApp() = default;
    virtual ~SandboxApp() = default;
};


namespace AT{
    std::unique_ptr<Application> CreateApplication(){
        return std::make_unique<Application>();
    }
}
