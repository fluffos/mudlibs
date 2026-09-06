inherit "/bldg/wall/wall";

NAME( "stairs" )
DISTANT( "a staircase" )
SPECIFIC( "the staircase" )
LOOK( "It's a staircase. It's a series of artificial ridges designed to make it easier to ascend or descend steep surfaces." )
ALT_NAME( ({ "staircase" }) )
PHRASE( "There is a solid cement staircase here." )

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
      painter->paint_shape( CX(point), CY(point), ">--->\n>--->\n>--->", 0x70, LAYER_TERRAIN );
   }
}
