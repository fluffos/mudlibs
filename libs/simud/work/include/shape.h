#ifndef _SHAPE_H_
#define _SHAPE_H_

inherit "/inherit/shape";
#include <const/shapeconst.h>

#ifdef _MAP_TILE_H_
#error You may not include shape.h and map_tile.h in the same file; they have conflicting purposes.
#endif

#endif
