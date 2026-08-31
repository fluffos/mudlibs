#include <std.h>
inherit MONSTER;
int ran; 

void create() {
 ::create();
   set_name("badger");
   set_id(({ "badger" }));
   set_short("badger");
 ran = random(100);
    if (ran < 20) set_level(12); else
    if (ran < 40) set_level(13); else
    if (ran < 60) set_level(14); else
    if (ran < 80) set_level(15); else
    if (ran < 101) set_level(16);
    set_long("A short brown furry creature standing about 2 foot tall with long claws and sharp teeth.");
    set_body_type("canine");
    set_race("badger");
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
