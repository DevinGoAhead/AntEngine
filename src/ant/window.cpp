#include "ant/Window.h"
#include "platform/WindowsWindow.h"
#include "memory"

namespace AE {
std::unique_ptr<Window> Window::CreateAEWindow(const WindowProp& winProp) {
#ifdef ANT_PLATFORM_WINDOWS 
    return std::make_unique<WindowsWindow>(winProp);
#elif defined (ANT_PLATFORM_LINUX)
    return std::make_unique<WindowsWindow>(winProp);
#endif
}
}  // namespace AE
