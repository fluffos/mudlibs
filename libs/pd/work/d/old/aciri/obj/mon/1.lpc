#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("orc");
   set_short("an orc");
   set_long("An ugly orc stands here, sulking around. The orc doesn't "
     "seem to remember why it's here. This orc smells horrible.");
   set_level(20);
   set_id(({ "orc" }));
   set_auto(5);
   set_race("orc");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("male");
  else
   set_gender("female");
   make(WEA"osword1");
   command("wield sword");
}
