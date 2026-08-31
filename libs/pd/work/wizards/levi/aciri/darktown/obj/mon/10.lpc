#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("scout");
   set_short("an Aciri scout");
   set_long("The scout runs around, getting information to relay to "
     "the general and other higher ranks. The scout's thin frame is "
     "not one of a soldier, but of one who's heart is hardened to "
     "death. The scout has seen many horrors in its time.");
   set_level(20);
   set_id(({ "scout" }));
   set_auto(0);
   set_race("imp");
   set_body_type("human");
  if (random(4) >= 3)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"cap");
   command("wear cap");
}
