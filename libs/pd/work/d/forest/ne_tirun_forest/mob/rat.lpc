#include <std.h>

inherit MONSTER;
int ran;
void create() {
    ::create();
   set_name("rat");
   set_id( ({ "rat" }) );
    set_short("a rat");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
   set_long("A large rat. It looks unhappy about something.");
   set_body_type("feline");
   set_alignment(-10);
   set("race", "rat");
   set_gender("male");
   set("aggressive", 15);
}
