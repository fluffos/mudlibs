#include <const.h>
inherit "/obj/monster";

ALT_NAME( ({ "wolf", "wolf cub" }) )
ALT_PLURAL( ({ "wolves", "wolf cubs" }) )
void create() {
   object ob;
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
   set_distant( "a wolf cub" );
   set_specific( "the wolf cub" );
   set_look( "This is a wolf cub. ~Pron ~verbis cute. ~Pron is $(HP)." );
   set_plural( "cubs" );
   set_name( "cub" );
   set_type( "wolf" );
   set_droppable( 1 );
   set_weight( 10000 );
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("canine");
   set_wc((["piercing":4]));
   set_wimpy(40);

   /*
   env_var( "skin_type", "/monsters/skin/wolfcub_pelt" );
   set_env_var( "meat_type", "/monsters/meat/wolf" );
   */
   set_product_aspect( C_WOLF );
   add_product( C_MEAT, 1, 50 );
   add_product( C_PELT, 4, 20 );
   // add_product( C_TOOTH, 1, 40 );

   set_hp( query_max_hp() );

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(1);
   ob->move(this_object());
}

ICON( 'w', 8, LAYER_LIVING )
