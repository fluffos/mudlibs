#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Frank");
  enable_commands();
  set("long", @ENDLONG
This is Frank.  Frank is a 7ft. tall human.  Frank is not happy.  
Frank wants you to try somthing.
ENDLONG
  );
  set_name("frank");
  set("id", ({
    "frank",
    "Frank",
    "human",
  }));
	set_alignment(-10);
  arm(WEAPONS(lallai), "dagger");
  credit(380 );
  set("weapon_name", "dagger");
  wear( ARMOR(bshield), "shield");
  set("damage", ({10, 15 }) );
  set("armor_class", 7);
  set("attack_strength", 5);
  set("race", "human");
  set("attrib1", "large");  set("attrib2", "menacing");
  set("gender", "male");
	command("wear all");
  set_verbs( ({
    "poke",
    "thrust",

}));
  set_verbs2( ({
    "pokes",
    "thusts",

}));
  set_level(6);
  set("forgetful", 1);

}
