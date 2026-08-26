#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a heavy bastard sword") ;
  set("long", @ENDLONG
This huge sword would surely inflict a lot of damage if used properly.
The initials 'D.R.' seem to be inscribed in the hilt.
ENDLONG
  );
  set("id", ({ "bastard sword", "sword", "large sword" }) ) ;
  set("name", "bastard sword") ;
  set("bulk", 300);
  set("mass", 200);
  set("value",1750) ;
  set("weapon", 15);
  set("damage", ({ 8, 15 }));
  set_weapon_type("sword/long") ;
  set_material_type("metal/steel") ;
  set_verbs(({
    "swing at",
    "attack",
  }) );
  set("size", 7) ;
  set("value", 2300 ) ;
  set("nosecond", 1);
} 

