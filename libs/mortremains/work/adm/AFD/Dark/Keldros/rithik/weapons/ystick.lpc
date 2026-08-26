#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "bloody yardstick");
  set("long", @ENDLONG
This yardstick is covered in blood.  You see no markings
of any kind, other than the blood.  The numbers must have
been rubbed off from constant use.
ENDLONG
  );
  set("id", ({
    "yardstick",
    "stick",
    "weapon",
  }));
  set("name", "yardstick");
  set("bulk", 20);
  set("mass", 22);

  set("size", 6);
  set_value(650);
  set("weapon", 9);
  set("damage", ({ 2,7 }));
  set_type("blunt");
  set_verbs( ({
    "thrash",
    "smack",
}));
  set_verbs2( ({
    "thrashes",
    "smacks",
}));

  set("post_wield_func", "special_on");
}

int special_on() {
  write("You grin evilly as you grasp the yardstick.\n" );
  say(TPN+" grins evilly while grasping the evil yardstick.\n");
  set("extra_look", TPN+" has a constant evil grin on "+possessive(TP->query("gender"))+" face.\n");
return 1;
}

int weapon_hit(int damage) {
  object victim;


  int cost;
  cost = random(damage) + 7;
  victim = environment()->query_current_attacker();
  if (random(100) < 5) {
  message("combat",
 
        victim->query("cap_name") + "'s are turned bloody!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "Your knuckles burst into agony!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "The yardstick finds its home on the hand of its enemy.\n");
    return 0;
  }
}