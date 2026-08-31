#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("a Neo-Orog soldier");
   set_long("Some of the lesser skilled Neo-Orogs, who have recieved "
     "less vigorous training wield orcish blades and battle along "
     "side of their orcish brethren.");
   set_level(38);
   set_id(({ "neo-orog", "soldier", "orc" }));
   set_auto(4);
   set_race("neo-orog");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"osword1");
   command("wield sword");
   make(WEA"osword2");
   command("wield sword");
}
