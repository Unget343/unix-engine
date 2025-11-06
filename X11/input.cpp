#include "input.h"
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <string>

using namespace std;

Display* display = XOpenDisplay(nullptr);
if (!display) { return; }

bool check_Xkey(const string& key, KeySym keysym)
{
    const char* sym_str = XKeysymToString(keysym);
    if (!sym_str) return false;
    return key == sym_str;
}

bool getkey(const string& key)
{
    XEvent event;
    XNextEvent(display, &event);

    if (event.type == KeyPress)
    {
        KeySym keysym = XLookupKeysym(&event.xkey, 0);
        return check_Xkey(key, keysym);
    }

    return false;
}

bool keyrelease(const string& key)
{
    XEvent event;
    XNextEvent(display, &event);

    if (event.type == KeyRelease)
    {
        KeySym keysym = XLookupKeysym(&event.xkey, 0);
        return check_Xkey(key, keysym);
    }

    return false;
}
