#include <const.h>
inherit "/obj/monster";

NAME( "bear" )
LOOK( "~Name ~verbhas brown fur, menacing dark eyes, and an irritable demeanor. ~Pron is $(HP)." )
DISTANT( "a bear" )
SPECIFIC( "the bear" )
PLURAL( "bears" )
TYPE( "bear" )
WEIGHT( 135000 )
DROPPABLE( 1 )

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 15 );
   set_con( 20 );
   set_str( 18 );
   set_dex( 12 );
   set_wil( 10 );
   set_cha( 3 );
   set_int( 4 );
   set_emp( 3 );
   set_skill ( "combat.weapon.unarmed", 50);
/* } OBJEDIT */

   set_living_name( name );

   set_food(query_food_capacity()/2);
   set_drink(query_drink_capacity()/2);

   add_form("animal");
   set_form("animal", 1);
   remove_form("brawl");

   set_race("ursine");
   set_wc((["piercing":7]));

   /*
   set_env_var( "skin_type", "/monsters/skin/bear_skin" );
   set_env_var( "meat_type", "/monsters/meat/bear" );
   */
   set_product_aspect( C_BEAR );
   add_product( C_MEAT, 10, 20 ); // lots of meat, easy to get at
   //add_product( C_GREASE, 10, 30 ); // as much fat as meat, slightly harder
   //add_product( C_BONE,   8,  20 ); // a good number of bones as well
   //add_product( C_TOOTH,  2,  40 ); // let's limit the number of teeth
   add_product( C_PELT, 12, 30 ); // and bears produce a very large hide

   set_base_ac( 15 );
   set_ac_mod( ([ "piercing" : -5, "slashing" : 5 ]) );
   set_hp( query_max_hp() );
   set_wimpy(20);

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(1);	// barely aggro
   ob->move(this_object());
}

ICON( 'B', 3, LAYER_LIVING )
