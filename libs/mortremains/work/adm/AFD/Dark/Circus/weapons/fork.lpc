#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a wicked pitchfork");
  set("long", @ENDLONG
This scimitar has a thinly fashioned blade.  The blade glistens in the light
At close examination, it is covered with faint runes.  Perhaps this weapon
has magic properties...
ENDLONG
  );
  set("id", ({
    "pitchfork",
    "fork",
    "wicked pitchfork",
  }));
  set("size", 7);
  set("name", "wicked pitchfork");
  set("bulk", 20);
  set("mass", 22);
  set_value(1150);
  set("weapon", 13);
  set("damage", ({ 11,20 }));
  set_type("thrusting");
  set_verbs(({
    "spear at",
    "attempt to spike",
  }) );
  set("pre_wield_func", "req_func");
}

int req_func() {
  if(!userp(TP)) return 0;
  if ((int)TP->query("stat/strength")<7) {
    write("You are not strong enough to wield that weapon.\n");
    return 1;
  }
}
int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 20;
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
  "You gore " +
        victim->query("cap_name") + "horribly with his wicked pitchfork!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are gored horribly by Hans' wicked pitchfork!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 victim->query("cap_name") +" Is gored horribly by "+TPN+"!\n");
}
}