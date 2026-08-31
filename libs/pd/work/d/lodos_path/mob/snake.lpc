#include <std.h>
inherit MONSTER;
int ran; 
void create() {
 ::create();
   set_name("dark snake");
   set_id(({"black snake", "snake"}));
   set_short("black snake");
   set_long("A long, dark snake, it looks prepared to strike.");
   set_race("black snake");
   set_body_type("snake");
 ran = random(100);
    if (ran < 20) set_level(17); else
    if (ran < 40) set_level(18); else
    if (ran < 60) set_level(19); else
    if (ran < 80) set_level(20); else
    if (ran < 101) set_level(21);
    if (ran < 51) set_gender("female"); else
    if (ran < 101) set_gender("male");
}
