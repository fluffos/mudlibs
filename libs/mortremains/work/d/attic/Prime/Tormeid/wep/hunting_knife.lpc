#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a hunting knife");
  set("long", @ENDLONG
A razor sharp blade on a strong hide hilt.
ENDLONG
  );
  set("id", ({ "knife", "hunting knife" }));
  set("name", "knife");
  set("bulk", 50);
  set("mass", 20);
  set("value",120);
  set("weapon", 3);
  set("damage", ({ 2, 4 }));
  set_weapon_type("dagger") ;
  set("size", 2) ;
  set("value", 400 ) ;
  set_verbs(({
    "swing at",
    "cut at",
    "stab at",
    "attack",
  }) );
  set("second", 1);
} 

