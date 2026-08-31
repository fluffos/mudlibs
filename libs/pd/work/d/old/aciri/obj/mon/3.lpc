#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("knight");
   set_short("an armoured knight");
   set_long("The knight is armoured head to foot. Part of a massive "
     "force in the tower, the knight stands at guard. Both hands on "
     "a long pike, ready for battle.");
   set_level(25);
   set_id(({ "knight", "armoured knight" }));
   set_auto(3);
   set_race("human");
   set_body_type("human");
  if (random(4) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"khelm");
   make(ARM"kplate");
   make(WEA"kpike");
   command("wear all");
   command("wield pike");
}
