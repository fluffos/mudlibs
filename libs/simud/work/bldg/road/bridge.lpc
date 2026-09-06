// Wall tiles are chosen according to their borders
// for this wall type. The four cardinal directions
// SWNE are considered; these four make a nibble,
// which is used to lookup the tile.

inherit "/bldg/wall/wall";
#include <const/shapeconst.h>

NAME( "bridge" )
DISTANT( "a bridge" )
SPECIFIC( "the bridge" )
LOOK( "Bridges are a useful means of spanning bodies of water, as they allow traffic to cross from one side to the other. They are one of the great innovations of the ages." )
PHRASE( "A bridge arches over the water." )
ALT_NAME( ({ "bridge" }) )

/// 0 = horiz, 1 = vert
int direction;

int query_direction() { return direction; }
void set_direction( int x ) { direction = x; border = 0; }

mapping query_border() {
   int pos;
   mapping spots;

   if( border ) return border;
   spots = query_spots();
   border = ([ ]);
   foreach( pos : spots ) {
      if( query_direction() ) {
         if( !member(spots, MAKE_C(CX(pos), CY(pos) - query_tile_height(), CZ(pos))) )
            border += SHAPE_OFFSET( SHAPE_BOX(5,1), SMAKE_C(CX(pos), CY(pos)-1, 0) );
         if( !member(spots, MAKE_C(CX(pos), CY(pos) + query_tile_height(), CZ(pos))) )
            border += SHAPE_OFFSET( SHAPE_BOX(5,1), SMAKE_C(CX(pos), CY(pos)+query_tile_height(), 0) );
      }
      else {
         if( !member(spots, MAKE_C(CX(pos) - query_tile_width(), CY(pos), CZ(pos))) )
            border += SHAPE_OFFSET( SHAPE_BOX(1, 3), SMAKE_C(CX(pos)-1, CY(pos), 0) );
         if( !member(spots, MAKE_C(CX(pos) + query_tile_width(), CY(pos), CZ(pos))) )
            border += SHAPE_OFFSET( SHAPE_BOX(1, 3), SMAKE_C(CX(pos)+query_tile_width(), CY(pos), 0) );
      }
   }
   return border;
}

int query_site_layer() {
   return LAYER_OVERLAY; // So you can't walk across the river on the site...
}

mapping query_legal_layers() {
   return ([ LAYER_WATER + '0' : 1 ]);
}

mapping query_legal_border_layers() {
   return FLOOR_CHARS;
}

int query_tile_width() {
   return 5;
}

int query_tile_height() {
   return 3;
}

int check_direction( int dir ) {
   int pos, tile;

   if( !dir ) {
      msg("You have to specify a direction to build the bridge (i.e. 'to the north').");
      return -1;
   }

   if( SCY(dir) ) set_direction(1);
   else set_direction(0);

   // Multiply up.
   dir = SMAKE_C(SCX(dir)*5, SCY(dir)*3, 0);
   pos = OFFSET_C(this_player()->query_coord(), dir);

   // Now check to see if the tiletype is valid.
   do {
      tile = environment(this_player())->get_tiletype(CX(pos), CY(pos));
      if( !tile ) {
         msg("You can't build a bridge off the edge of the map. Find somewhere where you can see both sides of the body of water.");
         return -1;
      }
      tile -= '0'; // get_tiletype uses the zbuffer, which offsets by '0' ...

      if( tile == LAYER_WATER )
         add_spot(pos);
      pos = OFFSET_C(pos, dir);
   } while( tile == LAYER_WATER );

   if( !query_spots() || !sizeof(query_spots()) ) {
      msg( "You have to build bridges over water! If you are near water, try walking closer, and make sure the direction is correct." );
      return -1;
   }

   return 0;
}

void on_map_paint( object painter ) {
   int point;
   mapping wallmap;
   string block;

   wallmap = query_spots();

   if( query_direction() )
   block = "|   ||   ||   |";
   else block = "-----     -----";
   foreach( point : wallmap )
      painter->paint_tile_clipped( CX(point), CY(point), block, 0x6F, LAYER_BRIDGE );
}

