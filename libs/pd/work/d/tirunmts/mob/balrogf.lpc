#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("balrog");
   set_id( ({ "balrog" }) );
   set_short("balrog");
 ran = random(100);
    if (ran < 20) set_level(10); else
    if (ran < 40) set_level(11); else
    if (ran < 60) set_level(12); else
    if (ran < 80) set_level(13); else
    if (ran < 101) set_level(14);
   set_long("A female balrog, her form is engulfed in flame. Standing over 7 foot tall, this creature is horned, winged, and is evil incarnate.");
   set_body_type("demon");
   set_alignment(-100);
   set_race("balrog");
   set_gender("female");
   set("aggressive", 20);
}
