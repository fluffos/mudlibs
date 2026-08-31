#include <std.h>

inherit MONSTER;
int ran;
void create() {
 ::create();
   set_name("deer");
   set_id(({"deer"}));
   set_short("a small deer");
   set_long("A small dear with brown fur and w hite tail.");
   set_gender("female");
   set_race("deer");
   set_body_type("equine");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
}
