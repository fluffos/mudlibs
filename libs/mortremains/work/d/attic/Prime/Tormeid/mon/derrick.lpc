#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Derrick") ;
  set("long", @ENDLONG
Derrick is a young man who is reportedly dating Larissa.
ENDLONG
  );
  set("id",({ "man", "derrick" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("Derrick") ;
  credit(2401) ;
  set_level(15) ;
  set("stat", ([
   "strength" : 17, "dexterity" : 15, "intelligence" : 10,
   "wisdom" : 9, "charisma" : 15, "constitution" : 11
  ]) ) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 6 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "punche at", "swing at", "attack" }) );
}
