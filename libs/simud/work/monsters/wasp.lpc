#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_distant( "a giant wasp" );
   set_specific( "the giant wasp" );
   set_look( "~Name ~verbis a great black flying menace. Its wings emit an incessant buzz as it hovers a meter or two off of the ground, searching for prey. ~Pron is $(HP)." );
   set_alt_name( "giant wasp" );
   set_alt_plural( "giant wasps" );
   set_plural( "wasps" );
   set_name( "wasp" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["animal": ({"sting","dodge"}) ]) );
   set_form("animal",1);

   set_race("wasp");
   set_random_stats();
   set_wc( ([ "piercing":10, "poison":3 ]) );
   set_base_ac( 50 );
   set_ac_mod( ([ "blunt": 25, "fire": 10, "piercing": -10, "ice": -40 ]) );

   set_product_aspect( C_INSECT );
   add_product( C_MEAT, 2, 25 );
   add_product( C_CARAPACE, 3, 40 );
   // add_product( C_TOOTH, 2, 40 ); // stinger
   // wings

   clone_object("/ai/carnivore")->move(this_object());
}

ICON( 'w', 8, LAYER_LIVING )
