inherit "/obj/scenery";
#include <container.h>
#include <shape.h>

SPECIFIC( "the counter" )
DISTANT( "a counter" )
LOOK( "A wooden counter.?(HASINV: On it $(ISINV) $(INV).)" )

int length;

void create() {
   ::create();
/* OBJEDIT { */
   set_name( "counter" );
   set_phrase( "There's a wooden counter ~plac." );
   set_position( "across the room" );
   set_preposition( "on" );
/* } OBJEDIT */
}

// 1 if vertical, 0 if horizontal.
int query_direction() {
   if( length < 0 ) return 1;
   else return 0;
}

int query_length() {
   return abs(length);
}

void set_direction( int x ) {
   if( x ) x = -1;
   else x = 1;
   if( (length < 0 && x == 1) || (length > 0 && x == -1) ) length = -length;
   if( length == 0 ) length = x;
}

void set_length( int x ) {
   if( length == 0 )
      length = x;
   else
      length = (length / abs(length)) * x;
}

void on_map_paint( object painter ) {
   int pos = query_coord(), ilen;

   if( query_direction() ) {
      for( ilen = query_length(); ilen--; pos += MAKE_C(0, 1, 0) )
         painter->paint( CX(pos), CY(pos), '#', 0x0F, LAYER_FURNITURE );
   }
   else {
      for( ilen = query_length(); ilen--; pos += MAKE_C(1, 0, 0) )
         painter->paint( CX(pos), CY(pos), '#', 0x0F, LAYER_FURNITURE );
   }
}
