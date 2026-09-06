#include <const.h>
#include <inven.h>
#include <desc.h>
#include <object.h>

NAME( "beach" )
SPECIFIC( "the beach" )
DISTANT( 0 )
LOOK("It's fine beach sand. It has the magical property of making people want to walk around barefoot.")

int query_is_landscape() { return 1; }

void on_map_paint( object painter ) {
   int i, small_map_xdim;
   string small_map;

   if( !environment() );
   if( environment()->query_map_room() ); // Already painted for us :-)
   small_map = environment()->query_small_map();
   small_map_xdim = environment()->query_small_map_xdim();
   for( i = sizeof(small_map); i--; ) {
      mixed *tile;
      int x, y;

      x = (i % small_map_xdim) * 5;
      y = (i / small_map_xdim) * 3;
      if( small_map[i] == '\255' )
         continue;
      // Homogenous paint (no border behavior)
      "/daemon/map"->build_tile( x, y, 5, ({ 5, 5, 5, 5 }), 15 );
      tile = "/daemon/map"->query_last_tile();
      painter->paint_tile_clipped( x + 1, y + 1, tile[0], tile[1], 0 );
   }
}
