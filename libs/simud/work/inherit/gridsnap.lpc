#include <spots.h>

/** The same as spots, except with grid snapping on the spots.
 */

/// \return Width of one tile of the wall. Override it for your wall.
int query_tile_width() {
   return 1;
}

/// \return Height of one tile of the wall. Override it for your wall.
int query_tile_height() {
   return 1;
}

void add_spot( int pos ) {
   int x, y;

   x = CX(pos) - 1;
   y = CY(pos) - 1;
   x = (x / query_tile_width()) * query_tile_width();
   y = (y / query_tile_height()) * query_tile_height();
   ::add_spot( MAKE_C(x + 1, y + 1, CZ(pos)) );
}

void remove_spot( int pos ) {
   int x, y;

   x = CX(pos) - 1;
   y = CY(pos) - 1;
   x = (x / query_tile_width()) * query_tile_width();
   y = (y / query_tile_height()) * query_tile_height();
   ::remove_spot( MAKE_C(x + 1, y + 1, CZ(pos)) );
}
