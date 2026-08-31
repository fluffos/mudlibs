#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("warrior");
   set_short("an orcish warrior");
   set_long("The orcish warrior must not be a pure blooded orc, for "
     "the warriors size and strength resemble more that of a giant. "
     "One of the most powerful troops in the Aciri army, the warriors "
     "stand ready to fight.");
   set_level(40);
   set_id(({ "warrior", "orc", "orcish warrior" }));
   set_auto(24);
   set_race("orc");
   set_body_type("human");
  if (random(7) >= 5)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"osword3");
   command("wield sword");
   make(WEA"osword3");
   command("wield sword");
}
