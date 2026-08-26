#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Princess Lulu") ;
  set("long", @ENDLONG
Lulu is the bratty princess of the castle.  She demanded that she live
in the southeast tower because she felt like it.  So she lives in the
drafty top floor of the tower.
ENDLONG
  );
  set("id", ({ "princess", "lulu" }) ) ;
  set("gender", "female");
  set("race", "human") ;
  set_name("Princess Lulu") ;
  credit(3204) ;
  set_level(12) ;
  set("stat", ([
   "strength" : 12, "dexterity" : 15, "intelligence" : 10,
   "wisdom" : 14, "charisma" : 17, "constitution" : 9
  ]) ) ;
  set_alignment("cn") ;
  set("damage", ({ 2, 5 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
}
