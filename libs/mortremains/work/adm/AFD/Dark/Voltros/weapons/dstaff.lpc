inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "Staff of the Damned");
  set("long", @ENDLONG
This is a staff about 5 feet in length.  It is made of an unknown,
rock-like substance.  It is black, with golden runes emblazoned
up and down it's length.
ENDLONG
  );
  set("id", ({
    "staff",
    "polearm",
    "weapon",
  }));
  set("size", -1);
  set("name", "staff");
  set("bulk", 70);
  set("mass", 32);
        set("nosecond", 1);
        set_value(1650);
  set("weapon", 18);
  set("damage", ({ 22,52 }));
  set_type("blunt");
  set_verbs( ({
    "thrash",
    "smack",
}));
  set_verbs2( ({
    "thrashes",
    "smacks",
}));
  set("pre_wield_func", "req_func");
  set("post_wield_func", "special_on");
}
int req_func2()
{
if((int)TP->query("stat/spirit")<16){
write("You are not mystic enough to wield that weapon.\n");
    return 1;
  }
}
int req_func() {
  if ((int)TP->query("stat/intelligence")<16) {
        write("You are not smart enough to wield that weapon.\n");
req_func2();
return 1;
}
  }

int special_on() {
  write(@ENDLONG
You shudder uncontrollably as the power of damned souls courses through your vei
ns!.
ENDLONG
 );
return 1;
}

int weapon_hit(int damage) {
  object victim;


  int cost;
  cost = random(50);
  victim = environment()->query_current_attacker();
  if (random(100) < 10) {
  message("combat",
        victim->query("cap_name") + " is encompassed by a shadowform, confusing
and suffocating"+victim->query("gender")+"\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "A stream of shadows comes out of the staff and assaults your mind, disorentin
g you and causing you to choke!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "The staff shakes violently in your hands as spirits are unleased from the staf
f!\n");
    return 0;
  }
}