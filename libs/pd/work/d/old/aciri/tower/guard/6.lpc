#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("ned");
   set_short("Ned, the Dark");
   set_long("The dark monk, Ned, wandered into this tower in search "
     "of power. His faith was not enough to pass this very point. In "
     "a fury, he vowed not to let anyone pass the point he could not, "
     "thus Ned is the sixth guardian of the tower.");
   set_level(55);
   set_race("human");
   set_body_type("human");
   set_gender("male");
   set_auto(25);
   set_properties(([ "no bump" : 1 ]));
//   set_heart_beat(1);
   set_spell_chance(25);
   set_class("kataan");
   set("alignment", -500);
   set_skill("healing", 150);
   set_skill("faith", 150);
   set_spells(({ "demonfire", "hellfire" }));
}
/*
void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wear robes"); oi = 1; }
}*/

int stop_up() {
   write("Ned shoves you to the ground and threatens you.");
   return 1;
}

void init() {
 ::init();
   add_action("stop_up", "up");
}
