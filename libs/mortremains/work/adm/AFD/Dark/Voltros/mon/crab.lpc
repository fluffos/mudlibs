inherit MONSTER;
void create() {
  seteuid(getuid());
  ::create();
  set("short", "a crab");
  enable_commands();
  set("long", @ENDLONG
This is a blue crab.  The munchkins catch them
to sell.
ENDLONG
  );
  set_name("crab");
  set("id", ({
  "crab",
  }));
  set("damage", ({ 1, 5 }) );
  set("armor_class", 1);
  set("attack_strength", 1);
  set("race", "crab");
	set("size", 1);
  set("attrib1", "tiny");  set("attrib2", "blue");
  set("gender", "neuter");
  set("weapon_name", "pincers");
  set_verbs( ({
    "attempt to clamp",
    "pinch",

}));
  set_level(1);
  set("forgetful", 1);

}
