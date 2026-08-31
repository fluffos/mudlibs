#include <std.h>

inherit MONSTER;
int ran;
void create() {
::create();
set_name("wolf");
set_short("a small wolf");
set_long("This small grey wolf looks to be very young.");
set_gender("male");
set_id(({ "wolf" }));
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
set("race", "wolf");
set_body_type("canine");

}

