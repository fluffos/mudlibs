#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("archer");
   set_short("an archer");
   set_long("The archer knows many of the ancient arts of magical archery that "
     "were lost when the world was young. The archer's spirit resides in the "
     "tower.");
   set_level(41);
   set_id(({ "archer" }));
   set_auto(0);
   set_race("spirit");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"mbow");
   command("wield bow");
}
