#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 12 );
   set_con( 13 );
   set_str( 14 );
   set_dex( 15 );
   set_wil( 10 );
   set_cha( 3 );
   set_int( 4 );
   set_emp( 3 );
   set_distant( "a wolf" );
   set_specific( "the wolf" );
   set_look( "~Name ~verbhas gray fur, penetrating yellow eyes, and a generally surly disposition. ~Pron is $(HP)." );
   set_plural( "wolves" );
   set_name( "wolf" );
   set_type( "wolf" );
   set_droppable( 1 );
   set_weight( 45000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("canine");
   set_wc((["piercing":6]));
   set_wimpy(30);

   /*
   set_env_var( "skin_type", "/monsters/skin/wolf_pelt" );
   set_env_var( "meat_type", "/monsters/meat/wolf" );
   */
   set_product_aspect( C_WOLF );
   add_product( C_MEAT, 3, 40 );
   add_product( C_PELT, 7, 20 );
   // add_product( C_TOOTH, 4, 40 );

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(10);
   ob->move(this_object());
}

ICON( 'w', 8, LAYER_LIVING )
