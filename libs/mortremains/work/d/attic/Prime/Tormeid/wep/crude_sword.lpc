#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a crude shortsword") ;
  set("long", @ENDLONG
A crude shortsword with numerous rust spots forming on it.
It's a piece of shit.
ENDLONG
  );
  set("id", ({ "sword", "shortsword" }));
  set("name", "shortsword");
   set("weapon", 9) ;
  set("damage", ({ 2, 7 }));
  set_weapon_type("sword/short") ;
  set_material_type("metal/steel") ;
  set_verbs(({ "swing at", "attack", "poke at", "thrust at", "jab at" }) );
  set("size", 4);
} 

