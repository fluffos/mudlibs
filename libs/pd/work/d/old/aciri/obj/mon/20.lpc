#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("an experienced orcish soldier");
   set_long("The orc soldier is experienced from months of training "
     "and careful practice in the tower. The orcs have trouble "
     "following orders, but make generally make good soldiers.");
   set_level(32);
   set_id(({ "soldier", "orc", "orcish soldier" }));
   set_auto(20);
   set_race("orc");
   set_body_type("human");
   set_class("fighter");
   set_spell_chance(10);
   set_spells(({ "whirl" }));
  if (random(10) >= 6)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"osword1");
   command("wield sword");
}
