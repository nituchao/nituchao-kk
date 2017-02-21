#ifndef UI_GLOBAL_H
#define UI_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UI_LIBRARY)
#  define UISHARED_EXPORT Q_DECL_EXPORT
#else
#  define UISHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // UI_GLOBAL_H
