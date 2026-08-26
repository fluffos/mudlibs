#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "General Phoscaff");
  enable_commands();
  set("long", @ENDLONG
General Phoscaff is a large, undead ogre.  He wears black and
silver ringmail and carries a rather deadly looking whip at his
side.
ENDLONG
  );
  set_alignment(-80);
  set_name("general Phoscaff");
  set("id", ({
    "general",
    "phoscaff",
  }));
  credit(1000);
  set("damage", ({ 37, 67 }) );
  set("armor_class", 15);
  set("hit_points", 610);
  set("attack_strength", 19);
  set("gender", "male");
		set("undead", 15);
		arm(WEAPONS(sting),"whip");
		wear(ARMOR(ringmail),"ringmail");
  set("race", "undead");
  set("attrib2", "alert");  set("attrib1", "commanding");
  set("weapon_name", "Sting");
  set_verbs( ({
    "slashes at",
    "attempt to cut",
}));
  set_level(15);

}
