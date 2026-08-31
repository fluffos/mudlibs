#include <std.h>
inherit MONSTER;
int ran; 

void create() {
    ::create();
   set_name("mountain lion");
   set_id( ({ "mountain lion", "lion" }) );
   set_short("mountain lion");
 ran = random(100);
    if (ran < 20) set_level(17); else
    if (ran < 40) set_level(18); else
    if (ran < 60) set_level(19); else
    if (ran < 80) set_level(20); else
    if (ran < 101) set_level(21);
   set_long("A large furry feline with long claws and sharp teeth");
   set_body_type("feline");
   set_alignment(-100);
   set_race("lion");
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
   set("aggressive", 20);
}
