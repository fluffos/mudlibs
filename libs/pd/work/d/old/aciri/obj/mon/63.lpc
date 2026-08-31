#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("warlord");
   set_short("a shadowy warlord");
   set_long("The evil shadow resembles a greedy warlord. The shadow's evil "
     "aura can be felt all through the room. The warlord's long, knife like "
     "fingers point at you, menacingly.");
   set_level(45);
   set_id(({ "shadow", "warlord", "shadowy warlord" }));
   set_auto(5);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(5) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"thunhammer");
   command("wield hammer");
}
