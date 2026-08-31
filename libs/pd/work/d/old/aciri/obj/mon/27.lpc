#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("neo-orog");
   set_short("an elite Neo-Orog soldier");
   set_long("The Acirian Neo-Orog are much more skilled with weapons, "
     "and require much less training to develope the same skill as a "
     "veteran orcish soldier. This is an elite Neo-Orog soldier, one "
     "of the strongest of the Neo-Orog.");
   set_level(43);
   set_id(({ "neo-orog", "trooper", "orc" }));
   set_auto(8);
   set_race("neo-orog");
   set_body_type("human");
  if (random(6) >= 3)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"hhelm");
   command("wear all");
   make(WEA"scythe");
   command("wield scythe");
  if (random(3) == 2) {
   make(WEA"scythe");
   command("wield scythe");
  }
}
