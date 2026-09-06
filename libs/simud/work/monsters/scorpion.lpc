#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_distant( "a giant scorpion" );
   set_specific( "the giant scorpion" );
   set_look( "~Name is a nasty big crawly thing of the sort that give people nightmares. It has some eight legs, two claws, and a great tail with a nasty barbed stinger on the tip. This is definitely one monster that not even a mother could love. Oh, and the claws could probably cut you in half too. ~Pron is $(HP)." );
   set_alt_name( "giant scorpion" );
   set_alt_plural( "giant scorpions" );
   set_plural( "scorpions" );
   set_name( "scorpion" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["animal": ({"grab","sting","dodge"}) ]) );
   set_form("animal",1);

   set_race("scorpion");
   set_random_stats();
   set_wc( ([ "piercing":7, "poison":10 ]) );
   set_base_ac( 50 );
   set_ac_mod( ([ "blunt": 25, "fire": 10, "piercing": -10, "ice": -40 ]) );

   set_product_aspect( C_SCORPION );
   add_product( C_MEAT, 3, 25 );
   add_product( C_CARAPACE, 7, 40 );
   // add_product( C_TOOTH, 2, 40 ); // mandibles

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(50);
   ob->move(this_object());
}

ICON( 's', 1, LAYER_LIVING )
