#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "glowing scimitar");
  set("long", @ENDLONG
This scimitar has a thinly fashioned blade.  The blade glistens in the light
At close examination, it is covered with faint runes.  Perhaps this weapon
has magic properties...
ENDLONG
  );
  set("id", ({
    "scimitar",
    "sword",
    "weapon",
  }));
  set("name", "scimitar");
  set("bulk", 20);
  set("mass", 22);


  set_value(550);
  set("weapon", 9);
  set("damage", ({ 2,7 }));
  set_type("cutting");
  set_verbs(({
    "jab at",
    "swing violently",
  }) );
  set("damage_type", "light");
  set("post_wield_func", "special_on");
}

int special_on() {
  write(@ENDLONG
The scimtar seems to move on its own within your grasp!
ENDLONG
 );
return 1;
}

int weapon_hit(int damage) {
  object victim;


  int cost;
  cost = random(damage) + 10;
  victim = environment()->query_current_attacker();
  if (random(100) < 5) {
  message("combat",
  "The scimitar's controller scoffs at the poor combat skill of " +
        victim->query("cap_name") + "!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "The scimitar finds your comat skills appauling and shows you how correct it is!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "The scimitar tells you: Why do you bother fighting such a weak foe?\n");
    return 0;
  }
}
