/*Unix framework -- mcursor.h
* Library for edit cursor in WM based on X11(if supported)
*/

#if defined(_WIN32)
#   error "Unsupported OS: please use Unix-like system"
#elif defined(__APPLE__) && defined(__MACH__)
#   pragma message("[Warning]: Work may be unstable on macOS")
#endif

#include <X11/Xlib.h>

Display *display = XOpenDisplay(nullptr);
Window root = DefaultRootWindow(display);

namespace CursorProperty
{
    void setPos(int x, int y);
    void Grab(int x, int y);
    void UnGrab();

    void SetIcon();
    void SetCursor();

    int getPosX();
    int getPosY();
}

