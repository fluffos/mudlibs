inherit "/bldg/wall/wall";

NAME( "pier" )
DISTANT( 0 )
SPECIFIC( "the pier" )
LOOK( "Wooden boards, tied together to form a platform." )
PHRASE( 0 )

int query_tile_width() {
   return 5;
}

int query_tile_height() {
   return 3;
}

nosave string *road_tiles = ({
// 0000
"()__)"
"()__)"
"()__)",
// 0001
"()__)"
"()___"
"()__)",
// 0010
"()__)"
"()__)"
"()__)",
// 0011
"()___"
"()__)"
"()___",
// 0100
"____)"
"____)"
"____)",
// 0101
"____)"
"_)___"
"_)___",
// 0110
"____)"
"____)"
"____)",
// 0111
"__)__"
"____)"
"___)_",
// 1000
"()__)"
"()__)"
"()__)",
// 1001
"()___"
"()__)"
"()__)",
// 1010
"()__)"
"()__)"
"()__)",
// 1011
"()__)"
"()__)"
"()___",
// 1100
"____)"
"_)__)"
"____)",
// 1101
"_)___"
"___)_"
"____)",
// 1110
"____)"
"____)"
"_)__)",
// 1111
"____)"
"___)_"
"_)___",
});

void on_map_paint( object painter ) {
   int point, ix, iy;
   mapping wallmap;

   wallmap = query_spots();

   foreach( point : wallmap ) {
      string shape_pattern;
      int ch, col;

      if( CX(point) > environment()->query_map_xdim() ||
         CY(point) > environment()->query_map_ydim() ) {
         remove_spot(point);
         continue;
      }

      shape_pattern = road_tiles[get_mask(point, wallmap)];

      for( ix = 0; ix < 5; ix++ )
      for( iy = 0; iy < 3; iy++ ) {
         ch = shape_pattern[ix + iy * 5];
         painter->paint( ix + CX(point), iy + CY(point), ch, 0x30, LAYER_TERRAIN );
      }
   }
}
