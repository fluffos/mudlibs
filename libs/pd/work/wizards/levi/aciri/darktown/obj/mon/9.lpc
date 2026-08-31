#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("a troll soldier");
   set_long("The troll soldiers are the true strength of the lower "
     "rank soldiers of the Acirian Army. They are pretty quick and "
     "fierce. The trolls fight with a maddened fury that the orcs and "
     "goblins could never produce.");
   set_level(31);
   set_id(({ "soldier", "troll", "troll soldier" }));
   set_auto(8);
   set_race("troll");
   set_body_type("human");
  if (random(4) == 3)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"ssword1");
   command("wield sword");
   make(WEA"ssword1");
   command("wield sword");
   make(ARM"lvest");
   command("wear all");
}
