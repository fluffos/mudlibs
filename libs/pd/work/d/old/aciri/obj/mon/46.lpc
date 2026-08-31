#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("acolyte");
   set_short("an acolyte of the dark");
   set_long("The acolyte of the dark is a follower of evil in it's many forms. "
     "This being of evil was drawn to this tower to wander around, reveling in "
     "it's pure power of evil.");
   set_level(42);
   set_id(({ "acolyte" }));
   set_auto(4);
   set_race("human");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"rknife");
   command("wield knife");
   make(WEA"rknife");
   command("wield knife");
}
