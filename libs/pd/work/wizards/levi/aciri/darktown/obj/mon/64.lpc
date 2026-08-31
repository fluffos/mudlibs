#include <std.h>
#include <aciri.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("soldier");
   set_short("a shadow soldier");
   set_long("The soldier is of a strange and magical race that resemble "
     "solidified shadows. It's skin is a pure black and glossy. The soldier "
     "easily moves, unnoticed in the shadows.");
   set_level(46);
   set_id(({ "shadow", "soldier", "shadow soldier" }));
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
