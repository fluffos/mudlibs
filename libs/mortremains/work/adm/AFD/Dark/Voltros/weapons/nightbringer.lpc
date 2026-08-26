inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a heavy mace");
  set("long", @ENDLONG
This mace is made of a black material know as Eog.
ENDLONG
  );
  set("id", ({
"mace",
"nightbringer",
  }));
  set("name", "Nightbringer");
  set("bulk", 29);
  set("size",-1);
  set("magic",2);
  set("mass", 20);
  set_value(2200);
  set("weapon", 16);
  set("damage", ({ 13,17 }));
  set_type("bash");
  set_verbs(({
   "beat",
   "pound",
 }) );
set("pre_wield_func", "req_func");
}
int req_func()
{
if((int)TP->query("alignment")>-100){
write("Away, foul being!!!\n");
	TP->receive_damage(20);
    return 0;
  }
return 1;
}

int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(60);
  victim = environment()->query_current_attacker();
  if (random(100) < 10) {
  message("combat",
        victim->query("cap_name") + " is encompassed by complete darkness!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "\n\n\nNightbringer hums softly as it strikes you, plunging you into darkness!\n");
  tell_object(victim,
  "\n\n\nIt's so dark, that you accidentally hit yourself!\n\n");
  victim->receive_damage(cost);
    tell_object(environment(),
 "Nightbringer hums softly as it strikes it's opponnent.\n");
    return 0;
  }
}
