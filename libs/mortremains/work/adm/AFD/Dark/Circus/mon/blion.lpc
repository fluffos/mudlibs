#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a fierce bat-lion");
  set("long", @ENDLONG
This creatures torso and legs appear to be a black-colored lion.  Its head,
however resembles a giant bat.  It has two large, batlike wings jutting
from both sides of the creatures body.
ENDLONG
  );
  set_alignment(100);
  set_name("bat-lion");
  set("id", ({
    "bat",
    "lion",
    "bat-lion",
  }));
  set("agressive", 1);
  set("damage", ({ 5, 50 }) );
  set("armor_class", 6);
  set("attack_strength", 14);
  set("race", "bat-lion");
  set("attrib1", "HUGE");  set("attrib2", "long-haired");
  set("gender", "neuter");
  set("weapon_name", "claws", "wings", "jaws");
  set_verbs( ({
    "slash at",
    "bite at",
}));
set_verbs2( ({
    "slashes at",
    "bites at",
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(9);
  set("forgetful", 1);
  set("att_chat_output", ({
      "The bat-lion beats at you with his bony wings!\n",
      "The beast screaches and your ears begin to bleed.\n",
      "The bat-lion tries to swallow you whole!\n",
      "The horrific creature growls angrily.\n",
}) );
}
int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 30;
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
  "You gore " +
        victim->query("cap_name") + "horribly with his wicked pitchfork!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You scream in anguish as as chunk of flesh is rended from your body!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 query("cap_name") +" is nearly torn to pieces by the bat-lion!\n");
}
}