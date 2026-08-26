#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a fine longsword");
  set("long", @ENDLONG
A well-made longsword.
ENDLONG
  );
  set("id", ({ "sword", "longsword" }));
  set("name", "longsword");
  set("bulk", 125);
  set("mass", 100);
  set("value",875);
  set("weapon", 10);
  set("damage", ({ 3, 7 }));
  set_weapon_type("sword/long") ;
  set_verbs(({ "swing at", "attack", "slash at", "cut at" }) );
  set("size", 7);
  set_verbs2(({ "swings at", "attacks", "slashes at", "cuts at" }) );
} 

