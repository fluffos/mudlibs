#include <const.h>
inherit "/obj/monster";
// As per Al's direction...
//inherit "/ai/wolf";

void create() {
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 13 );
   set_con( 3 );
   set_str( 6 );
   set_dex( 8 );
   set_wil( 11 );
   set_cha( 3 );
   set_int( 4 );
   set_emp( 3 );
   set_distant( "a beaver" );
   set_specific( "the beaver" );
   set_look( "This is a small beaver. It has a broad scaly tail and very large teeth. Perhaps it's pelt it worth something. It's $(HP)." );
   set_plural( "beavers" );
   set_name( "beaver" );
   set_type( "beaver" );
   set_droppable( 1 );
   set_weight( 10000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_product_aspect( C_BEAVER );
   add_product( C_MEAT, 3, 20 );
   //add_product( C_GREASE, 3, 20 );
   //add_product( C_TOOTH, 2, 30 );
   add_product( C_PELT, 4, 20 );

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("castor");
   set_wc((["piercing":4]));

   set_env_var( "skin_type", "/monsters/skin/beaver_pelt" );
   set_hp( query_max_hp() );

//   start_ai();
}

ICON( 'b', 8, LAYER_LIVING )

void on_hunger() {
   add_food( 100 );
}

void on_thirst() {
   add_drink( 100 );
}
