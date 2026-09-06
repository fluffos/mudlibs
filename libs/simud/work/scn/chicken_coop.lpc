#include "const.h"
inherit "/obj/scenery";

int xdim;

int query_xdim() {
   return xdim;
}

void set_xdim( int i ) {
   xdim = i;
   if( environment() )
      environment()->clear_map();
}

int ydim;

int query_ydim() {
   return ydim;
}

void set_ydim( int i ) {
   ydim = i;
   if( environment() )
      environment()->clear_map();
}

void create() {
   ::create();
/* OBJEDIT { */
   set_distant( "?(RECO(chicken coop):a chicken coop):(an enclosure)" );
   set_specific( "the ?(RECO(chicken coop):chicken coop):(enclosure)" );
   set_look( "?(RECO(chicken coop):This chicken coop is made from):(This enclosure is made from) several wooden stakes stuck in the ground in a ring, with bits of ratty wooden board connecting them." );
   set_plural( "?(RECO(chicken coop):chicken coops):(enclosures)" );
   set_name( "chicken coop" );
   set_type( "fence" );
   set_alt_name( "enclosure" );
   set_phrase( "There is ?(RECO(chicken coop):a wooden chicken coop):(some kind of small, wooden fence) set up ~plac." );
   set_position( "just off the path" );
   set_preposition( "in" );
   add_alt_name("enclosure");
   add_alt_name("coop");
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   int ix, iy, x, y;

   x = query_x();
   y = query_y();

   if( xdim == 0 || ydim == 0 ) return;

   painter->paint( x, y, 'o', 3, 2 );
   painter->paint( x + xdim - 1, y, 'o', 3, 2 );
   painter->paint( x, y + ydim - 1, 'o', 3, 2 );
   painter->paint( x + xdim - 1, y + ydim - 1, 'o', 3, 2 );

   for( iy = ydim - 1; --iy; ) {
      painter->paint( x, y + iy, '|', 7, 1 );
      painter->paint( x + xdim - 1, y + iy, '|', 7, 1 );
   }
   for( ix = xdim - 1; --ix; ) {
      painter->paint( x + ix, y, '=', 7, 1 );
      painter->paint( x + ix, y + ydim - 1, '=', 7, 1 );
   }
}

void on_move( object src ) {
   if( src )
      src->clear_map();
   environment()->clear_map();
}