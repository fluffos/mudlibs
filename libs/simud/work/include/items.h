#ifndef _ITEMS_H_
#define _ITEMS_H_

#include "const.h"

inherit "/inherit/items";

#ifdef _TILEDMAP_H_
#error You may not include tiledmap.h and item.h in the same file; both inherit coord.
#endif

#ifdef _COORD_H_
#error You may not include item.h and coord.h in the same file; item inherits coord.
#endif

#endif
