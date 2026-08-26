#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "Larissa") ;
  set("long", @ENDLONG
Larissa is a attractive young lady who lives in the castle.
ENDLONG
  );
  set("id",({ "lady", "larissa" }) ) ;
  set("gender", "female");
  set("race", "half-elf");
  set_name("Larissa") ;
  credit(1320) ;
  set_level(12) ;
  set("stat", ([
   "strength" : 12, "dexterity" : 15, "intelligence" : 10,
   "wisdom" : 14, "charisma" : 17, "constitution" : 9
  ]) ) ;
  set_alignment("lg") ;
  set("damage", ({ 2, 5 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
}
