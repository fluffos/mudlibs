#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a well-fashioned shortsword");
  set("long", @ENDLONG
A shortsword of exceptional quality.
ENDLONG
  );
  set("id", ({ "sword", "shortsword" }));
  set("name", "shortsword");
  set("bulk", 100);
  set("mass", 90);
  set("value",750);
   set("weapon", 9) ;
  set("damage", ({ 2, 7 }));
  set_weapon_type("sword/short") ;
  set_material_type("metal/fine steel") ;
  set_verbs(({ "swing at", "attack", "poke at", "thrust at", "jab at" }) );
  set("size", 4);
} 

