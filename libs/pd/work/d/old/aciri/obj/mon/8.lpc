#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("an orc soldier");
   set_long("The orc soldiers are a strong breed, much more so than "
     "the goblins. Still not the best of the lower ranked soldiers, "
     "the orcs guard the lower level of the tower. The orc is pretty "
     "slow, but makes up for it with power.");
   set_level(26);
   set_id(({ "orc", "soldier" }));
   set_auto(7);
   set_race("orc");
   set_body_type("human");
  if (random(4) >= 3)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"ssword1");
   command("wield sword");
   make(WEA"ssword1");
   command("wield sword");
}
