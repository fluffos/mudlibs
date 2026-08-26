#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "concentrating teacher");
  enable_commands();
  set("long", @ENDLONG
Mrs. Racine is one of the shortest humanoids you have ever seen, yet it appears she
has extremely strong legs, she could probably jump and reach your face, if she tried.
ENDLONG
  );
  set_alignment(-200);
  set_name("Mrs. Racine");
  set("id", ({
    "teacher",
    "racine",
  }));
  
  credit(200);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 4);
  arm(WEAPONS(ystick), "stick");
  set( "agressive", 1);
  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "extremely short");  set("attrib2", "brown-haired");
  set("gender", "female");
  set("weapon_name", "finger nails");
  set_verbs( ({
    "thrash",
    "smack",
}));
  set_verbs2( ({
    "thrashes at",
    "smacks",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 3);
  set("chat_output", ({
    "Mrs. Racine chants: \"K-E-L-T-F-E-R\"\n",
    "Mrs. Racine chants: \"S-K-U-N-N-A-K\"\n",
    "Mrs. Racine chants: \"B-A-R-S-T-E-R\"\n",
  }) );
  set("forgetful", 1);

}





int weapon_hit(int damage) {
  object victim;


  int cost;
  cost = random(damage) + 7;
  victim = environment()->query_current_attacker();
  if (random(100) < 20) {
  message("combat",
 
        victim->query("cap_name") + "'s eyes are gouged out!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are blinded for an instant as you feel a piercing pain in your eyes!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "The eyes of your opponent bleed.\n");
    return 0;
  }
}
