#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a mace");
  set("long", @ENDLONG
A large club with a metal ball at the end.  You could deal quite
a bit of damage with this weapon.
ENDLONG
  );
  set("id", ({ "mace" }));
  set("name", "mace");
  set("bulk", 150);
  set("mass", 120);
  set("value",200);
  set("weapon", 16) ;
  set("damage", ({ 3, 6 }));
  set_verbs(({
    "swing at",
    "attack",
  }) );
  set_weapon_type("mace") ;
} 

