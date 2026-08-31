#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("mauler");
   set_short("a shadow mauler");
   set_long("The shadow hides back, where none would notice and waits for "
     "to come by. The shadow mauls it's prey from behind.");
   set_level(45);
   set_id(({ "shadow", "mauler", "shadow mauler" }));
   set_auto(13);
   set_class("fighter");
   set_spells(({ "maul" });
   set_spell_chance(35);
   set_race("shadow");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"shstaff");
   command("wield staff");
}
