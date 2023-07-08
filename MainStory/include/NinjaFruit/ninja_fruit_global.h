#ifndef NINJA_FRUIT_GLOBAL_H
#define NINJA_FRUIT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(NINJA_FRUIT_LIBRARY)
#   define NINJA_FRUIT_EXPORT Q_DECL_EXPORT
#else
#   define NINJA_FRUIT_EXPORT Q_DECL_IMPORT
#endif

#endif // NINJA_FRUIT_GLOBAL_H
