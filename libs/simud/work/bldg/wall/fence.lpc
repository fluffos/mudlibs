inherit "/bldg/wall/wall";

NAME( "wooden fence" )
DISTANT( "a fence" )
SPECIFIC( "the fence" )
LOOK( "A simple wooden fence; strong enough to keep livestock in, but a human could easily get through it." )
ALT_NAME( ({ "fence" }) )
PHRASE( "A simple wooden fence runs through here." )
PLURAL( "fences" )
ALT_PLURAL( ({ "wooden fences" }) )

nosave string *wall_tiles = ({
// 0000
"+",
// 0001
"-",
// 0010
"|",
// 0011
"+",
// 0100
"-",
// 0101
"-",
// 0110
"+",
// 0111
"+",
// 1000
"|",
// 1001
"+",
// 1010
"|",
// 1011
"+",
// 1100
"+",
// 1101
"+",
// 1110
"+",
// 1111
"+",
});

int query_tile_width() {
   return 1;
}

int query_tile_height() {
   return 1;
}

string *query_wall_tiles() {
   return wall_tiles;
}

int query_paint_color( int pos, int mask ) {
   return 0x83;
}

int query_paint_zbuf( int pos, int mask ) {
   return LAYER_WALL;
}

int query_is_razable( object razer ) {
   return 1;
}
