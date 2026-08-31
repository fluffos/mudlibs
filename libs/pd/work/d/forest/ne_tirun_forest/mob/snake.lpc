#include <std.h>

inherit MONSTER;
int ran;
void create() {
::create();
    set_name("snake");
    set_short("a snake");
    set_long("The snake is medium sized, color with brown and black markings.");
    set_id(({"snake"}));
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
    set_race("snake");
    set_body_type("snake");


}