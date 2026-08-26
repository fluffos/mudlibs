inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "Lallai");
  set("long", @ENDLONG
This weapon has been crafted from animal bones and seinew.  Human hair adorns the hil
t.  The handle has been wrapped in some kind of vine, that seems like it would provid
e a good grip.  The bone blade is serrated, but it is somewhat dulled, due to wear an
d tear.
ENDLONG
  );
  set("id", ({
"Lallai",
"lallai",
"dagger",
"knife",
"weapon",
  }));
  set("name", "Lallai");
  set("bulk", 2);
  set("mass", 3);
	set("size", 6);
  set_value(750);
  set("weapon", 9);

  set("damage", ({ 5,9 }));
  set_type("thrusting");
  set_verbs(({
    "lunge at",
    "thrust at",
  }) );
   set("post_wield_func", "empower");
}

int empower() {
  write(@ENDLONG
You feel the winds of the room quicken.
ENDLONG
 );
return 1;
}

int weapon_hit(int damage) {
  object victim;
  int cost;
  cost = random(damage) + 1;
  victim = environment()->query_current_attacker();
  if (random(100) < 5) {
  message("combat",
  "The winds gather themselves and strike " +
        victim->query("cap_name") + "!\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are slammed by a strong gust of wind!\n");
   victim->receive_damage(cost);
    tell_object(environment(),
 "You feel lighter as the winds lift you closer for another strike!\n");
    return 0;
  }
}