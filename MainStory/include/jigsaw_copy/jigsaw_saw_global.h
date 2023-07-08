#ifndef JIGSAW_SAW_GLOBAL_H
#define JIGSAW_SAW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(JIGSAW_SAW_LIBRARY)
#   define JIGSAW__EXPORT Q_DECL_EXPORT
#else
#   define JIGSAW

#endif // JIGSAW_SAW_GLOBAL_H
