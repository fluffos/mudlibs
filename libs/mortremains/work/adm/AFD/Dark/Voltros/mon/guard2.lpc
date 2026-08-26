inherit MONSTER;
#include "../defs.h"
void create() {
  seteuid(getuid());
  ::create();
  set("short", "mayor's guard");
  enable_commands();
  set("long", @ENDLONG
This munchkin is one of the largest munchkins you have
 ever seen.  His well defined muscles ripple under his shirt.  
This does not look like a person you wanna mess with.
ENDLONG
  );
  set_name("guard");
  set("id", ({
    "guard_2",
     "guard",
  }));
  arm(WEAPONS(sling), "sling");
  credit(80 );
  wear( ARMOR(shirt), "guard's shirt");
  set("weapon_name", "sling");
  set("damage", ({ 5, 10 }) );
  set("armor_class", 5);
	set("size", 3);
  set("attack_strength", 3);
  set("race", "munchkin");
	set("size", 3);
  set("attrib1", "small");  set("attrib2", "stout");
  set("gender", "male");
  set("weapon_name", "sling");
	command("wear all");
  set_verbs( ({
    "poke",
    "thrust",

}));
  set_verbs2( ({
    "pokes",
    "thusts",

}));
  set_level(3);
                set("chat_chance", 3);
   set("chat_output", ({
                "The guard stares at you intently.\n",


  }) );
  set("forgetful", 1);

}