inherit MONSTER;
void create() {
  seteuid(getuid());
  ::create();
  set("short", "a fishing munchkin");
  enable_commands();
  set("long", @ENDLONG
This little man is just fishin away.  He has no cares in the world.
ENDLONG
  );
  set_name("munchkin");
  set("id", ({
  "munchkin",
  "fishing munchkin"
  }));
  set("damage", ({ 9, 23}) );
  set("armor_class", 7);
  set("attack_strength", 6);
  set("race", "munchkin");
	set("size", 3);
  set("attrib1", "happy");  set("attrib2", "content");
  set("gender", "male");
  set("weapon_name", "fishing pole");
  set_verbs( ({
    "lashes",
}));
  set_verbs2( ({
    "lashes at",
}));
  set_level(6);
}