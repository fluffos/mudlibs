#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("bear");
   set_id( ({ "bear" "black bear" }) );
   set_short("black bear");
 ran = random(100);
    if (ran < 20) set_level(18); else
    if (ran < 40) set_level(19); else
    if (ran < 60) set_level(20); else
    if (ran < 80) set_level(21); else
    if (ran < 101) set_level(22);
   set_long("A large black beast standing around 5 foot tall, this creature is furry, clawed, and looks angry.");
   set_body_type("feline");
   set_alignment(0);
   set_race("bear");
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
   set("aggressive", 20);
}
