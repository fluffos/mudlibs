#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("orc");
   set_short("a strong orc");
   set_long("The tall, strong orc wandered off from the Acirian army troops. "
     "The orc is lost and has nowhere to go.");
   set_level(38);
   set_id(({ "orc" }));
   set_auto(0);
   set_race("orc");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"ospear1");
   command("wield spear");
}
