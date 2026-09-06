/* Inheritable for patch of some sort of (likely fungal) growth on the ground.
 */

inherit "/econ/plant";
#include <const.h>

int query_max_size() {
   return 10;
}

// never crowded, will grow up next to things
int query_crowded( int fertility ) {
   if( query_y() < 2 || query_x() < 2 || query_y() >= environment()->query_map_y_dim() - 1 || query_x() >= environment()->query_map_xdim() - 1 )
      return 1;
}

void on_map_paint( object painter ) {
   switch( query_size() ) {
      case 0..2: painter->paint( query_x(), query_y(), '.', 0x8A, LAYER_ITEMS );
 break;
      case 3..5: painter->paint( query_x(), query_y(), 'o', 0x8A, LAYER_ITEMS );
 break;
      default: painter->paint( query_x(), query_y(), '@', 0x8A, LAYER_ITEMS ); break;
   }
}
