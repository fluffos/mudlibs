#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "the whip of a wicked Ring Master");
  set("long", @ENDLONG
The whip is made of a black, hard leather.  The grip
is warm to the touch, it appears magical.  The whip
extends approximately eight feet from handle to tip
and looks quite painful.
ENDLONG
  );
  set("id", ({
    "whip",
    "master whip",
    "ring master whip",
    "ring masters whip",
  }));
  set("size", -1);
  set("name", "ring master's whip");
  set("bulk", 140);
  set("mass", 100);
  set_value(3150);
  set("weapon", 23);
  set("damage", ({ 80,200}));
  set_type("lashing");
  set_verbs(({
    "lacerate",
    "crack at",
    "beat",
    "smack",
    "lash at",
    "slice at",
  }) );
  set_verbs2(({
    "lacerates",
    "cracks at",
    "beats",
    "smacks",
    "lashes at",
    "slices at",
  }) );
  set("post_wield_func", "stud");
}

int stud(){
  write("You feel a sense of power and authority as you grasp the whip.\n");
  say(TPN+" looks to be more confident in "+possessive(TP->query("gender"))+" overall authority on this plane.\n");
return 1;
}
 
int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 100;
  victim = environment()->query_current_attacker();
  if (random(100) < 30) {
  message("combat",
        victim->query("cap_name") + "is tortured by a wicked slash from your whip!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You feel that submission to your opponent would be better than to taste the wicked slash from that whip again!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 victim->query("cap_name") +" Is beaten mercilessly by "+TPN+"!\n");
}
}