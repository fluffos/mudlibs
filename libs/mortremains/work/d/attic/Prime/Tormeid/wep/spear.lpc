#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "an iron spear");
  set("long", @ENDLONG
A spear forged of iron.
ENDLONG
  );
  set("id", ({ "spear", "iron spear" }));
  set("name", "spear");
  set("bulk", 140);
  set("mass", 150);
  set("value",710);
  set("weapon", 7);
  set("damage", ({ 5, 8 }));
  set_weapon_type("spear") ;
  set("nosecond", 1);
  set("size", 7 );
  set_verbs(({ "swing at", "attack", "poke at", "thrust at", "jab at" }) );
} 

