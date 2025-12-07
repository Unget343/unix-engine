#pragma once

#include <cstdlib>
using namespace std;

#if defined(_WIN32)
#       define UXFRAME_OS_WIN
#       define BASE_GRAPHIC "dwm"
#       include <Windows.h>
#elif defined(__APPLE__)
#       define UXFRAME_OS_APPLE
#       define BASE_GRAPHIC "qartz"
#elif defined(__linux__)
#       define UXFRAME_OS_BASE
        const char graphics = getenv("GRAPH_MODE");
        if (graphics != nullptr && strcmp(graphics, "xcb") == 0)
        {
#           define BASE_GRAPHIC "xcb"
        } else if (graphics != nullptr && strcmp(graphics, "wayland") == 0)
        {
#           define BASE_GRAPHIC "wayland"
        }

#endif // _WIN32

typedef long int  WSize;
typedef signed char WTitle;

#ifndef BASE_GRAPHIC == "xcb"
#       include <X11/Xlib.h>
#elif defined(BASE_GRAPHIC) == "wayland"
#       include <wayland-client.h>
#       include <wayland-server.h>
#elif defined(BASE_GRAPHIC) == "qartz"
#       include <CoreGraphics/CoreGraphics.h>
#endif // BASE_GRAPHIC
