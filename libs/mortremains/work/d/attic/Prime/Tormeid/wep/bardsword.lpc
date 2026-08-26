#include <mudlib.h>
#include "../defs.h"

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "the Bardsword");
  set("long", @ENDLONG
This is the Bardsword, a legendary shortsword said to have been carried
by the legendary Masked Bard during the ancient Underworld Wars of
Tormeid.
ENDLONG
  );
  set("id", ({ "bardsword", "sword", "shortsword" }));
  set("name", "Bardsword");
  set("value", 2500);
  set_weapon_type("sword/short") ;
  set("wield_func", "wield_that_shit") ;
  set("hit_func", "ilzarion's rookie code") ;
 set_bonus(1,2,0) ;
  set("value", 2500 ) ;
  set("size", 3);
  set_verbs(({ "swing at", "attack", "poke at", "stab at", "thrust at" }) );
}

int wield_that_shit() {
  if ((int)TP->query("stat/charisma") < 13) 
    write("You somehow get the feeling this weapon isn't going to do you much good.\n");  return 1;
}   

varargs int hit_func(object victim, int damage) {
  damage = damage + (((int)environment(TO)->query("stat/charisma") - 13)*2) ;
  if (damage<0) damage = 0 ;
  return damage ;
}
