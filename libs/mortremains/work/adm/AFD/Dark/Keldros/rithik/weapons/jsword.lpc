#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "jagged edged longsword");
  set("long", @ENDLONG
This scimitar has a thinly fashioned blade.
The blade glistens in the light  At close examination,
it is covered with faint runes.  Perhaps this weapon
has magical properties...
ENDLONG
  );
  set("id", ({
    "jagged longsword",
    "sword",
    "longsword",
  }));
  set("name", "longsword");
  set("bulk", 40);
  set("mass", 32);

  set("size", 4);
  set_value(2000);
  set("weapon", 16);
  set("damage", ({ 20,50 }));
  set_type("cutting");
  set_verbs( ({
    "lacerate",
    "jab",
    "transfix",

}));
  set_verbs( ({
    "lacerates",
    "jabs",
    "transfixes",

}));
  set("post_wield_func", "special_on");
}

int special_on() {
  write(@ENDLONG
The lonsword feels light within your grasp.
ENDLONG
 );
return 1;
}

int weapon_hit(int damage) {
  object victim;
 int cost;
  cost = random(damage) + 20;
  victim = environment()->query_current_attacker();
  if (random(100) < 10) {
  message("combat",
  "The jagged longsword saws into its victim" +
        victim->query("cap_name") + "!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You cry in anguish as the jagged longsword tears into you!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "The longsword drives into its opponent!\n");
    return 0;
  }
}
