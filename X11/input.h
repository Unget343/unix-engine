/* Unix framewrok library -- X11/input.h 
*  this lib is responsible for receiving and processing keystrockes
*/
#pragma once
#include <string>
#include <X11/Xlib.h>
#include <X11/keysym.h>

#if defined(_WIN32)
#   error "Unsupported OS: please use Unix-like system"
#elif defined(__APPLE__) && defined(__MACH__)
#   pragma message("[Warning]: Work may be unstable on macOS")
#endif

inline bool getkey(std::string& key);
inline bool keyrelease(std::string& key);
