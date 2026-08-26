#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a gleaming butcher knife") ;
  set("long", @ENDLONG
A well-sharpened butcher knife with a glistening edge.
ENDLONG
  );
  set("id", ({ "knife", "butcher knife" }) ) ;
  set("name", "butcher knife") ;
  set("value",50);
  set("weapon", 3) ;
  set("damage", ({ 1, 3 }));
  set_weapon_type("dagger") ;
 set_bonus(0,1,2) ;
  set_material_type("metal/steel") ;
 set_verbs( ({ "swing at", "cut at", "slash at", "attack", "slice at" }) ) ;
  set_verbs2(({ "swings at", "cuts at", "slashes at", "attacks", "slices at" }));
  set("size", 3) ;
  set("second", 1);
} 

