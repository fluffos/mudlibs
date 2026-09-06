#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_distant( "a giant crab" );
   set_specific( "the giant crab" );
   set_look( "~Name ~verbis essentially a large white edible bug. ~Pron is $(HP)." );
   set_alt_name( "giant crab" );
   set_alt_plural( "giant crabs" );
   set_plural( "crabs" );
   set_name( "crab" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["animal": ({"claw","dodge"}) ]) );
   set_form("animal",1);

   set_race("crustacean");
   set_random_stats();
   set_wc( ([ "piercing":3 ]) );
   set_base_ac( 70 );
   set_ac_mod( ([ "blunt": 25, "fire": 10, "piercing": -10, "ice": -40 ]) );

   set_product_aspect( C_CRAB );
   add_product( C_MEAT, 4, 15 );
   add_product( C_CARAPACE, 9, 30 );
   // claws
}

// temporary hack until we implement coastal fishing
on_hunger() { this_object()->set_food(1000); }
// crabs prolly won't ever have to drink
on_thirst() { this_object()->set_drink(1000); }

string *query_default_ai() { return ({ "wander" }); }

ICON( 'c', 15, LAYER_LIVING )
