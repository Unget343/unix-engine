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
