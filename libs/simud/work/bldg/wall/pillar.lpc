inherit "/bldg/wall/wall";

DISTANT( "pillars" )
SPECIFIC( "the pillars" )
LOOK( "Round, stone pillars. Way too heavy to pick up. Seriously." )
NAME( "pillar" )

void on_map_paint( object painter ) {
   int pos;

   foreach( pos : query_spots() )
      painter->paint_shape( CX(pos) - 1, CY(pos) - 1, "\t_\n(_)", 0x8F, LAYER_WALL );
}