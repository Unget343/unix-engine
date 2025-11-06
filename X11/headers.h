#ifndef HEADERS_H
#define HEADERS_H

#define OPEN_DISPLAY Display* display = XOpenDisplay(nullptr); \
                    if (!display) { return; }

#define REFLASH XFlash();
#endif // HEADERS_H
