// Wall tiles are chosen according to their borders
// for this wall type. The four cardinal directions
// SWNE are considered; these four make a nibble,
// which is used to lookup the tile.

inherit "/bldg/wall/wall";

NAME( "wall" )
DISTANT( "a city wall" )
SPECIFIC( "the city wall" )
LOOK( "An awesomely high city wall, solidly built of stone and wide enough for a horse to ride atop it. A wall this size indicates a wealthy and mighty city indeed." )
ALT_NAME( ({ "city wall" }) )
PHRASE( "A high city wall stands here, wide and powerful enough to repulse an army." )
ALT_PLURAL( ({ "walls" }) )
PLURAL( "city walls" )

int on_raze() {
   return 0; // This needs to be smarter.
}

nosave string *wall_tiles = ({
// 0000
":::::"
"|'''|"
"|___|",
// 0001
":::::"
"|''''"
"|____",
// 0010 = 0000
":::::"
"|'''|"
"|___|",
// 0011 = 0001
":::::"
"|''''"
"|____",
// 0100
":::::"
"''''|"
"____|",
// 0101
":::::"
"'''''"
"_____",
// 0110 = 0100
":::::"
"''''|"
"____|",
// 0111 = 0101
":::::"
"'''''"
"_____",
// 1000
"....."
":   :"
":   :",
// 1001
"....."
":    "
":    ",
// 1010
":   :"
":   :"
":   :",
// 1011
":   :"
":    "
":    ",
// 1100
"....."
"    :"
"    :",
// 1101
"....."
"     "
"     ",
// 1110
":   :"
"    :"
"    :",
// 1111
":   :"
"     "
"     ",
});

string *query_wall_tiles() {
   return wall_tiles;
}

int query_tile_width() {
   return 5;
}

int query_tile_height() {
   return 3;
}

int query_paint_color( int pos, int mask ) {
   int ch = wall_tiles[mask][pos];
   if( ch == '.' || ch == ':' || ch == ' ' ) return 0x70;
   else return 0x74;
}

int query_paint_zbuf( int pos, int mask ) {
   return /*wall_tiles[mask][pos] == ' '?LAYER_ROUGH:*/LAYER_WALL;
}

//   B
//  C A  mask pattern
//   D
/*
void on_map_paint( object painter ) {
   int point, mask, ix, iy;
   mapping wallmap;

   wallmap = query_spots();

   foreach( point : wallmap ) {
      string shape_pattern;
      int ch, col;

      shape_pattern = wall_tiles[get_mask(point, wallmap)];

      for( ix = 0; ix < 5; ix++ )
      for( iy = 0; iy < 3; iy++ ) {
         ch = shape_pattern[ix + iy * 5];
         if( ch == '.' || ch == ':' || ch == ' ' ) col = 0x70;
         else col = 0x74;
         painter->paint( ix + CX(point), iy + CY(point), ch, col, LAYER_WALL );
      }
   }
}
*/