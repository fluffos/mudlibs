#include <const/shapeconst.h>

nosave mapping shape, border;

void eval_shape() {
   string room_tiles;
   mapping border_shape;
   int ix, iy;

   border_shape = this_object()->query_border_shape();
   if( !mappingp(border_shape) )
      border_shape = ([
            SMAKE_C(0, 2, 0),
            SMAKE_C(6, 2, 0),
            SMAKE_C(3, 0, 0),
            SMAKE_C(3, 4, 0)
         ]);
   shape = ([ ]);
   border = ([ ]);
   if( !environment() || !environment(environment()) )
      return;
   room_tiles = environment(environment())->query_grid_chunk( environment()->query_coord() );
   if( !room_tiles )
      return;

   for( iy = 0; iy < OVERWORLD_HEIGHT; iy++ )
   for( ix = 0; ix < OVERWORLD_WIDTH; ix++ ) {
      if( room_tiles[ix + iy * OVERWORLD_WIDTH] == this_object()->query_tile_num() ) {
         shape += ([ SMAKE_C(ix * 5 + 3, iy * 3 + 2, 0) ]);
         border += SHAPE_OFFSET( border_shape, SMAKE_C(ix * 5, iy * 3, 0) );
      }
   }
}

mapping query_shape() {
   if( mappingp(shape) )
      return shape;
   eval_shape();
   return shape;
}

void clear_shape() {
   shape = 0;
   border = 0;
}

mapping query_border() {
   if( mappingp(border) )
      return border;
   eval_shape();
   return border;
}
