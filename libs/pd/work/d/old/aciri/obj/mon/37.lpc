#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("shade");
   set_short("a vengeful shade");
   set_long("A rotting image of it's former life, the shade wanders the tower "
     "in dispair. Hating all living things, the shade will try its hardest to "
     "claim that which it can not have, namely life.");
   set_level(41);
   set_id(({ "shade" }));
   set_auto(900);
   set_race("shade");
   set_body_type("human");
  if (random(6) >= 3)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"grave");
   command("wear all");
}
