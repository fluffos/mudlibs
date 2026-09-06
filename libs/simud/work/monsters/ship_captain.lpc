#include <const.h>
inherit "/obj/monster";

/* todo: have ship captains concordokken */
/* anyone who picks a fight on board */

void create() {
   object ob;

::create();

   if (!clonep(this_object())) {
     return; /* blueprints don't get stuff */
   }

   set_gender( random(2)+1 ); // both male and female guards
/* OBJEDIT { */
   set_distant( "a captain" );
   set_specific( "the ship captain" );
   set_look( "~Name ~verbis one of the captains of the 3 ships. ~Pron ~verbstand watch against rowdy passengers and stowaways. ~Pron ~verbis ?(ISCLOTHED:wearing $(WORN)):(unclothed), and ~verbis holding $(HELD). ~Pron ~verbis $(HP)." );
   set_alt_name( "ship captain" );
   set_alt_plural( "captain" );
   set_plural( "captains" );
   set_name( "captain" );
   set_type( "human" );
   set_droppable( 1 );
   set_weight( 60000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["sword": ({"slash","stab","dodge","parry"}),
                      "brawl": ({"punch","dodge"}) ]) );
   set_skill("combat.weapon.sword",50);
   set_skill("combat.weapon.unarmed",25);
   set_skill("combat.technique.parry",50);
   set_skill("combat.dodging",25);

   set_race("human");
   set_random_stats();
   set_stat("str",18);
   set_wc( ([ "blunt":5 ]) );
   set_base_ac( 10 );

   // initially aggro to all critters
   ob = clone_object("/ai/memory");
   ob->set_enemies( ({"skeleton", "crab", "bear", "grizzly bear", "polar bear", "duck", "centipede","lion","lizard","scorpion","wasp", "wolf", "rabbit", "deer", "fire lizard"}) );
   ob->move(this_object());

   // concordokken any troublemakers
   debug("captain:  loading peacekeeper ai");
   clone_object("/ai/peacekeeper")->move(this_object());

   call_out("suit_up",4);
}

void suit_up() {
   // equipment
   if( !present_clone("/items/armour/copper_breastplate", this_object()) ) {
      clone_object("/items/armour/leatherpants")->move(this_object());
      clone_object("/items/armour/leatherboots")->move(this_object());
      clone_object("/items/armour/copper_breastplate")->move(this_object());
      clone_object("/items/armour/copper_shield")->move(this_object());
      clone_object("/items/weapon/copper_gladius")->move(this_object());
   }

   command( "skillme" );
   command( "wear all", this_object() );
   command( "hold sword and shield", this_object() );
   set_hp( query_max_hp() );
   set_endurance( query_max_endurance() );
}

void on_hunger() {
   add_food(100);
   add_drink(100);
}

ICON( 'h', 9, LAYER_LIVING )
