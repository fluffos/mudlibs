#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("dragoon");
   set_short("an Acirian dragoon");
   set_long("A band of heavily armed troopers, called the dragoons, were "
     "organized to head further into the tower than the part that Aciri owned. "
     "They have become disorganized and split up. Now the dragoons try to fight "
     "their way back down the tower.");
   set_level(40);
   set_id(({ "dragoon" }));
   set_auto(4);
   set_race("human");
   set_body_type("human");
  if (random(3) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"dragoon");
   command("wear all");
}
