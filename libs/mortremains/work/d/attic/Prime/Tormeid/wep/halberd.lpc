#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a halberd");
  set("long", @ENDLONG
A deadly-looking halberd.
ENDLONG
  );
  set("id", ({ "halberd"}));
  set("name", "halberd");
  set("mass", 20) ;
  set("value",1000);
   set("weapon", 18) ;
  set("damage", ({ 4, 10 }));
  set_weapon_type("halberd") ;
  set_material_type("metal/steel") ;
  set_bonus(0,0,0) ;
  set("nosecond", 1);
  set("size", 9);
  set_verbs(({ "swing at", "attack", "poke at", "thrust at", "jab at" }) );
} 

