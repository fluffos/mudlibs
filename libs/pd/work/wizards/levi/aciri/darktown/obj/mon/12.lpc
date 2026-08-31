#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("javelineer");
   set_short("an armed javelineer");
   set_long("More practical than soldiers in many cases, the "
     "javelineers are stationed just high enough to be able to take "
     "on large masses comming from below. These troops are skilled "
     "with their weapons.");
   set_level(24);
   set_id(({ "javelineer", "armed javelineer" }));
   set_auto(4);
   set_race("half-orc");
   set_body_type("human");
  if (random(3) == 3)
   set_gender("male");
  else
   set_gender("female");
   make(WEA"javelin");
   command("wield javelin");
}
