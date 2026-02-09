#pragma once

#include "ant/Core.h"
#include "ant/render/GraphicsContext.h"

struct GLFWwindow;

namespace AE {
class OpenGLContext : public GraphicsContext {
   public:
    OpenGLContext(GLFWwindow* inWindow);

    void Initial() override;
    void Swapbuffers() override;

   private:
    GLFWwindow* window;
};
}  // namespace AE