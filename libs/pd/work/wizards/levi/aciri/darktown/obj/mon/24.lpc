#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("commander");
   set_short("a commander");
   set_long("One of the high commanders of the Acirian Army, second "
     "only to the general, the commanders control a large division of "
     "the army stationed within the tower.");
   set_level(42);
   set_id(({ "commander" }));
   set_auto(4);
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
