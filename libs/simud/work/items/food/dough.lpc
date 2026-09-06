#include <const.h>
inherit "/obj/ingredient";

int state, cooked;

TASTE( "It tastes great, but it can't be good for ~pron." )

create() {
   ::create();
/* OBJEDIT { */
   set_edible( 1 );
   set_food_value( 10 );
   set_drink_value( 2 ); // Per 1000 units
   set_weight( 1500 );
   set_bulk( 1000 );
   set_value( 0 );
   set_distant( "dough" );
   set_specific( "the dough" );
   set_look( "A pale brown glob of raw dough." );
   set_plural( "dough" );
   set_name( "dough" );
   set_use_msg( "~Name ~verbgulp down some raw dough." );
   set_quantity( 250 );
   set_solid( 1 );
   set_gettable( 1 );
   set_droppable( 1 );
/* } OBJEDIT */
   call_out( "rise", 60 );
   state = 0; // Unraised
   cooked = 0;
}

void rise() {
   set_look( "A pale brown glob of raw dough. The effects of the leaven in the dough have caused it to enlarge, becoming lighter and filled with air bubbles." );
   state = 1; // Risen
}

void on_heat( int temp ) {
   if( temp > 100 ) {
       remove_call_out( "rise" );
       cooked++;
      if( cooked > 2 ) {
         if( state == 0 )
            clone_object("/items/food/flatbread")->move( environment(this_object()) );
         else
            clone_object("/items/food/bread")->move( environment(this_object()) );
         destruct( this_object() );
      }
   }
}

int query_cooked() {
   return cooked;
}

void set_cooked( int x ) {
   cooked = x;
}
mapping query_aspects() {
   return ([ C_FOOD, C_DOUGH ]);
}
