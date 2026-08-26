#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a dagger");
  set("long", @ENDLONG
A simple, yet sturdy dagger.
ENDLONG
  );
  set("id", ({ "dagger" }));
  set("name", "dagger");
  set("bulk", 40);
  set("mass", 20);
  set("value",50);
  set("weapon", 2);
  set("damage", ({ 1, 3 }));
  set_weapon_type("dagger") ;
  set_bonus(0,0,0) ;
  set_material_type("metal/steel") ;
  set_verbs(({ "swing at", "cut at", "stab at", "slash at", "attack" }) );
  set("size", 3) ;
  set_verbs2(({ "swings at", "cuts at", "stabs at", "slashes at", "attacks" }) );
  set("second", 1);
} 

