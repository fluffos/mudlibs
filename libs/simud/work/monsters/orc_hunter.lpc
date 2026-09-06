#include <const.h>
inherit "/obj/monster";

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 ); // both male and female hunters
/* OBJEDIT { */
   set_distant( "an orcish hunter" );
   set_specific( "the orcish hunter" );
   set_look( "~Name ~verbis one of many orcs who make their living by hunting the beasts of the forest. ~Pron ~verbis ?(ISCLOTHED:wearing $(WORN)):(unclothed), and ~verbis holding $(HELD). ~Pron ~verbis $(HP)." );
   set_alt_name( ({"orc hunter","orcish hunter"}) );
   set_alt_plural( ({"orc hunters","orcish hunters","orcs"}) );
   set_plural( "hunters" );
   set_name( "hunter" );
   set_type( "orc" );
   set_droppable( 1 );
   set_weight( 70000 );
/* } OBJEDIT */

   set_living_name( name );

   set_known_forms( (["polearm": ({"slash","thrust","dodge","parry"}),
                      "brawl": ({"punch","dodge"}) ]) );
   set_skill("combat.weapon.polearm",50);
   set_skill("combat.weapon.unarmed",25);
   set_skill("combat.technique.parry",50);
   set_skill("combat.dodging",25);
   set_skill("craft.butcher",50);

   set_race("orc");
   set_random_stats();
   set_stat("str", max(18,query_stat("str")) );
   set_wc( ([ "blunt":5 ]) );
   set_base_ac( 15 );

   // initially aggro to all desert critters
   ob = clone_object("/ai/hunter");
   ob->set_enemies( ({"rabbit","lion","lizard","wolf","bear"}) );
   ob->move(this_object());

   call_out("suit_up",4);
}

void suit_up() {
    // equipment
   if( !present_clone("/items/weapon/spear", this_object()) ) {
      clone_object("/items/armour/leatherpants")->move(this_object());
       clone_object("/items/armour/leatherboots")->move(this_object());
       clone_object("/items/armour/leatherjerkin")->move(this_object());
       clone_object("/items/weapon/spear")->move(this_object());
       clone_object("/items/weapon/knife")->move(this_object());
   }

   command( "skillme" );
   command( "wear all", this_object() );
   command( "hold spear", this_object() );
   set_hp( query_max_hp() );
   set_endurance( query_max_endurance() );
}

// No fair giving hunters free food.  They work the food chain
// like everyone else.
// - gpfault

//void on_hunger() {
//   add_food(100);
//   add_drink(100);
//}

ICON( 'h', 9, LAYER_LIVING )
