#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "a young wife") ;
  set("long", @ENDLONG
This is the wife of a castle guard.
ENDLONG
  );
  set("id", ({ "woman","mother", "wife" }) ) ;
  set("gender", "female");
  set("race", "human");
  set_name("wife") ;
  credit( 100 + random(45) ) ;
  set_level(5) ;
  set("stat", ([
   "strength" : 10, "dexterity" : 15, "intelligence" : 15,
   "wisdom" : 18, "charisma" : 15, "constitution" : 11
  ]) ) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 6 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "punche at", "swing at", "attack" }) );
}
