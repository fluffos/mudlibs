#include <std.h>

inherit MONSTER;
int ran;
void create() {
    ::create();
    set_name("wildcat");
    set_id ( ({"wildcat"}) );
    set_short("a small wildcat");
    set_long("A medium sized feline of tan colration.");
    set_gender("female");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
    set_race("wildcat");
    set_body_type("feline");
}
