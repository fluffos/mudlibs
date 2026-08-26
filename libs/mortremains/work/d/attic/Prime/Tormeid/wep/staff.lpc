#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a wooden staff");
  set("long", @ENDLONG
A strong wooden staff carved from oak.
ENDLONG
  );
  set("id", ({ "staff" }));
  set("name", "staff");
  set("bulk", 100);
  set("mass", 40);
  set("value",100);
  set("weapon", 4);
  set("damage", ({ 2, 4 }));
  set_weapon_type("quarterstaff") ;
  set("nosecond", 1);
  set("size", 5);
  set_verbs(({ "swing at", "attack" }) );
} 

