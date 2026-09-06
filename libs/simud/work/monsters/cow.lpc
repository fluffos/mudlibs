#include <const.h>
inherit "/obj/monster";

void on_tickle() {
	set_actor(this_object());
	set_listener(this_player());
	msg("~Name ~verbis $(MILKHP).");
}

void create() {
   ::create();
   set_gender( 2 );	// all female for the time being ;)
/* OBJEDIT { */
   set_spd( 9 );
   set_con( 20 );
   set_str( 18 );
   set_dex( 10 );
   set_wil( 10 );
   set_cha( 9 );
   set_int( 5 );
   set_emp( 7 );
   set_distant( "a cow" );
   set_specific( "the cow" );
   set_look( "It's a cow. ~Pron is $(HP).");
   set_plural( "cows" );
   set_name( "cow" );
   set_type( "animal" );
   set_droppable( 1 );
   set_weight( 150000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_product_aspect( C_COW );
   add_product( C_MEAT, 20, 20 );
   //add_product( C_GREASE, 2, 30 );
   //add_product( C_BONE, 4, 20 );
   //add_product( C_HORN, 2, 10 );
   add_product( C_PELT, 15, 20 );

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("bovine");
   set_wc((["blunt":10]));
   set_wimpy(90);

   clone_object("/ai/forage")->move(this_object());
   clone_object("/ai/milkable")->move(this_object());
}

ICON( 'c', 3, LAYER_LIVING )
