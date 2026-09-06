inherit "/scn/water/water";
#include <shape.h>
#include <spots.h>

mapping query_shape() {
   int p;

   if( !mappingp(shape) ) {
      shape = ([ ]);
      foreach( p : query_spots() )
         shape += ([ p + MAKE_C(4096, 4096, 32) ]);
   }
   return shape;
}

void on_map_paint( object painter ) {
   int pos;

   foreach( pos : query_spots() ) {
      painter->paint( CX(pos), CY(pos), '.', 70, LAYER_GROUND );
   }
}
