// updated to new standards for mass bulk 970108
#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a large two-handed sword");
  set("long", @ENDLONG
This enormous blade would easily require two hands to wield it properly.
It looks quite lethal.
ENDLONG
  );
  set("id", ({ "sword", "two-handed sword", "large sword" }));
  set("name", "two-handed sword");
  set_bonus(0,2,2);
  set_material_type("metal/steel") ;
  set_weapon_type("sword/two-handed") ;
  set("bulk", 10) ;
  set("value", 1200) ;
  set("weapon", 15);
  set("damage", ({ 8, 15 }));
  set("size", 8);
  set_verbs(({
    "swing at",
    "attack",
  }) );
  set("nosecond", 1);
} 
