// Wall tiles are chosen according to their borders
// for this wall type. The four cardinal directions
// SWNE are considered; these four make a nibble,
// which is used to lookup the tile.

inherit "/bldg/wall/wall";

NAME( "plaza" )
DISTANT( "a plaza" )
SPECIFIC( "the plaza" )
LOOK( "It's made of a bunch of big squares of concrete. It's not really very exciting." )
ALT_NAME( ({ "cement" }) )
PHRASE( "A pattern of large, formed squares of cement covers the ground, forming a plaza." )

int query_tile_width() {
   return 5;
}

int query_tile_height() {
   return 3;
}

//"....."
//".   ."
//"....."

void on_map_paint( object painter ) {
   int point;
   mapping wallmap;

   wallmap = query_spots();

   foreach( point : wallmap ) {
      painter->paint_shape( CX(point), CY(point), ".....\n:\n:", 0x7F, LAYER_TERRAIN );
      painter->paint_shape( CX(point), CY(point)+1, "\t   :\n\t...:", 0x78, LAYER_TERRAIN );
   }
}
