#ifndef JIGSAW_COPY_GLOBAL_H
#define JIGSAW_COPY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JIGSAW_COPY_LIBRARY)
#   define JIGSAW_COPY_EXPORT Q_DECL_EXPORT
#else
#   define JIGSAW_COPY_EXPORT Q_DECL_IMPORT
#endif

#endif // JIGSAW_COPY_H
