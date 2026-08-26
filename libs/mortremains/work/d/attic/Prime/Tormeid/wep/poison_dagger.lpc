#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a poison-coated dagger");
  set("long", @ENDLONG
A dagger was dipped in a contact poison.
ENDLONG
  );
  set("id", ({ "dagger", "poison dagger" }));
  set("name", "dagger");
  set("weapon", 9);
  set("damage", ({ 1, 4 }));
  set_weapon_type("dagger") ;
  set("value", 1000) ;
  set_bonus(2,0,5) ;
  set("second", 1);
  set("size", 4);
  set("damage_type", "poison");
  set_verbs(({ "swing at", "attack", "poke at", "thrust at", "cut at" }) );
} 


