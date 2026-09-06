#include <const.h>
inherit "/obj/monster";

void create() {
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 20 );
   set_con( 6 );
   set_str( 4 );
   set_dex( 20 );
   set_wil( 18 );
   set_cha( 5 );
   set_int( 4 );
   set_emp( 2 );
   set_distant( "a black bat" );
   set_specific( "the black bat" );
   set_look( "It's a black bat, with veined bat wings that can stretch to about a foot wide. ~Pron is $(HP)." );
   set_plural( "bats" );
   set_name( "bat" );
   set_type( "rodent" );
   set_droppable( 1 );
   set_weight( 1500 );
/* } OBJEDIT */

   set_living_name( name );
   set_default_doing( "hanging from the ceiling" );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   /*
   set_env_var( "skin_type", "/monsters/skin/bat_skin" );
   */
   set_product_aspect( C_BAT );
   add_product( C_MEAT, 1, 40 );	// 1 meat, difficult to get
   //add_product( C_TOOTH, 2, 50 );   // 2 very fine teeth
   //add_product( C_WING, 2, 10 );    // 2 very easy to get wings
   add_product( C_PELT, 1, 30 );    // not very easy to get, not very big

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");
   set_race("avian");	// yeah, yeah, I know
   set_wc((["piercing":4]));
   set_wimpy(60);
}

ICON( 'b', 8, LAYER_LIVING )
