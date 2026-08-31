#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("a goblin soldier");
   set_long("The goblin soldiers have a great agility and speed over "
     "many of the other soldiers, but are not as strong or have the "
     "same control of arms as some of the other races under the control "
     "of the Acirian Army.");
   set_level(24);
   set_id(({ "soldier", "goblin" }));
   set_auto(7);
   set_race("goblin");
   set_body_type("human");
  if (random(3) == 3)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"ssword1");
   command("wield sword");
}
