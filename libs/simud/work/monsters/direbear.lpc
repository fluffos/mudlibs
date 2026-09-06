#include <const.h>
inherit "/obj/monster";

NAME( "dire bear" )
LOOK( "~Name ~verbhas brown fur streaked with red, and angry, piercing eyes, which glow faintly red. ~Pron is $(HP)." )
DISTANT( "a dire bear" )
SPECIFIC( "the dire bear" )
PLURAL( "bears" )
ALT_PLURAL( ({ "dire bears" }) )
ALT_NAME( ({ "bear", "dire" }) )
TYPE( "bear" )
WEIGHT( 185000 )
DROPPABLE( 1 )

void create() {
   object ob;
   ::create();
   set_gender( 0 );
/* OBJEDIT { */
   set_spd( 15 );
   set_con( 35 );
   set_str( 20 );
   set_dex( 18 );
   set_wil( 20 );
   set_cha( 10 );
   set_int( 15 );
   set_emp( 10 );
   set_skill ( "combat.weapon.unarmed", 100);
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("ursine");
   set_wc((["piercing":10]));

   /*
   set_env_var( "skin_type", "/monsters/skin/bear_skin" );
   set_env_var( "meat_type", "/monsters/meat/bear" );
   */
   set_product_aspect( C_BEAR );
   add_product( C_MEAT, 14, 20 );
   //add_product( C_GREASE, 14, 30 );
   //add_product( C_BONE,   8,  20 );
   //add_product( C_TOOTH,  2,  40 );
   add_product( C_PELT, 16, 30 );

   set_base_ac( 45 );
   set_ac_mod( ([ "piercing" : 20, "slashing" : 20 ]) );
   set_hp( query_max_hp() );
   set_wimpy(5);

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(20);
   ob->move(this_object());
}

ICON( 'B', 9, LAYER_LIVING )
