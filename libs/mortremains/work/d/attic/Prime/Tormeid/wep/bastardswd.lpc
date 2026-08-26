// updated to new stds
#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a nasty-looking bastard sword") ;
  set("long", @ENDLONG
This lethal weapon has been sharpened to a glistening fine edge.
It's extremely comfortable in your hands for a sword of its 
size.
ENDLONG
  );
  set("id", ({ "sword", "bastard", "bastard sword" }) ) ;
  set("name", "bastard sword") ;
  set("mass", 65) ;
  set("bulk", 7) ;
  set("value",1650) ;
  set("weapon", 19) ;
  set("damage", ({ 9, 16 }) ) ;
  set("size", 9) ;
  set_material_type("metal/steel") ;
  set_bonus(0,3,3) ;
  set_weapon_type("sword/long") ;
  set("weapon", 3) ;
  set("value", 2300 ) ;
  set_verbs(({
    "swing at",
    "attack",
  }) );
  set("nosecond", 1);
} 

