/*  Copyright (C) 2025 UnixSD

   This file is part of Unix Engine.

   Unix Engine is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Unix Engine is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Unix Engine.  If not, see <http://www.gnu.org/licenses/>.
*/

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
