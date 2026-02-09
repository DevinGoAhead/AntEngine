#include "platform/opengl/OpenGLContext.h"
#include "ant/Ant.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


namespace AE {
OpenGLContext::OpenGLContext(GLFWwindow* inWindow) : window(inWindow) {
    ANT_CORE_ASSERT(window, "window is null")
}

void OpenGLContext::Initial() {
    glfwMakeContextCurrent(window);
    auto status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    ANT_CORE_ASSERT(status, "LoadGLLoader failed!");
}

void OpenGLContext::Swapbuffers() {
    glfwSwapBuffers(window);
}

}  // namespace AE
