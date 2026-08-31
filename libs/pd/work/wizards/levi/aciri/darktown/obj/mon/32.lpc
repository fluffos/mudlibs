#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("fiend");
   set_short("a deathly fiend");
   set_long("The fiend has long, wicked tenticals leading back from its head "
     "tipped with poisonous stingers. Its teeth are long and razor sharp. At the "
     "end of long fingers are sharp metallic claws. The fiend has an aura of "
     "death about it.");
   set_level(41);
   set_id(({ "fiend", "deathly fiend" }));
   set_auto(10);
   set_race("fiend");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
}
