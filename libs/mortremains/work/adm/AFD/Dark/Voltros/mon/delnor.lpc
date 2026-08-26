#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Darklord Delnor");
  enable_commands();
  set("long", @ENDLONG
Darklord Delnor is a very commanding fellow.  He says
little, and what he does say, is followed exactly.  He
leaves no margin for error.  To fail while under his
command means death.
ENDLONG
  );
  set_alignment(-120);
  set_name("darklord Delnor");
  set("id", ({
    "delnor",
    "darklord",
  }));
  credit(1000);
  set("damage", ({ 27, 67 }) );
  set("armor_class", 15);
  set("attack_strength", 19);
  set("gender", "male");
		set("undead", 19);
		arm(WEAPONS(nightbringer),"mace");
		wear(ARMOR(bplate),"platemail");
  set("race", "undead");
  set("attrib2", "grim");  
  set("attrib1", "ruthless");
  set("weapon_name", "Nightbringer");
  set_verbs( ({
    "cut",
    "rip",
}));
  set_level(17);

}
