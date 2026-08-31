#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("footsoldier");
   set_short("an orc footsoldier");
   set_long("The orc is one of the lower ranks of the Acirian Army. "
     "The footsoldiers guard the lower levels of the the tower. They "
     "are the first in line, the first to die, and very aggressive.");
   set_level(21);
   set_id(({ "footsoldier", "soldier", "orc" }));
   set_auto(19);
   set_race("orc");
   set_body_type("human");
  if (random(2) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"loin");
   command("wear all");
   make(WEA"osword1");
   command("wield sword");
}
