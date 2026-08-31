#include <std.h>
#include <aciri.h>
inherit MONSTER;

int oi=0;

void create() {
 ::create();
   set_name("ashlynn");
   set_short("Ashlynn, the aeromistress");
   set_long("Ashlynn was a well known and powerful aeromancer before "
     "she left her home in search of the secret of the tower in "
     "Aciri. Knowing her power was not enough to advance past this "
     "point, Ashlynn stopped here to train. Afraid someone else would "
     "claim the legendary power, she will not allow any to pass her. "
     "Ashlynn, the aeromistress is the seventh guardian of the tower "
     "of every evil.");
   set_level(57);
   set_race("human");
   set_body_type("human");
   set_gender("female");
   set_auto(0);
   set_spell_chance(13);
   set_skill("healing", 150);
   set_skill("faith", 150);
   set_spells(({ "point wand" }));
   set_properties(([ "no bump" : 1 ]));
   set_heart_beat(1);
   make(WEA"wand");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wield wand"); oi = 1; }
}

int stop_up() {
   write("Ashlynn summons a quick wind to blow you to the ground.");
   return 1;
}

void init() {
 ::init();
   add_action("stop_up", "up");
}
