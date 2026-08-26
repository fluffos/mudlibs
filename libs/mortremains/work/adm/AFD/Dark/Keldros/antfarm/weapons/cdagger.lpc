inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a copper dagger");
  set("long", @ENDLONG
This dagger appears short and has serrated edges. 
It looks as though, if used properly, it could inflict
serious damage on an opponent.  
ENDLONG
  );
  set("id", ({
"dagger",
"weapon",
"copper dagger",
  }));
  set("name", "copper dagger");
  set("bulk", 5);
  set("mass", 3);
  set("size", -1);
  set_value(280);
  set("weapon", 8);
  set("damage", ({ 8, 15 }));
  set_type("thrusting");
  set_verbs(({
     "slice at",
     "rip at",    
  }) );
 set("second", 1);
}
int weapon_hit(int damage) {
  object victim;
  int spark;
  spark = random(damage) + 10;
  victim = environment()->query_current_attacker();
  if (random(101) < 10) {
  message("combat",
  "The dagger glows red and strikes " +
        victim->query("cap_name")+"\n",
         environment(victim),
      ({ victim, environment() }) );
  tell_object(victim,
  "You are in singed with the red-hot dagger!\n");
   victim->receive_damage(spark);
    tell_object(environment(),
 victim->query("cap_name") +" recoils from intense heat!\n");
}
}