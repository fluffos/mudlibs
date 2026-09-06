#include <const.h>
inherit "/obj/monster";

void create() {
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 11 );
   set_con( 4 );
   set_str( 4 );
   set_dex( 14 );
   set_wil( 9 );
   set_cha( 15 );
   set_int( 3 );
   set_emp( 5 );
   set_distant( "a rat" );
   set_specific( "the rat" );
   set_look( "It's a rat, a large, furry pest known for spreading disease and stealing grain. ~Pron is $(HP)." );
   set_plural( "rats" );
   set_name( "rat" );
   set_type( "rodent" );
   set_droppable( 1 );
   set_weight( 3000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_product_aspect( C_RAT );
   add_product( C_MEAT, 3, 10 );
   add_product( C_PELT, 2, 20 );
   //add_product( C_TAIL, 1, 10 );

   set_known_forms( (["animal": ({ "bite", "dodge"}) ]) );
   set_form("animal",1);

   set_race("rodent");
   set_wc((["piercing":4]));
   set_wimpy(10);

   clone_object("/ai/forage")->move(this_object());
}

ICON( 'r', (query_gender()?3:7) , LAYER_LIVING )
