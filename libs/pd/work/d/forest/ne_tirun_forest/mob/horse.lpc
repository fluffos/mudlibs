#include <std.h>


inherit MOUNT;
int ran;
void create() {
::create();
set_name("horse");
set_short("a large white horse");
set_long("The horse is very broad, looks like a great mount.");
set_gender("male");
set("race", "horse");
set_body_type("equine");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
}
