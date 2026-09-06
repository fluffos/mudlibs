#ifndef _COORD_H_
#define _COORD_H_

#ifdef _ITEM_H_
#error You may not include item.h and coord.h in the same file; item inherits coord.
#endif

#ifdef _MAP_PAINT_H_
#error Can't inherit map_paint and coord together, map_paint inherits coord.
#endif

inherit "/inherit/coord";

#endif