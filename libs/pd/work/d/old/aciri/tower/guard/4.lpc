#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("giant");
   set_short("a huge giant");
   set_long("The giant is a guardian of this tower, but what strange "
     "twist of fate brings her here? Both of her hands are occupied, "
     "wielding an uprooted tree. The giant is just over thirty-five "
     "feet tall.");
   set_gender("female");
   set_spell_chance(4);
   set_spells(({ "rock" }));
   set_heart_beat(1);
   make(WEA"tree");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wield tree"); oi = 1; }
}
