#include <const.h>
inherit "/obj/monster";

int equipped;

NAME( "goblin" )
LOOK( "~Name is a small orange humanoid. Foul thing, ~pron emits a pungent odor that you will likely not soon forget. ~Pron is $(HP)." )
DISTANT( "a goblin" )
SPECIFIC( "the goblin" )
PLURAL( "goblins" )
TYPE( "human" )
WEIGHT( 40000 )
DROPPABLE( 1 )

void create() {
   object ob;
   ::create();
   set_gender( random(2)+1 );
/* OBJEDIT { */
   set_spd( 14 );
   set_con( 8 );
   set_str( 9 );
   set_dex( 12 );
   set_wil( 8 );
   set_cha( 5 );
   set_int( 5 );
   set_emp( 5 );
/* } OBJEDIT */

   add_lawful_alignment(-400);
   add_good_alignment(-400);
   set_living_name( name );

   set_food(query_food_capacity());
   set_drink(query_drink_capacity());

   // potentially should add butchering capabilities to this... but -much-
   // much later, ne? shudder

   set_race("human");
   set_wc((["blunt":3]));
   set_wimpy(60);
   equipped = 0;
   call_out( "equipme", 0 );

   ob = clone_object("/ai/aggro");
   ob->set_aggro_level(10);
   ob->move(this_object());
}

ICON( 'g', 3, LAYER_LIVING )

void on_hunger() {
   add_food( 100 );
}

void on_thirst() {
   add_drink( 100 );
}

void equipme() {
   string weapon;
   if (equipped)
      return;
   equipped = 1;
   command("skillme");
   switch(random(6)) {
      case 0: weapon = "dagger";
              this_object()->set_skill("combat.weapon.dagger",15);
              this_object()->set_skill("combat.dodging",15);
              this_object()->set_skill("combat.technique.parry",5);
              break;
      case 1: weapon = "knife";
              this_object()->set_skill("combat.weapon.dagger",15);
              this_object()->set_skill("combat.dodging",20);
              break;
      case 2: weapon = "shortsword";
              this_object()->set_skill("combat.weapon.sword",15);
              this_object()->set_skill("combat.dodging",5);
              this_object()->set_skill("combat.technique.parry",15);
              break;
      case 3: weapon = "club";
              this_object()->set_skill("combat.weapon.mace",15);
              this_object()->set_skill("combat.technique.parry",10);
              this_object()->set_skill("other.endurance",10);
              break;
      case 4: weapon = "spear";
              this_object()->set_skill("combat.weapon.polearm",15);
              this_object()->set_skill("combat.technique.parry",20);
              break;
      case 5: weapon = "hatchet";
              this_object()->set_skill("combat.weapon.axe",15);
              this_object()->set_skill("combat.dodging",10);
              this_object()->set_skill("other.endurance",10);
              break;
   }
   if( !present(weapon, this_object()) )
      clone_object("/items/weapon/"+weapon)->move(this_object());
   command("wield "+weapon);
}
