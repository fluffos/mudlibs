#ifndef _ITEM_H_
#define _ITEM_H_

#include "const.h"

inherit "/inherit/item";

#ifdef _COORD_H_
#error You may not include item.h and coord.h in the same file; item inherits coord.
#endif

#endif
