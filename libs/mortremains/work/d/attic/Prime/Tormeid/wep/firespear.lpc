// Coded by Chronos.
#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "Firespear");
  set("hit_func", "ilzarion's stupid hit_func") ;
  set("long", @ENDLONG
This is the Firespear, of unknown origin.  The furies of Hell
are contained within the mystic flames that cover this mighty
weapon of legend.
ENDLONG
  );
  set("id", ({
    "firespear",
  "spear" ,
  }));
  set("value",2400);
  set("size", 7);
  set("weapon", 18);
  set("damage", ({ 2,20 }));
  set("name", "Firespear");
  set_weapon_type("spear") ;
  set("damage_type", "fire") ;
  set_material_type("metal/fine steel") ;
  set("value", 2750 ) ;
  set_bonus(2,2,2) ;
  set_verbs(({
    "thrust at",
    "stab at",
    "attack",
  }) );
  set("second", 0);
  set("nosecond", 1);
  set("wield_func", "flame_on") ;
}

int flame_on() {
  write(@ENDLONG
You feel the power of the Firespear surge through your body!
ENDLONG
 );
return 1;
}

varargs
int hit_func(object victim, int damage) {
  int cost;
  if (!victim) victim = environment()->query_current_attacker() ;
  cost = random(damage) + 1;
  if (random(100) < 5) {
  message("combat", 
  "Hellfire bursts forth from the Firespear, engulfing " +
        victim->query("cap_name") + "!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "Hellfire bursts forth from the Firespear, engulfing you in flames!\n");
   victim->receive_damage(cost, "fire")  ;
    tell_object(environment(), 
 "Hellfire bursts forth from the Firespear, engulfing your foe!\n");
  return damage ;
  }
  return damage ;
}


