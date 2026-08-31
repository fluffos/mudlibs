#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("spirit");
   set_short("raging spirit");
   set_long("A spirit of someone who was slain in this very tower. The dead's "
     "spirit was brought back from it's maddened fury. The spirit, much like "
     "almost everything else here hates all life and seeks to destroy it.");
   set_level(44);
   set_id(({ "spirit", "raging spirit" }));
   set_auto(20);
   set_race("spirit");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"spirit");
   command("wear all");
}
