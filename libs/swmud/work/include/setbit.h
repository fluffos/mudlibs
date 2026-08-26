// Bad file name for historical reasons, but these are the standard flags for objects in the system.
#ifndef __SETBIT_H__
#define __SETBIT_H__

#include "flags.h"

#define INVIS                   MakeFlag(STD_FLAGS, 2)
#define TOUCHED                 MakeFlag(STD_FLAGS, 4)
#define DESTROYABLE             MakeFlag(STD_FLAGS, 5)
#define ATTACHED                MakeFlag(STD_FLAGS, 14)
#define TRANSPARENT             MakeFlag(STD_FLAGS, 16)
#define AUTOLOAD                MakeFlag(STD_FLAGS, 17)

#endif /* __SETBIT_H__ */