/* Unix framewrok library -- X11/input.h 
*  this lib is responsible for receiving and processing keystrockes
*
*  Copyright (C) 2025 UnixSD

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
