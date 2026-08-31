#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("slave");
   set_short("an armed orcish slave");
   set_long("An orc of typical build, the slave has been armed and "
     "used as an armed guard in the lower part of the tower, the part "
     "which is being held by the Aciri.");
   set_level(25);
   set_id(({ "slave", "orc", "armed orcish slave", "orcish slave" }));
   set_auto(15);
   set_race("half-orc");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"hammer1");
   command("wield malet");
   make(WEA"hammer2");
   command("wield hammer");
}
