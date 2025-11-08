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

#include "mcursor.h"
#include <QPointer>
#include <QCursor>
#include <QApplication>

void CursorProperty::setPos(int x, int y)
{
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);
    XFlush(display);

    XCloseDisplay(display);
}

void CursorProperty::Grab(int x, int y)
{
    XGrabPointer(display, root,
                 False, ButtonPressMask | ButtonReleaseMask | PointerMotionMask,
                 GrabModeAsync, GrabModeAsync, root, None, CurrentTime);

    setPos(x, y);

    XCloseDisplay(display);
}

void CursorProperty::UnGrab()
{
    XUngrabPointer(display, CurrentTime);

    XCloseDisplay(display);
}

void CursorProperty::SetIcon(QCursor shape)
{
    QCursor cursor(shape);
    QApplication::setOverrideCursor(cursor);
}
