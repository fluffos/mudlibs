#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a spiked mace");
  set("long", @ENDLONG
A large club with a large, spiked metal ball at the end.  
You could deal quite a bit of damage with this weapon.
ENDLONG
  );
  set("id", ({ "mace", "spiked mace" }));
  set("name", "spiked mace");
  set("bulk", 170);
  set("mass", 140);
  set("value",250);
  set("weapon", 7);
  set("damage", ({ 4, 8 }));
  set_weapon_type("mace") ;
  set("size", 5);
  set_verbs(({
    "swing at",
    "attack",
  }) );
} 

