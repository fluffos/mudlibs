#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_distant( "a giant centipede" );
   set_specific( "the giant centipede" );
   set_look( "~Name ~verbis over one meter long and has more legs than any decent critter should own. While definately not a full hundred, it's close enough to warrant the name. ~Pron is $(HP)." );
   set_alt_name( "giant centipede" );
   set_alt_plural( "giant centipedes" );
   set_plural( "centipedes" );
   set_name( "centipede" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["animal": ({"bite","poisonbite","dodge"}) ]) );
   set_form("animal",1);

   set_race("centipede");
   set_random_stats();
   set_wc( ([ "edged":4, "poison":5 ]) );
   set_base_ac( 50 );
   set_ac_mod( ([ "blunt": 25, "fire": 10, "piercing": -10, "ice": -40 ]) );

   set_product_aspect( C_INSECT );
   add_product( C_MEAT, 3, 25 );
   add_product( C_CARAPACE, 7, 40 );
   // add_product( C_TOOTH, 2, 40 ); // mandibles

   clone_object("/ai/carnivore")->move(this_object());
}

ICON( 'c', 3, LAYER_LIVING )
