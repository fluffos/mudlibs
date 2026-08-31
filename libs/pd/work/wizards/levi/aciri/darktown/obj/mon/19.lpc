#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("trooper");
   set_short("a hobgoblin storm trooper");
   set_long("The hobgoblin has been trained under the roughest Aciri "
     "training programs. The hobgoblin's muscles are about the size "
     "of your head. The storm troops have been trained in hand to "
     "hand combat.");
   set_level(35);
   set_id(({ "trooper", "storm trooper", "hobgoblin" }));
   set_auto(20);
   set_race("hobgoblin");
   set_body_type("human");
   set_stats("strength", 85);
   set_class("fighter");
   set_spell_chance(20);
   set_spells(({ "choke" }));
  if (random(10) >= 7)
   set_gender("female");
  else
   set_gender("male");
}
