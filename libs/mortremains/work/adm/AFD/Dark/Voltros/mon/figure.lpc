#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Eerie figure");
  enable_commands();
  set("long", @ENDLONG
The dark, ominous figure that looms over you seems to control a vast
ammount of power.  He radiates a dark-black aura.  His face can barely
be seen through his cloud of hatred.  A faint gleam can be seen where
his face should be.
ENDLONG
  );
  set_alignment(-180);
  set_name("figure");
  set("id", ({
    "figure",
  }));
  credit(1150);
  set("damage", ({ 25, 55 }) );
  set_level(19);
  set("monster_ac", 19);
  set("monster_wc", 19);
		set("undead", 20);
  set("race", "undead");
  set("attrib1", "tall");  set("attrib2", "dark");
  set("weapon_name", "staff"); 
  arm(WEAPONS(dstaff),"staff");
		wield_weapon("staff");
  set_verbs( ({
    "pummel",
    "strike",
    "pound",
}));
set_skill("Blunt weapons", 250, "agility");
}