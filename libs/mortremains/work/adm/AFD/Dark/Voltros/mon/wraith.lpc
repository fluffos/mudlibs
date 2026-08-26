#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "large wraith");
  enable_commands();
  set("long", @ENDLONG
This is a large, dark creature.  It's neon-green orbs stare back at you
through it's misty form.  Darkness convelesses around it, sucking any
light in the room towards it.
ENDLONG
  );
        set("aggressive", 1);
  set_alignment(-100);
  set_name("Wraith");
  set("id", ({
    "wraith",
    "Wraith",
  }));
  credit(350);
		set("undead", 11);
  set("damage", ({ 10, 60 }) );
  set("hit_points", 130);;
  set("race", "wraith");
  set("attrib1", "floating");  set("attrib2", "misty");
  set("weapon_name", "claws");
  set_verbs( ({
    "rake",
    "gouge",
}));
  set_skill("defense", 11, "dexterity");
  set_skill("attack", 11, "strength");
  set_level(15);

}