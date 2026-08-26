inherit MONSTER;

void create() {
	int y;
	y=(random(3)+2);
  seteuid(getuid());
  ::create();
  set("short", "munchkin");
  enable_commands();
  set("long", @ENDLONG
This little man is about 2 feet tall.  His features are very childlike, 
from his mannerisms to his sheer appearance.  Just by his size,
he would seem to be harmless.
ENDLONG
  );
  set_name("munchkin");
  set("id", ({
    "munchkin",
  }));

	set_alignment(random((-y*y)-y));
  set("damage", ({ y, 3*y }) );
  set("armor_class", y);
  set("attack_strength", y-1);
  set("race", "munchkin");
	set("size", 3);
  set("attrib1", "tiny");  set("attrib2", "humanoid");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punches at",
    "swings wildly at",

}));
  set_verbs2( ({
    "punches at",
    "swings at",

}));
  set_level(y);

  set("forgetful", 1);

}
