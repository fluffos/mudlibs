#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("an elite goblin warrior");
   set_long("The goblin elite warriors are grouped with some of the "
     "leser soldiers and troops, mainly because the goblins can never "
     "have the same brute force of many of the other races. The "
     "elites keep the others in line.");
   set_level(27);
   set_id(({ "goblin", "elite warrior", "elite goblin warrior",
             "warrior" }));
   set_auto(8);
   set_race("goblin");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"whip1");
   command("wield whip");
}
