#include <const.h>
inherit "/obj/monster";

NAME( "grizzly bear" )
LOOK( "~Name ~verbhas gray fur streaked with brown, and angry, piercing eyes. ~Pron is $(HP)." )
DISTANT( "a grizzly bear" )
SPECIFIC( "the grizzly bear" )
PLURAL( "grizzly bears" )
ALT_PLURAL( ({ "bears", "grizzly bears", "grizzlies" }) )
ALT_NAME( ({ "bear", "grizzly" }) )
TYPE( "bear" )
WEIGHT( 155000 )
DROPPABLE( 1 )

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 15 );
   set_con( 22 );
   set_str( 20 );
   set_dex( 14 );
   set_wil( 10 );
   set_cha( 3 );
   set_int( 4 );
   set_emp( 3 );
   set_skill ( "combat.weapon.unarmed", 80);
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("ursine");
   set_wc((["piercing":5]));
   /*
   set_env_var( "skin_type", "/monsters/skin/bear_skin" );
   set_env_var( "meat_type", "/monsters/meat/bear" );
   */
   set_product_aspect( C_BEAR );
   add_product( C_MEAT, 12, 20 );
   //add_product( C_GREASE, 12, 30 );
   //add_product( C_BONE,   8,  20 );
   //add_product( C_TOOTH,  2,  40 );
   add_product( C_PELT, 14, 30 );

   set_base_ac( 35 );
   set_ac_mod( ([ "piercing" : -1, "slashing" : 5 ]) );
   set_hp( query_max_hp() );
   set_wimpy(70);

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(1);
   ob->move(this_object());
}

ICON( 'B', 8, LAYER_LIVING )
