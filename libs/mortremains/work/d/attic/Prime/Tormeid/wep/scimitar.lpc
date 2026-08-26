#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a sharp scimitar");
  set("long", @ENDLONG
A long curved blade, sharpened to a fine, glistening edge.
ENDLONG
  );
  set("id", ({ "scimitar" }));
  set("name", "scimitar");
  set("bulk", 100);
  set("mass", 70);
  set("value",450);
  set("weapon", 7);
  set("damage", ({ 3, 7 }));
  set_weapon_type("sword/long") ;
  set("second", 1);
  set("size", 6);
  set_verbs(({ "swing at", "attack", "slash at", "cut at" }) );
  set_verbs2(({ "swings at", "attacks", "slashes at", "cuts at" }) );
} 

