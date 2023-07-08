#ifndef PLANEGAME_GLOBAL_H
#define PLANEGAME_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLANEGAME_LIBRARY)
#  define PLANEGAME_EXPORT Q_DECL_EXPORT
#else
#  define PLANEGAME_EXPORT Q_DECL_IMPORT
#endif

#endif // PLANEGAME_GLOBAL_H
