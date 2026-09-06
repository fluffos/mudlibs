#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_str( 18 );
   set_dex( 10 );
   set_con( 24 );
   set_spd( 20 );
   set_wil( 4 );
   set_int( 4 );
   set_emp( 4 );
   set_cha( 4 );
   set_distant( "a giant lizard" );
   set_specific( "the giant lizard" );
   set_look( "~Name ~verbis an enormous green monster. It is two meters long and stands on two pairs of widely spaced legs. It doesn't look terribly vicious, but it would probably still eat you if given the chance. ~Pron is $(HP)." );
   set_alt_name( "giant lizard" );
   set_alt_plural( "giant lizards" );
   set_plural( "lizards" );
   set_name( "lizard" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   set_known_forms( (["animal": ({"bite","throatbite","dodge"}) ]) );
   set_form("animal",1);

   set_race("lizard");
   set_wc((["piercing":5]));
   set_base_ac( 25 );
   set_ac_mod( ([ "blunt": 25, "fire": 10, "piercing": -10 ]) );

   set_product_aspect( C_LIZARD );
   add_product( C_MEAT, 6, 30 );
   add_product( C_PELT, 7, 40 );
   // add_product( C_TOOTH, 4, 40 );

   clone_object("/ai/carnivore")->move(this_object());
}

ICON( 'l', 2, LAYER_LIVING )
