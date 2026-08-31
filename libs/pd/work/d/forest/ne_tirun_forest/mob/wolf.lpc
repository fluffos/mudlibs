#include <std.h>

inherit MONSTER;
int ran;
void create() {
    ::create();
    set_name("wolf");
    set_id ( ({"wolf"}) );
    set_short("a grey wolf");
    set_long("A large canine with a grey coloration to it's fur.");
    set_gender("male");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7); 
    set_race("wolf");
    set_body_type("canine");
}
