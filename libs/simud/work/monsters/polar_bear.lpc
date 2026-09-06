#include <const.h>
inherit "/obj/monster";

NAME( "polar bear" )
LOOK( "~Name ~verbis hugely big. ~Pron is covered in thick white fur and has arms and teeth large enough to rip a seal in half. ~Pron is $(HP)." )
DISTANT( "a polar bear" )
SPECIFIC( "the polar bear" )
PLURAL( "bears" )
ALT_PLURAL( ({ "polar bears" }) )
ALT_NAME( ({ "bear", "polar" }) )
TYPE( "bear" )
WEIGHT( 185000 )
DROPPABLE( 1 )
TASTE( "The bear tastes like dried fish guts." )

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

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   set_known_forms( (["brawl": ({}), "animal": ({"claw","bite","dodge","counter","rend"})]) );
   set_form( "animal" );

   set_race("ursine");
   set_wc((["piercing":5,"blunt":12]));

   set_product_aspect( C_BEAR );
   add_product( C_MEAT, 16, 20 );
   //add_product( C_GREASE, 16, 30 );
   //add_product( C_BONE,   9,  20 );
   //add_product( C_TOOTH,  4,  40 );
   add_product( C_PELT, 18, 30 );

   set_base_ac( 55 );
   set_ac_mod( ([ "piercing" : 20, "edged" : 20, "ice": 40, "fire":-60 ]) );
   set_hp( query_max_hp() );
   set_wimpy(0);

   clone_object("/ai/carnivore")->move(this_object());
   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(20);
   ob->move(this_object());
}

ICON( 'B', 15, LAYER_LIVING )
