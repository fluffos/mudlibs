#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "heretic");
  enable_commands();
  set("long", @ENDLONG
A rather short person wrapped in the robes of his
religon.  He has a smile on his face as he looks 
at you.
ENDLONG
  );
  set_name("heretic");
  set("id", ({
    "heretic",
    "human",
  }));
	set_alignment(100);
  arm(WEAPONS(gstick), "stick");
  credit(180);
  set("weapon_name", "gnarled stick");
		wear(ARMOR(white_robes), "robes");
  set("damage", ({10, 15 }) );
  set("armor_class", 7);
  set("attack_strength", 6);
  set("race", "human");
  set("attrib1", "small");  set("attrib2", "smiling");
  set("gender", "male");
		set_level(7);
	command("wear all");
  set_verbs( ({
    "tap",
    "thrust",

}));
  set_verbs2( ({
    "taps",
    "thusts",

}));
set("chat_chance", 4);
   set("chat_output", ({
        "The heretic says, 'Mayas will save you, if you believe!'\n",
							 "The heretic says, 'Come sit by the fire with me and listen to the miracles of Mayas.'\n",
							 "The heretic asks you, 'Have you been saved by Mayas, the Life-Saver?'\n"
}));
}