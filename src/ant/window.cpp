#include "ant/Window.h"
#include "ant/platform/WindowWindow.h"
#include "memory"

namespace AE {
std::unique_ptr<Window> Window::CreateWindow(const WindowProp& winProp) {
#ifdef ANT_PLATFORM_WINDOWS 
    return std::make_unique<WindowWindow>(winProp);
#elif defined (ANT_PLATFORM_LINUX)
    return std::make_unique<WindowWindow>(winProp);
#endif
}
}  // namespace AE
