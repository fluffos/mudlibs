#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Fernelius") ;
  set_skill("Two Weapon Style", 2, "strength") ;
  set("long", @ENDLONG
Fernelius looks like the type of individual you'd expect to see
trying to rob someone in a busy marketplace.  He looks like he
can handle himself in combat, however.
ENDLONG
  );
  set("id",({ "fern", "fernelius" }) ) ;
  set("gender", "male");
  set("race", "half-elf");
  set_name("Fernelius") ;
  credit(random(300)+ 102) ;
  set_level(30) ;
  set("stat", ([
   "strength" : 15, "dexterity" : 19, "intelligence" : 12,
   "wisdom" : 11, "charisma" : 9, "constitution" : 10
  ]) ) ;
  set_skill("Ambidexterity", 1, "dexterity") ;
  set_skill("Short Blades", 2, "strength") ;
  set_alignment("cn") ;
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(protring3), "ring") ;
  wear(ARM(studded_leather), "leather") ;
  arm(WEP(poison_dagger), "dagger") ;
  arm(WEP(poison_dagger), "dagger") ;
  arm(OBJ(bag_of_holding), "hi there.") ;
  wear(ARM(slboots), "boots") ;
}
