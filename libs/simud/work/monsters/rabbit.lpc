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
   set_distant( "a rabbit" );
   set_specific( "the rabbit" );
   set_look( "It's a fluffy bunny rabbit, and it's absolutely adorable. It has a cute habit of wrinkling its nose at you. ~Pron is $(HP)." );
   set_plural( "rabbits" );
   set_alt_name( "bunny" );
   set_name( "rabbit" );
   set_type( "rodent" );
   set_droppable( 1 );
   set_weight( 3000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   /*
   set_env_var( "skin_type", "/monsters/skin/rabbit_pelt" );
   set_env_var( "meat_type", "/monsters/meat/rabbit" );
   */
   // new butcher system support
   set_product_aspect( C_RABBIT );
   add_product( C_MEAT, 3, 10 );
   add_product( C_PELT, 3, 20 );
   //add_product( C_FOOT, 2, 60 ); // just to be silly
   //add_product( C_TAIL, 1, 40 );

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("rodent");
   set_wc((["piercing":2]));
   set_wimpy(100);

   clone_object("/ai/forage")->move(this_object());
}

ICON( 'r', 15, LAYER_LIVING )
