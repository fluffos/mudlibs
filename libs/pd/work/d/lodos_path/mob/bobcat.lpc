#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("bobcat");
   set_id( ({ "bobcat" }) );
   set_short("bobcat");
 ran = random(100);
    if (ran < 20) set_level(14); else
    if (ran < 40) set_level(15); else
    if (ran < 60) set_level(16); else
    if (ran < 80) set_level(17); else
    if (ran < 101) set_level(18);
   set_long("A medium sized feline with long teeth, brown fur, and sharp claws.");
   set_body_type("feline");
   set_alignment(-100);
   set_race("bobcat");
   set_gender("male");
   set("aggressive", 16);
}
