#include <const.h>
#include <inven.h>
#include <desc.h>
#include <object.h>
#include <landscape.h>
#include <scenedesc.h>

int query_tile_num() { return 1; }

// How much more eating you can get from this grass.
int condition;

int query_fertile() { return 7; }

int query_condition() {
   return condition;
}

int query_max_condition() {
   return 2000;
}

void set_condition( int x ) {
   condition = x;
}

int query_is_edible() {
   return( query_condition() >= 0 );
}

int on_consume( int max ) {
   if( !this_player()->query_race_object()->query_can_graze() ) {
      msg("Grazing animals have it easy, don't they? Sorry, grass won't do you any good.");
      return 1;
   }

   if( query_condition() < max ) max = query_condition();
   if( max <= 0 ) {
      msg( "The grass is overgrazed, there's nothing left here to eat." );
      return 1;
   }
   if( max > 20 ) max = 20;
   this_player()->msg_local( "~CACT~Name ~verbeat a mouthful of grass.~CDEF" );
   this_player()->add_food( max );
   set_condition( query_condition() - max );
   return 1;
}

LOOK("This grass is ?(HP(0-30):thin and damaged):(?(HP(31-60):fresh and green):(lush and thick)). Grazing animals might appreciate its culinary virtues.")
DISTANT( "grass" )
SPECIFIC( "the grass" )
NAME( "grass" )
PHRASE( "?(HP(0-30):The grass growing here is scraggly and damaged.):(?(HP(31-60):Patches of green grass grow here.):(Lush green grass is growing here.))" )

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
   set_condition( 1000 );
}

void reset() {
   ::reset();
   // Grass gradually goes back, but it takes a long time... might speed it up later.
   set_condition( query_condition() + 5 );
   if( query_condition() > 2000 ) set_condition( 2000 );
   this_object()->remove_var("look");
   this_object()->remove_var("specific");
}

mapping query_aspects() {
   return ([ C_GRASS, C_GRAZE ]);
}
