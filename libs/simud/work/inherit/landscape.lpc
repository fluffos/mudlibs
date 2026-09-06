#define TILE_NUM this_object()->query_tile_num()

int query_is_landscape() { return 1; }

void on_map_paint( object painter ) {
   int i, small_map_xdim;
   string small_map;
   mapping spots = this_object()->query_spots();

   if( !mappingp(spots) || !sizeof(spots) ) spots = 0;

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
      if( mappingp(spots) && !member(spots, MAKE_C(x+1,y+1,0)) )
         continue;
      // Homogenous paint (no border behavior)
      "/daemon/map"->build_tile( x, y, TILE_NUM, ({ TILE_NUM, TILE_NUM, TILE_NUM, TILE_NUM }), 15, this_object()->query_tile_color() );
      tile = "/daemon/map"->query_last_tile();
      painter->paint_tile_clipped( x + 1, y + 1, tile[0], tile[1], this_object()->query_zlayer() );
   }
}
