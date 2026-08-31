#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("ogre");
   set_short("ogre");
   set_long("The tall, strong ogre looks very worried at your "
     "presence here, and inches towards you, expecting a fight.");
   set_level(28);
   set_id(({ "ogre" }));
   set_auto(12);
   set_race("ogre");
   set_body_type("human");
  if (random(2) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(ARM"loin");
   command("wear all");
}
