#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "stupid zombie");
  enable_commands();
  set("long", @ENDLONG
   This zombie moves around with no real purpose.  His face is contorted
in an expression of anger, rage, and bloodthirst.  His jaw hangs open and
low, barely-audible moan can be heard.
ENDLONG
  );
  set_alignment(-80);
  set_name("zombie");
  set("id", ({
    "zombie",
  }));
  credit(150);
  set("damage", ({ 5, 25 }) );
		set("killer", 1);
  set("hit_points", 140);
		set("undead", 5);
  set("race", "zombie");
  set("attrib1", "sluggish");  set("attrib2", "man-sized");
  set("weapon_name", "claws");
  set_verbs( ({
    "scratch at",
    "gouge",
}));
  set_skill("defense", 9, "dexterity");
  set_skill("attack", 13, "strength");
  set_level(11);

}

