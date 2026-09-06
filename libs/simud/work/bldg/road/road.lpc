inherit "/bldg/wall/wall";

NAME( "road" )
DISTANT( "a road" )
SPECIFIC( "the road" )
LOOK( "The road is a carefully cleared path across the landscape." )
PHRASE( "There is a stone road here." )

int query_tile_width() {
   return 5;
}

int query_tile_height() {
   return 3;
}

// Edge of road is the surface of the road when you walk to it...
mapping query_border() {
   return query_shape();
}

nosave string *road_tiles = ({
// 0000
" ... "
" ::: "
" ''' ",
// 0001
"  ..."
" ::::"
"  '::",
// 0010
" ::: "
" ::: "
" ''' ",
// 0011
" :::."
" ::::"
" ':::",
// 0100
"...  "
":::: "
"::'  ",
// 0101
"....."
":::::"
":::::",
// 0110 = 0100
".::: "
":::: "
":::' ",
// 0111 = 0101
".:::."
":::::"
":::::",
// 1000
" ... "
" ::: "
" ::: ",
// 1001
"  ..."
" ::::"
" ::::",
// 1010
" ::: "
" ::: "
" ::: ",
// 1011
" :::."
" ::::"
" ::::",
// 1100
"...  "
":::: "
":::: ",
// 1101
"....."
":::::"
":::::",
// 1110
".::: "
":::: "
":::: ",
// 1111
".:::."
":::::"
":::::",
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
         if( ch == ' ' )
            continue;
         if( ch != ':' )
            painter->paint( ix + CX(point), iy + CY(point), ch, 0x88, LAYER_TERRAIN );
         else
            painter->paint( ix + CX(point), iy + CY(point), ch, 0x38, LAYER_TERRAIN );
      }
   }
}
