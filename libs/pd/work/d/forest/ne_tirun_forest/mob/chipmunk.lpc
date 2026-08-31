#include <std.h>

inherit MONSTER;
int ran;
void create() {
    ::create();
    set_name("chipmunk");
    set_id ( ({"chipmunk"}) );
    set_short("a chipmunk");
    set_long("The chipmunk is a small brown furry rodent. They have been known to collect shiney objects.");
    set_gender("male");
 ran = random(100);
    if (ran < 25) set_level(4); else
    if (ran < 50) set_level(5); else
    if (ran < 75) set_level(6); else
    if (ran < 101) set_level(7);
    set_race("chipmunk");
    set_body_type("canine");
    add_money("gold", random(10));
}
