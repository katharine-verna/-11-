#ifndef JIGSAW_COPY_H
#define JIGSAW_COPY_H

#include <QtCore/qglobal.h>

#if defined(JIGSAW_COPY_LIB2RARY)
#   define JIGSAW_COPY_EXPORT Q_DECL_EXPORT
#else
#   define JIGSAW_COPY_EXPORT Q_DECL_IMPORT
#endif

#endif // JIGSAW_COPY_H
