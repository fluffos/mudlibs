#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a well crafted hand bow");
  set("long", @ENDLONG
This yardstick is covered in blood.  You see no markings
other than the blood caking the arrowhead.
ENDLONG
  );
  set("id", ({
    "bow",
    "hand bow",
    "weapon",
  }));
  set("name", "well crafted hand bow");
  set("size", 4);
  set("bulk", 20);
  set("mass", 22);
  set_value(950);
  set("weapon", 17);
  set("damage", ({ 22,40 }));
  set_type("thrusting");
  set_verbs( ({
    "attempt to spear",
    "attempt to perforate",
    "attempt to poke",
}));


}
int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 30;
  victim = environment()->query_current_attacker();
  if (random(100) < 5) {
  message("combat",
        victim->query("cap_name") + "is shot right through!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You scream as you are shot right through!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "An arrow fires from the bow and spears "+victim->query("cap_name")+" through the chest!\n");
    return 0;
  }
}