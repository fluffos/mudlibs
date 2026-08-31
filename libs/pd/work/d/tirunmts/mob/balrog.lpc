#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("balrog");
   set_id( ({ "balrog" }) );
   set_short("balrog");
 ran = random(100);
    if (ran < 20) set_level(12); else
    if (ran < 40) set_level(13); else
    if (ran < 60) set_level(14); else
    if (ran < 80) set_level(15); else
    if (ran < 101) set_level(16);
   set_long("A monster of the mountains, the balrog's form is engulfed in flame. Standing over 8 foot tall, this creature is horned, winged, and is evil incarnate.");
   set_body_type("demon");
   set_alignment(-100);
   set_race("balrog");
   set_gender("male");
   set("aggressive", 20);
}
