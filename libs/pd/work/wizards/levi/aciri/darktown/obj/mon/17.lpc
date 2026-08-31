#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("trooper");
   set_short("goblin shock trooper");
   set_long("The goblin shock troops have been stationed around here. "
     "The shock troops were formed by giving slaves their freedom if "
     "they joined the shock troops. Once the Aciri harness the power "
     "of the tower, the shcok troopers will be released.");
   set_level(24);
   set_id(({ "goblin", "trooper", "shock trooper", "goblin shock trooper" }));
   set_auto(9);
   set_race("goblin");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"club");
   command("wield club");
}
