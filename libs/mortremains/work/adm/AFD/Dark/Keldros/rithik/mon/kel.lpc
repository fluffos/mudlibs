#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Keldrin, The Lord High Mayor");
  enable_commands();
  set("long", @ENDLONG
Keldrin maintains a cruel grimace with every puff on his pipe. 
He is wearing a red smoking jacket which proclaims a decadent
wealth enjoyed by few.
ENDLONG
  );
  set_alignment(-150);
  set_name("keldrin");
  set("id", ({
    "mayor",
    "keldrin",   
}));
  credit(300+ random(900));
  set("damage", ({ 30, 70 }) );
  set("armor_class", 5);
  arm(WEAPONS(wbow), "bow");
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "medium-sized");  set("attrib2", "grimacing");
  set("gender", "male");
  set("weapon_name", "well crafted hand bow");
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(13);
  set("hit_points", 300);
  set("max_hp", 300);
  set("forgetful", 1);
}

int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 30;
  victim = environment()->query_current_attacker();
  if (random(100) < 15) {
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
