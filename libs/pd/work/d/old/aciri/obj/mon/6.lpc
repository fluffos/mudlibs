#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("messenger");
   set_short("a goblin messenger");
   set_long("A captured slave used as a messenger, goes running through "
     "the ranks, sending messages from the general and other upper ranks "
     "to the others. The goblin is small and quick, but not much of a "
     "fighter.");
   set_level(19);
   set_id(({ "messenger", "goblin", "goblin messenger" }));
   set_auto(1);
   set_race("goblin");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"lsuit");
   command("wear all");
}
