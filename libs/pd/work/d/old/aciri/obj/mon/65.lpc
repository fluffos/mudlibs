#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("shadow");
   set_short("a twisted shadow");
   set_long("The shadow's form is twisted and contorted in a mockery of agony "
     "and pain. The shadow looks like it was at first two shadows that somehow "
     "halfway merged and turned solid.");
   set_level(44);
   set_id(({ "shadow", "twisted shadow" }));
   set_auto(7);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"eveningstar");
   command("wield star");
}
