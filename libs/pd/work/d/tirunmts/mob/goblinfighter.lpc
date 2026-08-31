#include <std.h>
inherit MONSTER;
int ran; 

void create() {
 ::create();
   set_name("goblin fighter");
   set_id(({ "fighter", "goblin", "goblin fighter" }));
   set_short("goblin fighter");
 ran = random(100);
    if (ran < 20) set_level(10); else
    if (ran < 40) set_level(11); else
    if (ran < 60) set_level(12); else
    if (ran < 80) set_level(13); else
    if (ran < 101) set_level(14);
   set_long("A short green creature standing about 4 foot tall, the goblin is a warrior among his people.");
   set_body_type("human");
   set_race("goblin");
   set_gender("male");
}
