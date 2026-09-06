#include <const.h>
inherit "/obj/monster";

NAME( "deer" )
DISTANT( "a deer" )
SPECIFIC( "the deer" )
LOOK( "It's a deer. ~Pron is $(HP)." )
PLURAL( "deer" )

DROPPABLE(1)
GETTABLE(0)
WEIGHT(70000)

void create() {
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 9 );
   set_con( 8 );
   set_str( 9 );
   set_dex( 10 );
   set_wil( 8 );
   set_cha( 9 );
   set_int( 5 );
   set_emp( 7 );
   set_type( "animal" );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   /*
   set_env_var( "skin_type", "/monsters/skin/deer_skin" );
   */
   set_product_aspect( C_DEER );
   add_product( C_MEAT, 8, 20 );
   //add_product( C_GREASE, 2, 30 );
   //add_product( C_BONE, 4, 20 );
   //add_product( C_HORN, 2, 10 );
   add_product( C_PELT, 10, 20 );

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("bovine");
   set_wc((["blunt":4]));
   set_wimpy(90);

   use_ai_module( "forage" );
}

ICON( 'd', 3, LAYER_LIVING )
