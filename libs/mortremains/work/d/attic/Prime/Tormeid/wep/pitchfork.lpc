#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a pitchfork");
  set("long", @ENDLONG
A simple pitchfork, normally used for bailing hay.
ENDLONG
  );
  set("id", ({ "pitchfork", "fork" }) ) ;
  set("name", "pitchfork");
  set("mass", 7);
  set("bulk", 2);
 set("value",65) ;
  set("weapon", 4) ;
  set("damage", ({ 2, 4 }) );
  set_weapon_type("trident") ;
 set_verbs( ({ "poke at", "swing at", "attack at", "thrust at" }) );
  set("nosecond", 1) ;
  set("size", 5) ;
} 

