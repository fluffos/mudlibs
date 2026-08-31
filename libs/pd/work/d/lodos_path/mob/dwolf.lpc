#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("dire wolf");
   set_id( ({ "dire wolf", "wolf" }) );
   set_short("dire wolf");
 ran = random(100);
    if (ran < 20) set_level(20); else
    if (ran < 40) set_level(21); else
    if (ran < 60) set_level(22); else
    if (ran < 80) set_level(23); else
    if (ran < 101) set_level(24);
   set_long("A great hulking beast, this wolf stands over 5 foot tall, is covered with black fur, and is foaming madly from the mouth.");
   set_body_type("canine");
   set_alignment(-1000);
   set_race("dire wolf");
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
   set("aggressive", 30);
}
