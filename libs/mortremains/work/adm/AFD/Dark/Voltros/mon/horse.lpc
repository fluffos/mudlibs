inherit MONSTER;
void create() {
  seteuid(getuid());
  ::create();
  set("short", "a riding horse");
  enable_commands();
  set("long", @ENDLONG
This is a brown horse.  It looks like it could travel a long way
before resting.
ENDLONG
  );
  set_name("horse");
  set("id", ({
  "horse",
  "animal"
  }));
  set("damage", ({ 8, 15 }) );
  set("armor_class", 4);
  set("attack_strength", 7);
  set("race", "equine");
	set("size", 8);
  set("attrib1", "medium sized");  set("attrib2", "brown");
  set("gender", "male");
  set("weapon_name", "hooves");
  set_verbs( ({
    "kick",
}));
  set_verbs2( ({
    "kicks at",
}));
  set_level(4);
}