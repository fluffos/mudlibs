#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("shadow");
   set_short("a shadow lancer");
   set_long("One of the many beings of shadow, trapped halfway between this "
     "world and their own. The shadow absorbs much of the room's light. The "
     "lancer wields a lance of lightning.");
   set_level(44);
   set_id(({ "shadow", "shadow lancer" }));
   set_auto(6);
   set_class("fighter");
   set_race("shadow");
   set_body_type("human");
  if (random(4) >= 2)
   set_gender("female");
  else
   set_gender("male");
   make(WEA"lightning");
   command("wield lance");
}
