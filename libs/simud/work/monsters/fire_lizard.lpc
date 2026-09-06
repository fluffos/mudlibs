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
   set_distant( "a fire lizard" );
   set_specific( "the fire lizard" );
   set_look( "~Name ~verbis small and red with a wingspan no greater than about a meter. ~Pron occasionally emits a small puff of smoke from ~poss nostrils. ~Pron is $(HP)." );
   set_alt_name( "fire lizard" );
   set_alt_plural( "fire lizards" );
   set_plural( "lizards" );
   set_name( "lizard" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 12000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   set_known_forms( (["dragon": ({"dragon_bite","dragon_hide"}) ]) );
   set_form("dragon",1);

   set_race("lizard");
   set_wc((["piercing":7]));
   set_base_ac( 35 );
   set_ac_mod( ([ "blunt": 25, "fire": 60, "piercing": -10, "ice": -20 ]) );

   set_product_aspect( C_DRAGON );
   add_product( C_MEAT, 6, 30 );
   add_product( C_SCALE, 1, 40 );
   add_product( C_PELT, 2, 95 );
   // add_product( C_TOOTH, 4, 40 );

   clone_object("/ai/fire_lizard")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(20);
   ob->move(this_object());
}

ICON( 'l', 1, LAYER_LIVING )
