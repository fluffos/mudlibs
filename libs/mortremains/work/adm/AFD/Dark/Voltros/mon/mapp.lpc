inherit MONSTER;
void create() {
  seteuid(getuid());
  ::create();
  set("short", "munchkin apprentice");
  enable_commands();
  set("long", @ENDLONG
ENDLONG
  );
  set_name("munchkin apprentice");
  set("id", ({
  "munchkin",
  "apprentice"
  }));
  set("damage", ({ 2, 5 }) );
  set("armor_class", 1);
  set("attack_strength", 1);
  set("race", "munchkin");
	set("size", 3);
	set_level(2);
  set("attrib1", "tired");  set("attrib2", "studying");
  set("gender", "male");
  set("weapon_name", "fists");
  spell_cast("demon", 25);
  set_verbs( ({
    "attack",
    "swings at",

}));
}
int demon_cast() {
  object target;
  int damage;
  string name,x,y,z;
  target=query_current_attacker();
  if (!target || target->query("dead")) return 1;
  name = target->query("cap_name");
            x = "The apprentice casts a spell at you!.";
            y = "The apprentice casts an ice spell at "+name+"!";
            z = "You cast an ice spell at "+name+"!";
            damage = (random(10)+6);
  tell_object(target, wrap(x));
  message("combat", wrap(y), environment(), ({ this_object(), target }) );
  tell_object(this_object(), wrap(z));
      target->receive_damage(damage);
  return 1;
}