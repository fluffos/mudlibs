inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "long whip");
  set("long", @ENDLONG
Sting is a long, black and brown whip.  It is
made of leather and metal strands braided togther.
ENDLONG
  );
  set("id", ({
"whip",
"long whip",
"sting",
  }));
  set("magic", 1);
  set("name", "Sting");
  set("bulk", 12);
  set("mass", 10);
  set_value(1037);
	set("size", -1);
  set("weapon", 14);
  set("damage", ({ 11,14 }));
  set_type("lashing");
  set_verbs(({
   "snap at",
   "cut",
  }) );
set("pre_wield_func", "req_func");
}
int req_func()
{
if((int)TP->query("alignment")>-40){
write("Sting gets extremely cold!\n");
	TP->receive_damage(5);
    return 0;
  }
return 1;
}

int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(30);
  victim = environment()->query_current_attacker();
  if (random(100) < 15) {
  message("combat",
        victim->query("cap_name") + " is slapped across the face by Sting!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "Sting dances in the air in front of you before it strikes your face!\n");
  victim->receive_damage(cost);
    tell_object(environment(),
     "Sting whips around in the air a couple of times before it strikes" +victim->query("cap_name")+"!\n");
    return 0;
  }
}
